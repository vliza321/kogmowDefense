#include "Player.h"
#include "algorithm"
#include "ObjectClass.h"
#include "Canvas.h"

Player::Player()
	: Component()
{

}

Player::~Player()
{

}

bool Player::InitializeSet()
{
	m_moveLeftRight = 0;
	m_moveBackForward = 0;
	speed = 0.0033f;
	PoVTimer = POVMAXTIMER;
	canChangePov = true;
	m_currentShootType = ShootType::TPC;


	ReboundTimer = 0;
	isRebound = false;
	ReBoundConst = 0;
	canFire = false;
	return true;
}

bool Player::Initialize()
{
	
	return true;
}

bool Player::InitializeRef()
{
	transform = this->gameObject->GetComponentIncludingBase<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}
	m_cameraManager = gameObject->Root().Find("CameraManager")->GetComponentIncludingBase<CameraManager>();
	m_uiCanvas = gameObject->Root().Find("Canvas")->GetComponentIncludingBase<Canvas>();
	m_bulletManager = gameObject->GetComponentIncludingBase<BulletManager>();
	return true;
}

bool Player::InitializeSynchronization()
{
	SetPov(ShootType::TPC);
	return true;
}

bool Player::PostInitialize()
{
	return true;
}

void Player::FixedExecute()
{
	ChangePovCul();

	if (!m_moveBackForward && !m_moveLeftRight || (m_currentShootType == ShootType::Artillery)) return;

	auto tf = transform.lock();

	XMMATRIX RotationMatrix;
	XMVECTOR MoveVector = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Right = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Forward = XMVectorSet(0, 0, 0, 0);
	XMFLOAT3 temt = XMFLOAT3(0,0,0);

	RotationMatrix = XMMatrixRotationY(tf->eulerRotation.y);

	Right = XMVector3TransformCoord(tf->DefaultRight, RotationMatrix);
	Forward = XMVector3TransformCoord(tf->DefaultForward, RotationMatrix);

	if (!XMVector3IsNaN(MoveVector) && !XMVector3IsNaN(Right))
	{
		MoveVector += m_moveLeftRight * Right;
	}
	if (!XMVector3IsNaN(MoveVector) && !XMVector3IsNaN(Forward))
	{
		MoveVector += m_moveBackForward * Forward;
	}

	MoveVector = XMVector3Normalize(MoveVector);

	temt.x = XMVectorGetX(MoveVector) * speed * GetDeltaTime();
	temt.y = XMVectorGetY(MoveVector) * speed * GetDeltaTime();
	temt.z = XMVectorGetZ(MoveVector) * speed * GetDeltaTime();

	tf->Translate(temt);
	m_moveBackForward = 0;
	m_moveLeftRight = 0;
}

void Player::Execute() 
{
	auto tf = transform.lock();
	auto& input = InputClass::GetInstance();
	auto cm = m_cameraManager.lock();

	if (InputClass::GetInstance().IsKey(DIK_W))
	{
		m_moveBackForward = 1;
	}
	if (InputClass::GetInstance().IsKey(DIK_S))
	{
		m_moveBackForward = -1;
	}
	if (InputClass::GetInstance().IsKey(DIK_A))
	{
		m_moveLeftRight = -1;
	}
	if (InputClass::GetInstance().IsKey(DIK_D))
	{
		m_moveLeftRight = 1;
	}
	if ((input.GetCurrMouseState().lX != input.GetLastMouseState().lX) || (input.GetCurrMouseState().lY != input.GetLastMouseState().lY))
	{
		tf->eulerRotation.x += input.GetCurrMouseState().lY * 0.001f;
		tf->eulerRotation.y += input.GetCurrMouseState().lX * 0.001f;
		tf->eulerRotation.x = max(-XM_PI * 0.4999f, min(XM_PI * 0.2999f, tf->eulerRotation.x));
	}
	if (input.GetCurrMouseState().rgbButtons[0] && canFire)
	{
		Shoot(cm->GetLookAt(), cm->GetCamera()->GetPosition(), tf->position, tf->eulerRotation);
	}
	
	if (isRebound)
	{
		ReboundCul();
	}

	if (!canFire)
	{
		AutomaticFeeding();
	}

	if (canChangePov)
	{
		if (input.IsKeyDown(DIK_B))
		{
			SetPov(ShootType::Debug);
		}
		if (input.IsKeyDown(DIK_V))
		{
			if (m_currentShootType != ShootType::TPC)
			{
				SetPov(ShootType::TPC);
			}
			else
			{
				SetPov(ShootType::FPC);
			}
		}

		if (input.GetCurrMouseState().rgbButtons[1])//마우스 우클릭
		{
			if (m_currentShootType != ShootType::Scope)
			{
				SetPov(ShootType::Scope);
			}
			else
			{
				SetPov(ShootType::TPC);
			}
		}
		if (input.IsKey(DIK_Q))
		{
			if (m_currentShootType != ShootType::Artillery)
			{
				SetPov(ShootType::Artillery);
				SetArtilleryMod(*tf);
			}
			else
			{
				SetPov(ShootType::TPC);
				SetArtilleryMod(*tf);
			}
		}
	}
}

