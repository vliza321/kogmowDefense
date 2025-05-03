#include "Bullet.h"
#include "algorithm"


Bullet::Bullet()
	: BaseBullet()
{
	m_BulletType = ShootType::FPC;
}

Bullet::Bullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale,
	const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: BaseBullet(position, rotation, scale, modelFilename, textureFilename, instanceCounter)
{
	m_BulletType = ShootType::FPC;
}

Bullet::~Bullet()
{

}

bool Bullet::Initialize(ID3D11Device* device)
{
	transform.eulerRotation.x = 0;
	transform.eulerRotation.y = 0;
	transform.eulerRotation.z = 0;

	frontMoveDirection = XMVectorSet(1, 0, 0, 0);
	sideMoveDirection = XMVectorSet(0, 0, 1, 0);

	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	m_MoveVector = XMVectorSet(0, 0, 0, 0);

	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	Right = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	Forward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	isActive = true;
	timer = 0;

	speed = 0.045f;

	bool result;
	m_Model = new ModelClass;
	if (!m_Model)
	{
		return false;
	}
	result = m_Model->Initialize(device, m_ModelFileName, m_TextureFileName, m_InstanceCounter);
	if (!result)
	{
		return false;
	}

	return true;
}


void Bullet::BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation)
{
	SetPosition(PlayerPosition.x,PlayerPosition.y +0.70f, PlayerPosition.z);
	temt.x = XMVectorGetX(CameraLookAt) - transform.position.x;
	temt.y = XMVectorGetY(CameraLookAt) - transform.position.y;
	temt.z = XMVectorGetZ(CameraLookAt) - transform.position.z;
	SetEulerRotation(PlayerEulerRotation);
	transform.eulerRotation.x -= XM_PI * 0.10f;
	m_MoveVector = XMLoadFloat3(&temt);
	m_MoveVector = XMVector3Normalize(m_MoveVector);
	isActive = true;
	timer = 0;
	temt = XMFLOAT3(0.0f, 0.0f, 0.0f);
	SetRotation(temt);
}


void Bullet::Execute(XMFLOAT3 pos)//bullet update
{
	// �߷� + ������� ���� ����
	XMVECTOR tv = { 0.0f, -0.000098f * timer, speed * GetDeltaTime() * 0.15f, 0};
	
	temt.x = XMVectorGetX(m_MoveVector);
	temt.y = XMVectorGetY(m_MoveVector);
	temt.z = XMVectorGetZ(m_MoveVector); 

	// ������ ������ ȸ����� ���
	RotationMatrix = XMMatrixRotationRollPitchYaw(transform.eulerRotation.x, transform.eulerRotation.y, 0);

	// ������ ȸ����� ������� ���� ���� ����
	m_MoveVector = XMVector3TransformCoord(tv, RotationMatrix);

	// ���� ���� �հ�
	temt.x += XMVectorGetX(m_MoveVector);
	temt.y += XMVectorGetY(m_MoveVector);
	temt.z += XMVectorGetZ(m_MoveVector);

	// ������ ��ǥ �̵�
	Translate(temt);

	// ȸ�� ���� ���
	double pitchAngle = asinf(XMVectorGetY(m_MoveVector));

	pitchAngle = (pitchAngle > 0) ? pitchAngle : -pitchAngle;

	// ���� �� ��ȯ �� ȸ�� ���
	transform.rotation.x -= pitchAngle;

	if (transform.position.y < 0)
	{
		isActive = false;
	}

	timer += GetDeltaTime();
}

bool Bullet::Shutdown()
{
	m_Model->Shutdown();
	return true;
}

