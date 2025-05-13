#pragma once
#include "lightclass.h"
#include <vector>
#include <algorithm>

#include "CameraManager.h"

using namespace std;

class LightManager : public Component
{
public:
	LightManager();
	~LightManager();
	virtual bool InitializeSet() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual void Execute() override;
	virtual bool Shutdown() override;

public:
	LightClass** GetLights();
	LightClass& GetLights(int);
	LightClass* GetDirectionalLight();
	XMFLOAT4& GetDiffusers();
	XMFLOAT4& GetPositions();
private:
	void InsertionSort(vector<LightClass*>);
	void InsertionSortInPlace(vector<LightClass*>& lights, size_t start, size_t end);
private:
	std::weak_ptr<CameraManager> m_cameraManager;
	LightClass* m_directionalLight;
	LightClass* m_lights[8];
	vector<LightClass*> m_allLights;
	int m_frameTimer;	
};

