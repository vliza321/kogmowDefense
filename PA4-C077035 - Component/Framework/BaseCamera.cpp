#include "BaseCamera.h"
#include "ObjectClass.h"
#include "GameObject.h"

BaseCamera::BaseCamera()
	: CameraObject()
{
}

BaseCamera::~BaseCamera()
{
}

bool BaseCamera::Initialize()
{
	lookAt = XMVectorSet(0, 0, 0, 0);
	position = XMVectorSet(0, 0, 0, 0);
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, DefaultUp);
	return true;
}

bool BaseCamera::PostInitialize()
{
	lookAt = XMVectorSet(10, 4, 0, 0);
	position = XMVectorSet(0, 8, 0, 0);
	m_viewMatrix = XMMatrixLookAtLH(position, lookAt, DefaultUp);
	return true;
}

void BaseCamera::Execute()
{
}

void BaseCamera::SetCameraInfo()
{
}

void BaseCamera::CameraStart()
{
}

void BaseCamera::CameraEnd()
{
}
