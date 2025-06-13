#include "ScopeBullet.h"
#include "algorithm"

#include "algorithm"
#include "ObjectClass.h"
#include "GameObject.h"

ScopeBullet::ScopeBullet()
	: BaseBullet(ShootType::Scope)
{

}

ScopeBullet::~ScopeBullet()
{

}

bool ScopeBullet::InitializeSet()
{
	active = false;
	speed = 0.1f;
	return true;
}

bool ScopeBullet::Initialize()
{
	return true;
}

bool ScopeBullet::InitializeRef()
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

bool ScopeBullet::InitializeSynchronization()
{
	return true;
}

bool ScopeBullet::PostInitialize()
{
	return true;
}

void ScopeBullet::FixedExecute()
{
	// ������� ���� ����
	XMVECTOR tv = { 0.0f, 0, speed * GetDeltaTime() * 0.15f, 0 };
	// �߷����� ���� ����
	XMVECTOR tg = { 0.0f, -0.0000498f * timer , 0, 0 };
	auto tf = transform.lock();

	temt = XMFLOAT3(0.0f, 0.0f, 0.0f);

	XMStoreFloat3(&temt, m_moveVector);

	// ������ ������ ȸ����� ���
	m_rotationMatrix = XMMatrixRotationRollPitchYaw(tf->eulerRotation.x, tf->eulerRotation.y, 0);

	// ������ ȸ����� ������� ���� ���� ����
	m_moveVector = XMVector3TransformCoord(tv, m_rotationMatrix) + tg;

	// ���� ���� �հ�
	temt.x += XMVectorGetX(m_moveVector);
	temt.y += XMVectorGetY(m_moveVector);
	temt.z += XMVectorGetZ(m_moveVector);

	// ������ ��ǥ �̵�
	tf->Translate(temt);

	// ȸ�� ���� ���
	double pitchAngle = asinf(temt.y);

	(temt.y < 0) ? tf->rotation.x = pitchAngle : tf->rotation.x = -pitchAngle;

	if (tf->position.y < 0)
	{
		active = false;
		this->gameObject->active = false;
	}

	timer += GetDeltaTime();
}

void ScopeBullet::Execute()
{

}

void ScopeBullet::LateExecute()
{
}

void ScopeBullet::PostExecute()
{
}

void ScopeBullet::OnCollisionEnter(Collider* other)
{
	active = false;
	this->gameObject->active = false;
}

void ScopeBullet::OnCollisionStay(Collider* other)
{
	active = false;
	this->gameObject->active = false;
}

void ScopeBullet::OnCollisionExit(Collider* other)
{
}


void ScopeBullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	auto tf = transform.lock();

	tf->position = PlayerPosition;
	tf->position.y += 0.70f;

	tf->eulerRotation = PlayerEulerRotation;
	tf->eulerRotation.x -= XM_PI * 0.010f;

	temt.x = XMVectorGetX(CameraLookAt) - PlayerPosition.x;
	temt.y = XMVectorGetY(CameraLookAt) - PlayerPosition.y;
	temt.z = XMVectorGetZ(CameraLookAt) - PlayerPosition.z;

	m_moveVector = XMVector3Normalize(XMLoadFloat3(&temt));


	// ���� ���� �հ�
	temt.x += XMVectorGetX(m_moveVector);
	temt.y += XMVectorGetY(m_moveVector);
	temt.z += XMVectorGetZ(m_moveVector);

	active = true;
	this->gameObject->active = true;

	timer = 0;

	temt = XMFLOAT3(0.0f, 0.0f, 0.0f);
	tf->rotation = temt;
}

bool ScopeBullet::Shutdown()
{
	return true;
}

void ScopeBullet::OnEnable()
{

}

void ScopeBullet::OnDisable()
{
}
