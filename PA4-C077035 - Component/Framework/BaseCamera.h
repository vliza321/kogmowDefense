#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H

#pragma once
#include "CameraObject.h"

class BaseCamera :
    public CameraObject
{
public:
	BaseCamera();
	~BaseCamera();

	virtual bool InitializeRef() override;
	virtual bool PostInitialize() override;
	virtual void Execute() override;

public:
	virtual void SetScene(int, Transform) override;
	virtual void SetCameraInfo(Transform) override;

	virtual void CameraStart(Transform) override;
	virtual void CameraEnd() override;
};

#endif