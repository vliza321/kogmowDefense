#include "SkyBox.h"
#include "algorithm"


SkyBox::SkyBox()
	:GameObject()
{

}

SkyBox::SkyBox(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: GameObject(position, rotation, scale, modelFilename, textureFilename, instanceCounter)
{

}

SkyBox::~SkyBox()
{

}

bool SkyBox::Initialize(ID3D11Device* device)
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

void SkyBox::Execute(XMFLOAT3 pos)
{

}

bool SkyBox::Shutdown()
{
	m_Model->Shutdown();
	return true;
}

