#include "CameraObject.h"


CameraObject::CameraObject()
	:Component()
{
	m_viewMatrix = XMMatrixIdentity();
	camRotationMatrix = XMMatrixIdentity();

	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

	camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	position = XMVectorSet(0.0f, 0.0f, -10.0f, 0.0f);
	lookAt = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	speed = 0.033f;

	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);
}


CameraObject::~CameraObject()
{
}

bool CameraObject::InitializeRef()
{
	bool result = true;

	transform = this->gameObject->GetComponent<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}
	return result;
}

bool CameraObject::PostInitialize()
{
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);
	return false;
}

void CameraObject::SetCameraInfo()
{

}

XMMATRIX CameraObject::GetViewMatrix()
{
	return m_viewMatrix;
}

XMVECTOR CameraObject::GetLookAt()
{
	return lookAt;
}