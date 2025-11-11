#include "LightManager.h"
#include "GameObject.h"
#include "Scene.h"

LightManager::LightManager()
{
	m_allLights.clear();
	m_frameTimer = 0;
}

LightManager::LightManager(const LightManager& other)
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
	return result;
}

bool LightManager::InitializeRef()
{
	bool result = true;
	m_cameraManager = this->gameObject->Root().Find("CameraManager")->GetComponentIncludingBase<CameraManager>();
	return result;
}

bool LightManager::InitializeSynchronization()
{
	auto cm = m_cameraManager.lock();
	XMFLOAT3 targetPos = cm->GetCamera()->GetPosition();

	for (auto l = m_allLights.begin(); l != m_allLights.end(); l++)
	{
		XMVECTOR tpv = XMLoadFloat3(&targetPos) - XMLoadFloat4(&((*l)->position));
		float distnace = XMVectorGetX(XMVector3Dot(tpv, tpv));
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
	return true;
}

void LightManager::Execute()
{
	// CameraManager의 현재 카메라 포지션을 가져옴
	auto cm = m_cameraManager.lock();
	XMFLOAT3 targetPos = cm->GetCamera()->GetPosition();

	// 모든 라이트의 거리(distance) 값을 업데이트
	for (auto& light : m_allLights)
	{
		XMVECTOR targetToLight = XMLoadFloat3(&targetPos) - XMLoadFloat4(&light->position);
		light->distance = XMVectorGetX(XMVector3LengthSq(targetToLight));
	}

	if (m_allLights.size() < 8) return;

	// 60프레임마다 전체 라이트를 정렬
	if (m_frameTimer > 60)
	{
		m_frameTimer = 0;

		// 전체 라이트를 distance 값 기준으로 내림차순 정렬
		sort(m_allLights.begin(), m_allLights.end(), [](LightClass* a, LightClass* b) {
			return a->distance > b->distance;
			});
	}
	else
	{
		size_t numLights = m_allLights.size();
		size_t sortStart = (numLights < 16) ? 0 : numLights - 16;

		// 마지막 16개만 삽입 정렬
		InsertionSortInPlace(m_allLights, sortStart, numLights);
		m_frameTimer++;
	}

	// 상위 8개의 라이트를 m_lights 배열에 저장
	int i = 0;
	for (auto it = m_allLights.end() - 8; it != m_allLights.end(); ++it) {
		m_lights[i++] = *it;
	}
}

void LightManager::SetDirectionalLight(LightClass* light)
{
	m_directionalLight = light;
}

void LightManager::AddLight(LightClass* light)
{
	m_allLights.push_back(light);
}

LightClass** LightManager::GetLights()
{
	return m_lights;
}


void LightManager::InsertionSort(vector<LightClass*> lights) 
{
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

void LightManager::InsertionSortInPlace(vector<LightClass*>& lights, size_t start, size_t end)
{
	auto beginIt = lights.begin() + start;
	auto endIt = lights.begin() + end;
	
	for (auto it = beginIt + 1; it != endIt; ++it) {
		LightClass* key = *it;
		auto j = it;

		while (j != beginIt && (*(j - 1))->distance < key->distance) {
			*j = *(j - 1);
			j--;
		}
		*j = key;
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

	for (int i = 7; i >= 0; --i)
	{
		m_lights[i]->Shutdown();
		delete m_lights[i];
		m_lights[i] = nullptr;
	}
	
	m_cameraManager.reset();

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