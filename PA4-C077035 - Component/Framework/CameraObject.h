#ifndef CAMERA_OBJECT_H
#define CAMERA_OBJECT_H

#pragma once
#include <directxmath.h>
#include <memory>

#include "Component.h"
#include "Transform.h"

class CameraObject : public Component
{
public:
	CameraObject();
	~CameraObject();

	virtual bool InitializeRef() override;
	virtual bool PostInitialize() override;

public:
	virtual void SetCameraInfo() = 0;

	virtual void CameraStart() = 0;
	virtual void CameraEnd() = 0;

	XMMATRIX GetViewMatrix();
	XMVECTOR GetLookAt();
	XMFLOAT3 GetPosition();

protected:
	std::weak_ptr<Transform> transform;
	std::weak_ptr<Transform> targetTransform;

	XMMATRIX m_viewMatrix;

	XMVECTOR DefaultForward;
	XMVECTOR DefaultRight;
	XMVECTOR DefaultUp;
	
	XMVECTOR camForward;
	XMVECTOR camRight;

	XMMATRIX camRotationMatrix;

	XMVECTOR up, position, lookAt;

	float speed = 0.033f;
};

#endif