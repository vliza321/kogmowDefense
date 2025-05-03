#pragma once
#include <directxmath.h>
#include "CameraObject.h"

using namespace DirectX;


class TitleCamera : public CameraObject
{
public:
	TitleCamera();
	~TitleCamera();

	void SetScene(int, Transform) override;
	void SetCameraInfo(Transform) override;

	bool Initialize() override;
	void Execute() override;
	bool Shutdown() override;

	void CameraStart(Transform) override;
	void CameraEnd() override;

private:
};