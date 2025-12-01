#include "TestPlayer.h"
#include "algorithm"
#include "ObjectClass.h"
#include "SceneManager.h"

TestPlayer::TestPlayer()
	: Component()
{

}

TestPlayer::~TestPlayer()
{

}

bool TestPlayer::InitializeSet()
{
	return true;
}

bool TestPlayer::Initialize()
{
	m_moveLeftRight = 0;
	m_moveBackForward = 0;
	speed = 0.0033f;
	return true;
}

bool TestPlayer::InitializeRef()
{
	transform = this->gameObject->GetComponent<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}
	return true;
}

bool TestPlayer::InitializeSynchronization()
{
	return true;
}

bool TestPlayer::PostInitialize()
{
	//SetPov(ShootType::TPC);
	return true;
}

void TestPlayer::FixedExecute()
{
	auto tf = transform.lock();

	XMMATRIX RotationMatrix;
	XMVECTOR MoveVector = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Right = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Forward = XMVectorSet(0, 0, 0, 0);
	XMFLOAT3 temt = XMFLOAT3(0, 0, 0);

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

	temt.x = XMVectorGetX(MoveVector) * speed * DeltaTime();
	temt.y = XMVectorGetY(MoveVector) * speed * DeltaTime();
	temt.z = XMVectorGetZ(MoveVector) * speed * DeltaTime();

	tf->Translate(temt);
	m_moveBackForward = 0;
	m_moveLeftRight = 0;
}

void TestPlayer::Execute()
{
	auto tf = transform.lock();
	auto& input = Input();

	if (input.IsKey(DIK_W))
	{
		m_moveBackForward = 1;
	}
	if (input.IsKey(DIK_S))
	{
		m_moveBackForward = -1;
	}
	if (input.IsKey(DIK_A))
	{
		m_moveLeftRight = -1;
	}
	if (input.IsKey(DIK_D))
	{
		m_moveLeftRight = 1;
	}
	if (input.IsKeyDown(DIK_LSHIFT))
	{
		speed *= 4;
	}
	if (input.IsKeyUp(DIK_LSHIFT))
	{
		speed *= 0.25f;
	}
	if (((input.GetCurrMouseState().lX != input.GetLastMouseState().lX) || (input.GetCurrMouseState().lY != input.GetLastMouseState().lY)))
	{
		tf->eulerRotation.x += input.GetCurrMouseState().lY * 0.001f;
		tf->eulerRotation.y += input.GetCurrMouseState().lX * 0.001f;
		tf->eulerRotation.x = max(-XM_PI * 0.2499f, min(XM_PI * 0.2999f, tf->eulerRotation.x));
	}
}

void TestPlayer::LateExecute()
{
}

void TestPlayer::PostExecute()
{
}

bool TestPlayer::Shutdown()
{
	transform.reset();
	return true;
}
