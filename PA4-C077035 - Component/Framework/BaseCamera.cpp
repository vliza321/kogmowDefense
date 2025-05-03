#include "BaseCamera.h"
#include "ObjectClass.h"
#include "GameObject.h"
#include "Transform.h"

BaseCamera::BaseCamera()
	: CameraObject()
{
}

BaseCamera::~BaseCamera()
{
}

bool BaseCamera::InitializeRef()
{
	transform = this->gameObject->GetComponent<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0,0,0), XMFLOAT3(0,0,0), XMFLOAT3(1,1,1), XMFLOAT3(0,0,0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}

	auto player = this->gameObject->root->FindObjectWithTag(Tag::Player);
	targetTransform = player->GetComponent<Transform>();

	return true;
}

bool BaseCamera::PostInitialize()
{
	auto l_transform = transform.lock();
	if (!l_transform) {
		std::cerr << "Transform no longer exists!\n";
		return false;
	}
	lookAt = XMVectorSet(0, 0, 0, 0);
	position = XMLoadFloat3(&l_transform->position);
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, DefaultUp);
	return true;
}

void BaseCamera::Execute()
{
	auto l_transform = transform.lock();
	//l_transform->ApplyTranslate(XMFLOAT3(0, 0.1f, 0));
	if (!l_transform) {
		return ;
	}
	lookAt = XMVectorSet(0, 0, 0, 0);
	position = XMLoadFloat3(&l_transform->position);
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, DefaultUp);
}

void BaseCamera::SetScene(int, Transform)
{
}

void BaseCamera::SetCameraInfo(Transform)
{
}

void BaseCamera::CameraStart(Transform)
{
}

void BaseCamera::CameraEnd()
{
}
