#pragma once
#include <directxmath.h>
#include "CameraObject.h"
using namespace DirectX;


class ArtilleryCamera : public CameraObject
{
public:
	ArtilleryCamera();
	~ArtilleryCamera();

	void SetScene(int, Transform) override;
	void SetCameraInfo(Transform) override;

	bool Initialize() override;
	void Execute() override;
	bool Shutdown() override;

	void CameraStart(Transform) override;
	void CameraEnd() override;

	virtual void SetRollPitchYaw(float, float, float);

private:
};