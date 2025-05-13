#include "BaseBullet.h"

BaseBullet::BaseBullet(ShootType shootType)
	:Component()
{
	m_bulletType = shootType;
	timer = 0;
	speed = 0;
}

BaseBullet::~BaseBullet()
{

}

bool BaseBullet::InitializeSet()
{
	return true;
}

bool BaseBullet::Initialize()
{
	return true;
}

bool BaseBullet::InitializeRef()
{
	return true;
}

bool BaseBullet::InitializeSynchronization()
{
	return true;
}

bool BaseBullet::PostInitialize()
{
	return true;
}

void BaseBullet::FixedExecute()
{
}

void BaseBullet::Execute()
{

}

void BaseBullet::LateExecute()
{

}

void BaseBullet::PostExecute()
{
}

bool BaseBullet::Shutdown()
{
	return true;
}

void BaseBullet::OnEnable()
{
}

void BaseBullet::OnDisable()
{
}

void BaseBullet::OnCollisionEnter(Collider* other)
{
}

void BaseBullet::OnCollisionStay(Collider* other)
{
}

void BaseBullet::OnCollisionExit(Collider* other)
{
}


ShootType BaseBullet::GetBulletType()
{
	return m_bulletType;
}

void BaseBullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{

}

