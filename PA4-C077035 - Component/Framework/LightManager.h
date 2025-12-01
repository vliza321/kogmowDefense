#ifndef _LIGHTMANAGER_H
#define _LIGHTMANAGER_H

#include "lightclass.h"
#include <vector>
#include <algorithm>

#include "CameraResolver.h"

using namespace std;

class LightManager : public Component
{
public:
	LightManager();
	LightManager(const LightManager&);
	~LightManager();
public:
	virtual bool InitializeSet() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual void Execute() override;
	virtual bool Shutdown() override;
	void PrevRender();
public:
	void SetDirectionalLight(LightClass* light);
	LightClass** GetLights();
	LightClass& GetLights(int);
	LightClass* GetDirectionalLight();
	XMFLOAT4& GetDiffusers();
	XMFLOAT4& GetPositions();
	void SelectLight();
private:
	void InsertionSortInPlace(vector<weak_ptr<LightClass>> lights, size_t start, size_t end);
private:
	CameraResolver* m_cameraResolver;

	LightClass* m_directionalLight;
	LightClass* m_defaultDirectionalLight;
	LightClass* m_lights[8];
	LightClass* m_defaultLight[8];
	vector<weak_ptr<LightClass>> m_allLights;
	int m_frameTimer;	
};

#endif // !_LIGHTMANAGER_H