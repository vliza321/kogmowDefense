#pragma once
#include <directxmath.h>
#include <iostream>
#include <map>
#include <memory>
#include "ShootType.h"
#include "CameraObject.h"
#include "BaseCamera.h"
#include "FirstPersonCamera.h"
#include "ThirdPersonCamera.h"
#include "ScopeCamera.h"
#include "ArtilleryCamera.h"
//#include "TitleCamera.h"
#include "Component.h"

using namespace std;

class CameraManager : public Component
{
public:
	CameraManager();
	~CameraManager();

	virtual bool InitializeSet() override;
	virtual bool Initialize() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual bool PostInitialize() override;

	virtual void Execute() override;

	virtual bool Shutdown() override;

	void SetCameraInfo(Transform&);
	void SetCamera(ShootType, const Transform&);

	XMMATRIX GetViewMatrix();
	XMVECTOR GetLookAt();

	CameraObject* GetCamera();

private:
	ShootType m_CurrentCameraType;
	map<ShootType, CameraObject*>m_CameraMapSet;
};