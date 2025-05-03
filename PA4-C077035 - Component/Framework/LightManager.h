#pragma once
#include "lightclass.h"
#include <vector>
#include <algorithm>

using namespace std;

class LightManager : public Component
{
public:
	LightManager();
	~LightManager();
	virtual bool InitializeSet() override;
	virtual void Execute() override;
	virtual bool Shutdown() override;
	LightClass** GetLights();
	LightClass& GetLights(int);
	LightClass* GetDirectionalLight();
	XMFLOAT4& GetDiffusers();
	XMFLOAT4& GetPositions();
private:
	void InsertionSort(vector<LightClass*>);
private:
	LightClass* m_directionalLight;
	LightClass* m_lights[8];
	vector<LightClass*> m_allLights;
	int m_frameTimer;	
};

