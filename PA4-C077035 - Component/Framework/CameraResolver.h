#ifndef _CAMERARESOLVER_H
#define _CAMERARESOLVER_H

#include "Component.h"
#include "CameraObject.h"
#include "BaseCamera.h"

using namespace std;

class CameraResolver : public Component
{
public:
	CameraResolver();
	~CameraResolver();

	virtual bool InitializeSet() override;
	virtual bool Initialize() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual bool PostInitialize() override;

	virtual void PostExecute() override;

	void PrevRender();
	virtual bool Shutdown() override;

	XMMATRIX GetViewMatrix() ;
	XMVECTOR GetLookAt() ;
	XMFLOAT3 GetCameraPosition() ;
	CameraObject* GetCamera() ;
private:
	vector<weak_ptr<CameraObject>> m_cameras;
	CameraObject* m_selectedCamera;
	BaseCamera* m_dummyCamera;
};

#endif