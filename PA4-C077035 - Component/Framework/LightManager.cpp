#include "LightManager.h"
#include "GameObject.h"
#include "ObjectClass.h"

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