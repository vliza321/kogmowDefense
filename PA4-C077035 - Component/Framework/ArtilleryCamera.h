#pragma once
#include <directxmath.h>
#include "CameraObject.h"
using namespace DirectX;


class ArtilleryCamera : public CameraObject
{
public:
	ArtilleryCamera();
	~ArtilleryCamera();

	virtual bool InitializeRef() override;
	virtual bool PostInitialize() override;
	virtual void Execute() override;

public:
	virtual void SetCameraInfo() override;

	virtual void CameraStart() override;
	virtual void CameraEnd() override;

private:
	int m_moveLeftRight;
	int m_moveBackForward;
};