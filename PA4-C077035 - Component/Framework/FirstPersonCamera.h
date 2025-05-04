#pragma once
#include <directxmath.h>
#include "CameraObject.h"
using namespace DirectX;


class FirstPersonCamera : public CameraObject
{
public:
	FirstPersonCamera();
	~FirstPersonCamera();

	virtual bool InitializeRef() override;
	virtual bool PostInitialize() override;
	virtual void Execute() override;

public:
	virtual void SetCameraInfo() override;

	virtual void CameraStart() override;
	virtual void CameraEnd() override;
};