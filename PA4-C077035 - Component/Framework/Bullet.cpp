#include "Bullet.h"
#include "algorithm"
#include "ObjectClass.h"
#include "GameObject.h"

Bullet::Bullet()
	: BaseBullet(ShootType::FPC)
{

}

Bullet::~Bullet()
{

}

bool Bullet::InitializeSet()
{
	active = false;
	speed = 0.1f;
	return true;
}

bool Bullet::Initialize()
{
	return true;
}

bool Bullet::InitializeRef()
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

bool Bullet::InitializeSynchronization()
{
	return true;
}

bool Bullet::PostInitialize()
{
	return true;
}

void Bullet::FixedExecute()
{
	// 장약으로 인한 변위
	XMVECTOR tv = { 0.0f, 0, speed * GetDeltaTime() * 0.05f, 0 };
	// 중력으로 인한 변위
	XMVECTOR tg = { 0.0f, -0.000098f * timer , 0, 0 };
	auto tf = transform.lock();

	XMStoreFloat3(&temt, m_moveVector);

	// 변위에 적용할 회전행렬 계산
	m_rotationMatrix = XMMatrixRotationRollPitchYaw(tf->eulerRotation.x, tf->eulerRotation.y, 0);

	// 변위와 회전행렬 계산으로 최종 변위 도출
	m_moveVector = XMVector3TransformCoord(tv, m_rotationMatrix) + tg;

	// 최종 변위 합계
	temt.x += XMVectorGetX(m_moveVector);
	temt.y += XMVectorGetY(m_moveVector);
	temt.z += XMVectorGetZ(m_moveVector);

	// 실질적 좌표 이동
	tf->Translate(temt);

	// 회전 각도 계산
	double pitchAngle = asinf(XMVectorGetY(m_moveVector));

	pitchAngle = (pitchAngle > 0) ? pitchAngle : -pitchAngle;

	// 라디안 값 변환 및 회전 계산
	tf->rotation.x += pitchAngle;

	if (tf->position.y < 0)
	{
		active = false;
		this->gameObject->active = false;
	}

	timer += GetDeltaTime();
}

void Bullet::Execute()
{

}

void Bullet::LateExecute()
{
}

void Bullet::PostExecute()
{
}

void Bullet::OnCollisionEnter(Collider* other)
{
	active = false;
	this->gameObject->active = false;
}

void Bullet::OnCollisionStay(Collider* other)
{
	active = false;
	this->gameObject->active = false;
}

void Bullet::OnCollisionExit(Collider* other)
{
}


void Bullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	auto tf = transform.lock();

	tf->position = PlayerPosition;
	tf->position.y += 0.70f;

	tf->eulerRotation = PlayerEulerRotation;
	tf->eulerRotation.x -= XM_PI * 0.10f;

	temt.x = XMVectorGetX(CameraLookAt) - PlayerPosition.x;
	temt.y = XMVectorGetY(CameraLookAt) - PlayerPosition.y;
	temt.z = XMVectorGetZ(CameraLookAt) - PlayerPosition.z;

	m_moveVector = XMVector3Normalize(XMLoadFloat3(&temt));


	// 최종 변위 합계
	temt.x += XMVectorGetX(m_moveVector);
	temt.y += XMVectorGetY(m_moveVector);
	temt.z += XMVectorGetZ(m_moveVector);

	active = true;
	this->gameObject->active = true;

	timer = 0;
	
	temt = XMFLOAT3(0.0f, 0.0f, 0.0f);
	tf->rotation = temt;
}

bool Bullet::Shutdown()
{
	return true;
}

void Bullet::OnEnable()
{

}

void Bullet::OnDisable()
{
}

