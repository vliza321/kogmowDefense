#include "ArtilleryCamera.h"

ArtilleryCamera::ArtilleryCamera()
	: CameraObject()
{
	/*
	m_viewMatrix = XMMatrixIdentity();
	camRotationMatrix = XMMatrixIdentity();
	*/
	transform.position.x = 0.0f;
	transform.position.y = 0.0f;
	transform.position.z = -5.0f;

	transform.rotation.x = 45.0f;
	transform.rotation.y = 090.0f;
	transform.rotation.z = 0.0f;

	transform.scale.x = 1;
	transform.scale.y = 1;
	transform.scale.z = 1;

	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	up = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
	position = XMLoadFloat3(&transform.position);
	//position = XMLoadFloat3(&(XMFLOAT3(transform.position.x, transform.position.y, transform.position.z)));
	lookAt = XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f);
	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	speed = 0.004f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	transform.eulerRotation.x = transform.rotation.x * 0.0174532925f;
	transform.eulerRotation.y = transform.rotation.y * 0.0174532925f;
	transform.eulerRotation.z = transform.rotation.z * 0.0174532925f;

}

bool ArtilleryCamera::Initialize(ID3D11Device* device)
{
	/*
	m_viewMatrix = XMMatrixIdentity();
	camRotationMatrix = XMMatrixIdentity();
	*/
	transform.position.x = 0.0f;
	transform.position.y = 0.0f;
	transform.position.z = -5.0f;

	transform.rotation.x = 45.0f;
	transform.rotation.y = 090.0f;
	transform.rotation.z = 0.0f;

	transform.scale.x = 1;
	transform.scale.y = 1;
	transform.scale.z = 1;

	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
	camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	up = XMVectorSet(0.0f, 0.0f, 01.0f, 0.0f);
	position = XMLoadFloat3(&transform.position);
	//position = XMLoadFloat3(&(XMFLOAT3(transform.position.x, transform.position.y, transform.position.z)));
	lookAt = XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f);
	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	speed = 0.004f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	transform.eulerRotation.x = transform.rotation.x * 0.0174532925f;
	transform.eulerRotation.y = transform.rotation.y * 0.0174532925f;
	transform.eulerRotation.z = transform.rotation.z * 0.0174532925f;


	return true;
}

bool ArtilleryCamera::Shutdown()
{
	return true;
}

ArtilleryCamera::~ArtilleryCamera()
{
}

void ArtilleryCamera::SetScene(int SceneCounter, Transform transform)
{
	SetCameraInfo(transform);
	Execute(transform.position);
}

void ArtilleryCamera::SetCameraInfo(Transform transform)
{
	SetPosition(transform.position.x, transform.position.y + 10.5f, transform.position.z);
	SetEulerRotation(transform.eulerRotation);
	SetRotation(transform.rotation);
}

/// <summary>
/// 1. 카메라 오프셋 세팅
/// 2. 카메라 로테이션 계산
/// 3. lookAt& 카메라 position 계산
/// 3.0. lookAt이 플레이어 포지션과 동일하다는 가정하에 시작
/// 3.1. 카메라 이동 좌표 계산
/// 3.2. 이동 좌표 만큼 position 및 LookAt에 추가
/// </summary>
void ArtilleryCamera::Execute(XMFLOAT3 playerPos)
{
	XMVECTOR LookAtOffSet = XMVectorSet(0, -10.0f, 0.00f, 0);
	temt = XMFLOAT3(0, 0, 0);

	//카메라 물리적 이동 과정
	RotationMatrix = XMMatrixRotationY(transform.eulerRotation.y);

	Right = XMVector3TransformCoord(DefaultRight, RotationMatrix);
	Forward = XMVector3TransformCoord(DefaultForward, RotationMatrix);

	if (!XMVector3IsNaN(m_MoveVector) && !XMVector3IsNaN(Right))
	{
		m_MoveVector += moveLeftRight * Right;
	}
	if (!XMVector3IsNaN(m_MoveVector) && !XMVector3IsNaN(Forward))
	{
		m_MoveVector += moveBackForward * Forward;
	}
	
	position += m_MoveVector;

	temt.x = XMVectorGetX(m_MoveVector);
	temt.y = XMVectorGetY(m_MoveVector);
	temt.z = XMVectorGetZ(m_MoveVector);
	
	transform.position.x += temt.x * speed * GetDeltaTime() * 1000;
	transform.position.y += temt.y * speed * GetDeltaTime() * 1000;
	transform.position.z += temt.z * speed * GetDeltaTime() * 1000;

	m_MoveVector = XMVectorSet(0, 0, 0, 0);

	position = XMLoadFloat3(&transform.position);

	lookAt = position + LookAtOffSet;

	XMStoreFloat3(&transform.position, position);

	camRotationMatrix = XMMatrixRotationRollPitchYaw(transform.eulerRotation.x, transform.eulerRotation.y, 0);

	up = XMVector3TransformCoord(DefaultForward, camRotationMatrix);

	//viewMatrix 생성
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;
}

void ArtilleryCamera::CameraStart(Transform transform)
{
	SetCameraInfo(transform);
}

void ArtilleryCamera::CameraEnd()
{

}

void ArtilleryCamera::SetRollPitchYaw(float r, float p, float y)
{
	// Euler 회전 값 업데이트
	transform.eulerRotation.x += p;  // Pitch (X축)
	transform.eulerRotation.y += y;  // Yaw (Y축)
	transform.eulerRotation.z += r;  // Roll (Z축)

	transform.eulerRotation.y = max(-XM_PI * 0.499f, min(-XM_PI * 0.001f, transform.eulerRotation.y));
}
