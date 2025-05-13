#include "FirstPersonCamera.h"
#include "ObjectClass.h"
#include "GameObject.h"
#include "Transform.h"

FirstPersonCamera::FirstPersonCamera()
	:CameraObject()
{

}

bool FirstPersonCamera::InitializeRef()
{
	transform = this->gameObject->GetComponentIncludingBase<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}

	auto player = this->gameObject->root->FindObjectWithTag(Tag::Player);
	targetTransform = player->GetComponentIncludingBase<Transform>();
	return true;
}

bool FirstPersonCamera::PostInitialize()
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

FirstPersonCamera::~FirstPersonCamera()
{
}


void FirstPersonCamera::SetCameraInfo()
{
	transform = targetTransform;
}

void FirstPersonCamera::Execute()
{
	auto tf = transform.lock();
	auto target = targetTransform.lock();
	XMVECTOR CameraOffSet = XMVectorSet(0, 2.55f, -1.50f, 0);

	//�ٶ� ��ǥ ���
	camRotationMatrix = XMMatrixRotationRollPitchYaw(tf->eulerRotation.x, tf->eulerRotation.y, 0);

	camForward = XMVector3TransformCoord(DefaultForward, camRotationMatrix);

	lookAt = XMLoadFloat3(&tf->position);

	lookAt += 5 * camForward;

	//ī�޶� ��ġ ���
	position = XMLoadFloat3(&tf->position);

	position += XMVector3TransformCoord(CameraOffSet, camRotationMatrix);

	//XMStoreFloat3(&tf->position, position);

	//viewMatrix ����
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);
}

void FirstPersonCamera::CameraStart()
{
	SetCameraInfo();
}

void FirstPersonCamera::CameraEnd()
{

}