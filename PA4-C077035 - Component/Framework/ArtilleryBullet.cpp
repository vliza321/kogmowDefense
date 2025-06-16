#include "ArtilleryBullet.h"
#include "algorithm"
#include "ObjectClass.h"
#include "GameObject.h"

ArtilleryBullet::ArtilleryBullet()
	: BaseBullet(ShootType::Artillery)
{
	m_moveUp = true;
}

ArtilleryBullet::~ArtilleryBullet()
{

}

bool ArtilleryBullet::InitializeSet()
{
	active = false;
	speed = 0.01f;
	return true;
}

bool ArtilleryBullet::Initialize()
{
	return true;
}

bool ArtilleryBullet::InitializeRef()
{
	transform = this->gameObject->GetComponentIncludingBase<Transform>();

	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}

	targetTransform = this->gameObject->root->FindObjectWithTag(Tag::Player)->GetComponentIncludingBase<Transform>();
	return true;
}

bool ArtilleryBullet::InitializeSynchronization()
{
	return true;
}

bool ArtilleryBullet::PostInitialize()
{
	return true;
}

void ArtilleryBullet::FixedExecute()
{
	auto tf = transform.lock();
	if (m_moveUp)
	{
		// 중력 + 장약으로 인한 변위
		XMFLOAT3 tv = { 0.0f, speed * GetDeltaTime() * 4, 0 };

		tf->Translate(tv);

		if (tf->position.y > 20)
		{
			timer = 0;
			m_moveUp = false;
			tf->eulerRotation.x = XM_PI * 0.499f;

			tf->position = temt;
			tf->position.y = 20;
		}
	}
	else
	{
		// 중력 + 장약으로 인한 변위
		XMFLOAT3 tv = { 0.0f, -0.0000980f * timer - speed * GetDeltaTime(), 0 };

		// 실질적 좌표 이동
		tf->Translate(tv);

		if (tf->position.y < -5)
		{
			active = false;
			this->gameObject->active = false;
		}
	}

	timer += GetDeltaTime();
}

void ArtilleryBullet::Execute()
{
	
}

void ArtilleryBullet::LateExecute()
{
}

void ArtilleryBullet::PostExecute()
{
}

void ArtilleryBullet::OnCollisionEnter(Collider* other)
{
	active = false;
	this->gameObject->active = false;
}

void ArtilleryBullet::OnCollisionStay(Collider* other)
{

}

void ArtilleryBullet::OnCollisionExit(Collider* other)
{
}


void ArtilleryBullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	auto tf = transform.lock();

	temt = CameraPosition;

	tf->position = PlayerPosition;
	tf->position.y += 0.70f;
	tf->eulerRotation.x = -XM_PI * 0.499f;

	m_moveVector = XMLoadFloat3(&temt);
	m_moveVector = XMVector3Normalize(m_moveVector);
	
	active = true;
	this->gameObject->active = true;
	
	m_moveUp = true;
	
	timer = 0;
}

bool ArtilleryBullet::Shutdown()
{
	return true;
}

void ArtilleryBullet::OnEnable()
{

}

void ArtilleryBullet::OnDisable()
{
}

/*

void ArtilleryBullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	temt = CameraPosition;

	SetPosition(PlayerPosition.x, PlayerPosition.y + 0.70f, PlayerPosition.z);
	//SetEulerRotation(PlayerEulerRotation);
	transform.eulerRotation.x = -XM_PI * 0.499f;

	m_MoveVector = XMLoadFloat3(&temt);
	m_MoveVector = XMVector3Normalize(m_MoveVector);
	isActive = true;
	m_MoveUp = true;
	timer = 0;
	//SetRotation(temt);
}*/

/*
void ArtilleryBullet::Execute(XMFLOAT3 pos)//bullet update
{
	if (m_MoveUp)
	{
		// 중력 + 장약으로 인한 변위
		XMFLOAT3 tv = { 0.0f, speed * GetDeltaTime(), 0};

		Translate(tv);

		if (transform.position.y > 20)
		{
			timer = 0;
			m_MoveUp = false;
			transform.eulerRotation.x = XM_PI * 0.499f;

			transform.position = temt;
			transform.position.y = 20;
		}
	}
	else
	{
		// 중력 + 장약으로 인한 변위
		XMFLOAT3 tv = { 0.0f, -0.0000980f * timer - speed * GetDeltaTime(), 0};

		// 실질적 좌표 이동
		Translate(tv);

		if (transform.position.y < -5)
		{
			isActive = false;
		}
	}

	timer += GetDeltaTime();
}*/
