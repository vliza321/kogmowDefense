#include "LightManager.h"

LightManager::LightManager()
{
	m_allLights.clear();
	m_frameTimer = 0;
}

LightManager::~LightManager()
{

}

bool LightManager::InitializeSet()
{
	XMFLOAT3 PlayerPos = XMFLOAT3(0, 0, 0);
	bool result = true;
	m_directionalLight = new LightClass(
		XMFLOAT3(1.0f, 01.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f),
		128.0f);
	
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f), 
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f), 
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(12.50f * 0.2f, 0.50f, 5.0f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(-48.3f * 0.2f, 0.50f, 52.325f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(-99.0f * 0.2f, 0.50f, 114.50f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(75.00f * 0.2f, 0.50f, -41.5f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(123.10f * 0.2f, 0.50f, -106.750f * 0.2f, 1.0f),
			128.0f)
	);
	for (auto al = m_allLights.begin(); al != m_allLights.end(); al++)
	{
		(*al)->diffuseColor = XMFLOAT4(01.0f, 0.0f, 0.0f, 00.750f);
	}
	
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(173.10f * 0.2f, 0.50f, -166.750f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(223.10f * 0.2f, 0.50f, -236.750f * 0.2f, 1.0f),
			128.0f)
	);
	m_allLights.push_back(
		new LightClass(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
			XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(273.10f * 0.2f, 0.50f, -296.750f * 0.2f, 1.0f),
			128.0f)
	);
	for (auto l = m_allLights.begin(); l != m_allLights.end(); l++)
	{
		float distnace = 0;
		distnace += ((*l)->position.x - PlayerPos.x) * ((*l)->position.x - PlayerPos.x);
		distnace += ((*l)->position.y - PlayerPos.y) * ((*l)->position.y - PlayerPos.y);
		distnace += ((*l)->position.z - PlayerPos.z) * ((*l)->position.z - PlayerPos.z);
		(*l)->distance = distnace;
	}		
	sort(m_allLights.begin(), m_allLights.end(), [](LightClass* a, LightClass* b) {
		return (*a).distance > (*b).distance; }
	);
	int i = 0;
	for (auto l = m_allLights.end() - 8; l != m_allLights.end(); l++)
	{
		m_lights[i] = (*l);
		i++;
	}
	return result;
}

void LightManager::Execute()
{
	XMFLOAT3 PlayerPos = XMFLOAT3(0, 0, 0);
	for (auto l = m_allLights.begin(); l != m_allLights.end(); l++)
	{
		float distnace = 0;
		distnace += ((*l)->position.x - PlayerPos.x) * ((*l)->position.x - PlayerPos.x);
		distnace += ((*l)->position.y - PlayerPos.y) * ((*l)->position.y - PlayerPos.y);
		distnace += ((*l)->position.z - PlayerPos.z) * ((*l)->position.z - PlayerPos.z);
		(*l)->distance = distnace;
	}
	
	if (m_frameTimer > 60)
	{
		m_frameTimer = 0;
		sort(m_allLights.begin(), m_allLights.end(), [](LightClass* a, LightClass* b) {
			return (*a).distance > (*b).distance; }
		);
	}
	
	else
	{
		vector<LightClass*> last16Lights;

		size_t numLightsToCopy = min(m_allLights.size(), size_t(16));

		for (auto l = m_allLights.end() - numLightsToCopy; l != m_allLights.end(); l++)
		{
			last16Lights.push_back(*l);
		}

		InsertionSort(last16Lights);
		copy(last16Lights.begin(), last16Lights.end(), m_allLights.end() - numLightsToCopy);
		m_frameTimer++;
	}
	int i = 0;
	for (auto l = m_allLights.end() - 8; l != m_allLights.end(); l++)
	{
		m_lights[i] = (*l);
		i++;
	}
}

LightClass** LightManager::GetLights()
{
	return m_lights;
}


void LightManager::InsertionSort(vector<LightClass*> lights) {
	for (size_t i = 1; i < lights.size(); ++i) {
		LightClass* key = lights[i];
		int j = i - 1;

		while (j >= 0 && (*lights[j]).distance < (*key).distance) {
			(*lights[j + 1]) = (*lights[j]);
			j--;
		}
		(*lights[j + 1]) = *key;
		key = 0;
	}
}

bool LightManager::Shutdown()
{
	if (m_directionalLight)
	{
		delete m_directionalLight;
		m_directionalLight = 0;
	}

	m_allLights.clear();
	
	return true;
}

LightClass* LightManager::GetDirectionalLight()
{
	return m_directionalLight;
}

LightClass& LightManager::GetLights(int i)
{
	return *m_lights[i];
}

XMFLOAT4& LightManager::GetDiffusers()
{
	XMFLOAT4 DiffuserColor[8];
	int i = 0;
	for (auto& light : m_lights)
	{
		DiffuserColor[i] = light->diffuseColor;
	}
	return *DiffuserColor;
}

XMFLOAT4& LightManager::GetPositions()
{
	XMFLOAT4 Position[8];
	int i = 0;
	for (auto& light : m_lights)
	{
		Position[i] = light->position;
	}
	return *Position;
}