void Player::LateExecute()
{
}

void Player::PostExecute()
{
}

bool Player::Shutdown()
{
	return true;
}

void Player::ChangePovCul()
{
	if (!canChangePov) PoVTimer -= GetDeltaTime();
	(PoVTimer < 0) ? canChangePov = true : canChangePov = false;
}

void Player::SetPov(ShootType shootType)
{
	auto cm = m_cameraManager.lock();
	auto UIC = m_uiCanvas.lock();

	cm->SetCamera(shootType);

	m_currentShootType = shootType;

	this->canChangePov = false;
	this->PoVTimer = POVMAXTIMER;

	if (UIC != nullptr)
	{
		UIC->SetType(shootType);
	}
}

void Player::SetArtilleryMod(Transform& transform)
{
	if (m_currentShootType == ShootType::Artillery)
	{
		ArtilleryTemt = transform.eulerRotation.x;
		transform.eulerRotation.x = -XM_PI * 0.299f;
	}
	else
	{
		transform.eulerRotation.x = ArtilleryTemt;
	}
}

ShootType* Player::GetShootType()
{
	return &m_currentShootType;
}

void Player::AutomaticFeeding()
{
	FeedingTimer -= GetDeltaTime();

	if (FeedingTimer < 0.0f)
	{
		canFire = true;
	}
}

void Player::ReboundCul()
{
	auto tf = transform.lock();

	ReboundTimer += GetDeltaTime();
	switch (m_currentShootType)
	{
	case ShootType::Title:
		break;
	case ShootType::FPC:
		tf->eulerRotation.y += (double)((ReBoundConst % 160) - 80) * 0.0000174533 * GetDeltaTime();
		tf->eulerRotation.x -= (double)((ReBoundConst % 30) + 30) * 0.0000174533 * GetDeltaTime();
		break;
	case ShootType::TPC:
		tf->eulerRotation.y += (double)((ReBoundConst % 160) - 80) * 0.0000174533 * GetDeltaTime();
		tf->eulerRotation.x -= (double)((ReBoundConst % 30) + 30) * 0.0000174533 * GetDeltaTime();
		break;
	case ShootType::Scope:
		tf->eulerRotation.y += (double)((ReBoundConst % 100) - 50) * 0.00000174533 * GetDeltaTime();
		tf->eulerRotation.x -= (double)((ReBoundConst % 50) + 150) * 0.0000174533 * GetDeltaTime();
		break;
	case ShootType::Artillery:
		break;
	case ShootType::Num:
		break;
	}

	if (ReboundTimer > 60.0f)
	{
		isRebound = false;
		ReboundTimer = 0;
		ReBoundConst = 0;
	}
}

void Player::Shoot(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	auto bm = m_bulletManager.lock();
	bm->ShootBullet(CameraLookAt, CameraPosition, PlayerPosition, PlayerEulerRotation);
	isRebound = true;
	ReboundTimer = 0;
	ReBoundConst = rand();


	canFire = false;
	switch (m_currentShootType)
	{
	case ShootType::Title:
		break;
	case ShootType::FPC:
		FeedingTimer = 280.0f;
		break;
	case ShootType::TPC:
		FeedingTimer = 280.0f;
		break;
	case ShootType::Scope:
		FeedingTimer = 1000.0f;
		break;
	case ShootType::Artillery:
		FeedingTimer = 5600.0f;
		break;
	case ShootType::Num:
		break;
	}
}