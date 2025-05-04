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
	virtual void SetCameraInfo() override;

	virtual void CameraStart() override;
	virtual void CameraEnd() override;
};

#endif