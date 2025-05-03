#pragma once
#include <directxmath.h>
#include "CameraObject.h"
using namespace DirectX;


class ScopeCamera : public CameraObject
{
public:
	ScopeCamera();
	~ScopeCamera();

	void SetScene(int, Transform) override;
	void SetCameraInfo(Transform) override;

	bool Initialize() override;
	void Execute() override;
	bool Shutdown() override;

	void CameraStart(Transform) override;
	void CameraEnd() override;

private:
};

