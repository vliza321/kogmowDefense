#include "Billboard.h"
#include "algorithm"


Billboard::Billboard()
{

}

Billboard::Billboard(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: GameObject(position, rotation, scale, modelFilename, textureFilename, instanceCounter)

{
	
}

Billboard::~Billboard()
{

}

bool Billboard::Initialize(ID3D11Device* device)
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

void Billboard::Execute(XMFLOAT3 camPos)//billboard update
{
	XMVECTOR cameraToObject = XMVectorSet(transform.position.x - camPos.x, transform.position.y - camPos.y, transform.position.z - camPos.z, 0);

	cameraToObject = XMVector3Normalize(cameraToObject);

	double angle = atan2(XMVectorGetX(cameraToObject), XMVectorGetZ(cameraToObject));

	transform.eulerRotation.y = (float)angle;

	float angleX = -asin(XMVectorGetY(cameraToObject)); // asin을 사용하면 반전 방지 가능

	transform.eulerRotation.x = angleX;
}

bool Billboard::Shutdown()
{
	m_Model->Shutdown();
	return true;
}

