#include "Monster.h"
#include "algorithm"


Monster::Monster()
	:GameObject()
{

}

Monster::Monster(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: GameObject(position, rotation, scale, modelFilename, textureFilename, instanceCounter)

{
	
}

Monster::~Monster()
{

}

bool Monster::Initialize(ID3D11Device* device)
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

	speed = 0.033f;

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

void Monster::Execute(XMFLOAT3 playerPos)
{

	XMVECTOR PlayerToObject = XMVectorSet(transform.position.x - playerPos.x, 0, transform.position.z - playerPos.z, 0);

	PlayerToObject = XMVector3Normalize(PlayerToObject);

	double angle = atan2(XMVectorGetX(PlayerToObject), XMVectorGetZ(PlayerToObject));

	transform.eulerRotation.y = (float)angle;


	XMVECTOR tv;
	temt = XMFLOAT3(0.0f, 0.0f, -00.250f);
	tv = XMVectorSet(temt.x, temt.y, temt.z, 1);

	RotationMatrix = XMMatrixRotationY(transform.eulerRotation.y);

	m_MoveVector = XMVector3TransformCoord(tv, RotationMatrix);
	Forward = XMVector3TransformCoord(DefaultForward, RotationMatrix);

	if (!XMVector3IsNaN(m_MoveVector) && !XMVector3IsNaN(Right))
	{
		m_MoveVector += moveLeftRight * Right;
	}
	if (!XMVector3IsNaN(m_MoveVector) && !XMVector3IsNaN(Forward))
	{
		m_MoveVector += moveBackForward * Forward;
	}

	temt.x = XMVectorGetX(m_MoveVector) * speed * GetDeltaTime();
	temt.y = XMVectorGetY(m_MoveVector) * speed * GetDeltaTime();
	temt.z = XMVectorGetZ(m_MoveVector) * speed * GetDeltaTime();

	Translate(temt);
}

bool Monster::Shutdown()
{
	m_Model->Shutdown();
	return true;
}

