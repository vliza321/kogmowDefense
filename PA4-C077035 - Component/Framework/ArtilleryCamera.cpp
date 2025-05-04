#include "ArtilleryCamera.h"
#include "ObjectClass.h"
#include "GameObject.h"
#include "Transform.h"

ArtilleryCamera::ArtilleryCamera()
	: CameraObject()
{
	m_moveBackForward = 0;
	m_moveLeftRight = 0;
}

ArtilleryCamera::~ArtilleryCamera()
{
}

bool ArtilleryCamera::InitializeRef()
{
	transform = this->gameObject->GetComponent<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}

	auto player = this->gameObject->root->FindObjectWithTag(Tag::Player);
	targetTransform = player->GetComponent<Transform>();

	return true;
}

bool ArtilleryCamera::PostInitialize()
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

void ArtilleryCamera::SetCameraInfo()
{
	auto tf = transform.lock();
	auto tt = targetTransform.lock();
	tf->position = tt->position;
	tf->rotation = tt->rotation;
	tf->eulerRotation = tt->eulerRotation;
	tf->ApplyTranslate(XMFLOAT3(0, 15.0f, 0.00f));
}

/// <summary>
/// 1. 카메라 오프셋 세팅
/// 2. 카메라 로테이션 계산
/// 3. lookAt& 카메라 position 계산
/// 3.0. lookAt이 플레이어 포지션과 동일하다는 가정하에 시작
/// 3.1. 카메라 이동 좌표 계산
/// 3.2. 이동 좌표 만큼 position 및 LookAt에 추가
/// </summary>
void ArtilleryCamera::Execute()
{
	auto tf = transform.lock();
	XMVECTOR LookAtOffSet = XMVectorSet(0, -15.0f, 0.00f, 0);
	XMMATRIX RotationMatrix;
	XMVECTOR MoveVector = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Right = XMVectorSet(0, 0, 0, 0);
	XMVECTOR Forward = XMVectorSet(0, 0, 0, 0);
	XMFLOAT3 temt = XMFLOAT3(0, 0, 0);

	if (InputClass::GetInstance().IsKey(DIK_W))
	{
		m_moveBackForward = +1;
	}
	if (InputClass::GetInstance().IsKey(DIK_S))
	{
		m_moveBackForward = -1;
	}
	if (InputClass::GetInstance().IsKey(DIK_A))
	{
		m_moveLeftRight = -1;
	}
	if (InputClass::GetInstance().IsKey(DIK_D))
	{
		m_moveLeftRight = 1;
	}

	//카메라 물리적 이동 과정
	RotationMatrix = XMMatrixRotationY(tf->eulerRotation.y);

	Right = XMVector3TransformCoord(DefaultRight, RotationMatrix);
	Forward = XMVector3TransformCoord(DefaultForward, RotationMatrix);

	if (!XMVector3IsNaN(MoveVector) && !XMVector3IsNaN(Right))
	{
		MoveVector += m_moveLeftRight * Right;
	}
	if (!XMVector3IsNaN(MoveVector) && !XMVector3IsNaN(Forward))
	{
		MoveVector += m_moveBackForward * Forward;
	}

	temt.x = XMVectorGetX(MoveVector);
	temt.y = XMVectorGetY(MoveVector);
	temt.z = XMVectorGetZ(MoveVector);
	
	temt.x = temt.x * speed * GetDeltaTime() * 0.35f;
	temt.y = temt.y * speed * GetDeltaTime() * 0.35f;
	temt.z = temt.z * speed * GetDeltaTime() * 0.35f;

	tf->ApplyTranslate(temt);

	MoveVector = XMVectorSet(0, 0, 0, 0);

	position = XMLoadFloat3(&tf->position);

	lookAt = position + LookAtOffSet;

	XMStoreFloat3(&tf->position, position);

	RotationMatrix = XMMatrixRotationRollPitchYaw(tf->eulerRotation.x, tf->eulerRotation.y, 0);

	up = XMVector3TransformCoord(DefaultForward, RotationMatrix);

	//viewMatrix 생성
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

	m_moveLeftRight = 0.0f;
	m_moveBackForward = 0.0f;
}

void ArtilleryCamera::CameraStart()
{
	SetCameraInfo();
}

void ArtilleryCamera::CameraEnd()
{

}
