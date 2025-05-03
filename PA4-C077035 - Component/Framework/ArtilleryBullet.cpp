#include "ArtilleryBullet.h"
#include "algorithm"


ArtilleryBullet::ArtilleryBullet()
	: BaseBullet()
{
	m_BulletType = ShootType::Artillery;
	m_MoveUp = true;
}

ArtilleryBullet::ArtilleryBullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale,
	const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: BaseBullet(position, rotation, scale, modelFilename, textureFilename, instanceCounter)
{
	m_BulletType = ShootType::Artillery;
	m_MoveUp = true;
}

ArtilleryBullet::~ArtilleryBullet()
{

}

bool ArtilleryBullet::Initialize(ID3D11Device* device)
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

	speed = 0.05f;

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
}


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
}

bool ArtilleryBullet::Shutdown()
{
	m_Model->Shutdown();
	return true;
}
