#include "ScopeCamera.h"
#include "ObjectClass.h"
#include "GameObject.h"
#include "Transform.h"

ScopeCamera::ScopeCamera()
	: CameraObject()
{
	
}

ScopeCamera::~ScopeCamera()
{
}

bool ScopeCamera::InitializeRef()
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

bool ScopeCamera::PostInitialize()
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

void ScopeCamera::SetCameraInfo()
{
	transform = targetTransform;
}

void ScopeCamera::Execute()
{
	auto tf = transform.lock();
	auto target = targetTransform.lock();
	XMVECTOR CameraOffSet = XMVectorSet(0, 0.75f, 2.50f, 0);

	//회전 행렬 계산
	camRotationMatrix = XMMatrixRotationRollPitchYaw(tf->eulerRotation.x, tf->eulerRotation.y, 0);

	//카메라 위치 계산
	position = XMLoadFloat3(&tf->position);

	position += XMVector3TransformCoord(CameraOffSet, camRotationMatrix);

	//바라볼 좌표 계산
	camForward = XMVector3TransformCoord(DefaultForward, camRotationMatrix);

	lookAt = XMLoadFloat3(&tf->position);

	lookAt += 5 * camForward;

	//viewMatrix 생성
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);
}


void ScopeCamera::CameraStart()
{
	SetCameraInfo();
}

void ScopeCamera::CameraEnd()
{

}