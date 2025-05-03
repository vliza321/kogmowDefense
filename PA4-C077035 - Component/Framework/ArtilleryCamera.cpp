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
/// 1. ī�޶� ������ ����
/// 2. ī�޶� �����̼� ���
/// 3. lookAt& ī�޶� position ���
/// 3.0. lookAt�� �÷��̾� �����ǰ� �����ϴٴ� �����Ͽ� ����
/// 3.1. ī�޶� �̵� ��ǥ ���
/// 3.2. �̵� ��ǥ ��ŭ position �� LookAt�� �߰�
/// </summary>
void ArtilleryCamera::Execute(XMFLOAT3 playerPos)
{
	XMVECTOR LookAtOffSet = XMVectorSet(0, -10.0f, 0.00f, 0);
	temt = XMFLOAT3(0, 0, 0);

	//ī�޶� ������ �̵� ����
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

	//viewMatrix ����
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
	// Euler ȸ�� �� ������Ʈ
	transform.eulerRotation.x += p;  // Pitch (X��)
	transform.eulerRotation.y += y;  // Yaw (Y��)
	transform.eulerRotation.z += r;  // Roll (Z��)

	transform.eulerRotation.y = max(-XM_PI * 0.499f, min(-XM_PI * 0.001f, transform.eulerRotation.y));
}
