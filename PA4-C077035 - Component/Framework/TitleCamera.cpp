#include "TitleCamera.h"

TitleCamera::TitleCamera()
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
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
	camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	position = XMLoadFloat3(&transform.position);
	//position = XMLoadFloat3(&(XMFLOAT3(transform.position.x, transform.position.y, transform.position.z)));
	lookAt = XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f);
	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	speed = 0.033f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	transform.eulerRotation.x = transform.rotation.x * 0.0174532925f;
	transform.eulerRotation.y = transform.rotation.y * 0.0174532925f;
	transform.eulerRotation.z = transform.rotation.z * 0.0174532925f;

}

bool TitleCamera::Initialize(ID3D11Device* device)
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

	up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	position = XMLoadFloat3(&transform.position);
	//position = XMLoadFloat3(&(XMFLOAT3(transform.position.x, transform.position.y, transform.position.z)));
	lookAt = XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f);
	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	speed = 0.033f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	transform.eulerRotation.x = transform.rotation.x * 0.0174532925f;
	transform.eulerRotation.y = transform.rotation.y * 0.0174532925f;
	transform.eulerRotation.z = transform.rotation.z * 0.0174532925f;


	return true;
}

bool TitleCamera::Shutdown()
{
	return true;
}

TitleCamera::~TitleCamera()
{
}

void TitleCamera::SetScene(int SceneCounter, Transform PlayerTransform)
{
	
	SetPosition(XMFLOAT3(-50.0f, 50.0f, 0.0f));
	SetRotation(XMFLOAT3(-50.0f, 0.0f, 0.0f));
	//1인칭 오프셋
	XMVECTOR CameraOffSet = XMVectorSet(0, 2.55f, -1.50f, 0);

	//바라볼 좌표 계산
	camRotationMatrix = XMMatrixRotationRollPitchYaw(transform.eulerRotation.x, transform.eulerRotation.y, 0);

	camForward = XMVector3TransformCoord(DefaultForward, camRotationMatrix);

	lookAt = XMLoadFloat3(&PlayerTransform.position);

	lookAt += 5 * camForward;

	//카메라 위치 계산
	position = XMLoadFloat3(&transform.position);

	position += XMVector3TransformCoord(CameraOffSet, camRotationMatrix);

	XMStoreFloat3(&transform.position, position);

	//viewMatrix 생성
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, up);
}

void TitleCamera::SetCameraInfo(Transform transform)
{
	SetPosition(transform.position.x, transform.position.y, transform.position.z);
	SetEulerRotation(transform.eulerRotation);
	SetRotation(transform.rotation);
}

void TitleCamera::Execute(XMFLOAT3 playerPos)
{

}

void TitleCamera::CameraStart(Transform transform)
{
	SetCameraInfo(transform);
}

void TitleCamera::CameraEnd()
{

}