#include "LightManager.h"
#include "GameScene.h"

LightManager::LightManager()
{
	m_allLights.clear();
	m_frameTimer = 0;
	m_directionalLight = 0;
	m_defaultDirectionalLight = 0;
}

LightManager::LightManager(const LightManager& other)
{
	m_allLights.clear();
	m_frameTimer = 0;

	m_directionalLight = 0;
	m_defaultDirectionalLight = 0;
}

LightManager::~LightManager()
{
	
}

bool LightManager::InitializeSet()
{
	XMFLOAT3 PlayerPos = XMFLOAT3(0, 0, 0);
	bool result = true;
	for (int i = 0; i < 8; i++)
	{
		m_defaultLight[i] = new LightClass();
	}
	m_defaultDirectionalLight = new LightClass();
	m_allLights.clear();
	return result;
}

bool LightManager::InitializeRef()
{
	bool result = true;
	m_cameraResolver = this->gameObject->root->GetCameraresolver();
	auto DL = FindObjectWithTag(Tag::DirectionalLight);
	if (DL != nullptr)
	{
		auto DLC = DL->GetComponent<LightClass>();
		if (DLC != nullptr) m_directionalLight = DLC.get();
	}
	vector<shared_ptr<LightClass>> allLight = this->gameObject->root->GetAllComponents<LightClass>();
	for (auto& al : allLight)
	{
		if(!al->gameObject->CompareTag(Tag::DirectionalLight)) m_allLights.push_back(al);
	}
	return result;
}

bool LightManager::InitializeSynchronization()
{
	auto cm = m_cameraResolver;
	XMFLOAT3 targetPos = cm->GetCamera()->GetPosition();

	for (int i = m_allLights.size() - 1; i >= 0; i--)
	{
		if (auto light = m_allLights[i].lock())
		{
			XMVECTOR tpv = XMLoadFloat3(&targetPos) - XMLoadFloat4(&(light->position));
			light->distance = XMVectorGetX(XMVector3LengthSq(tpv));
		}
	}
	for (int i = m_allLights.size() - 1; i >= 0; --i)
	{
		if (m_allLights[i].expired())
		{
			m_allLights.erase(m_allLights.begin() + i);
		}
	}
	sort(m_allLights.begin(), m_allLights.end(), [](weak_ptr<LightClass> a, weak_ptr<LightClass> b) {
		return a.lock()->distance > b.lock()->distance; }
	);
	SelectLight();
	return true;
}

//버전2. 카메라 앞에 있는 라이트를 거리 계산
void LightManager::Execute()
{
	auto cm = m_cameraResolver;
	XMFLOAT3 targetPos = cm->GetCamera()->GetPosition();
	XMVECTOR vCamPos = XMLoadFloat3(&targetPos);
	XMVECTOR vCamForward = XMVector3Normalize( cm->GetCamera()->GetLookAt() - vCamPos);

	for (int i = m_allLights.size() - 1; i >= 0; i--)
	{
		if (auto light = m_allLights[i].lock())
		{
			XMVECTOR vLight = XMLoadFloat4(&(light->position));
			XMVECTOR diff = vLight - vCamPos;

			light->distance = XMVectorGetX(XMVector3LengthSq(diff));

			// 내적 계산
			float dot = XMVectorGetX(XMVector3Dot(diff, vCamForward));
			
			light->distance /= dot;
		}
	}

	auto mid = stable_partition(m_allLights.begin(), m_allLights.end(),
		[](const auto& pl) { return pl.lock()->distance < 0.0f; });

	sort(mid, m_allLights.end(),
		[](const auto& a, const auto& b) {
			return a.lock()->distance > b.lock()->distance;
		}
	);
}

//버전1. 단순 거리 기반 계산
/*

void LightManager::Execute()
{
	// CameraManager의 현재 카메라 포지션을 가져옴
	auto cm = m_cameraResolver;
	XMFLOAT3 targetPos = cm->GetCamera()->GetPosition();

	// 모든 라이트의 거리(distance) 값을 업데이트
	for (int i = m_allLights.size() - 1; i >= 0; i--)
	{
		if (auto light = m_allLights[i].lock())
		{
			XMVECTOR tpv = XMLoadFloat3(&targetPos) - XMLoadFloat4(&(light->position));
			light->distance = XMVectorGetX(XMVector3LengthSq(tpv));
		}
	}
	for (int i = m_allLights.size() - 1; i >= 0; --i)
	{
		if (m_allLights[i].expired())
		{
			m_allLights.erase(m_allLights.begin() + i);
		}
	}

	if (m_allLights.size() > 8)
	{
		// 60프레임마다 전체 라이트를 정렬
		if (m_frameTimer > 60)
		{
			m_frameTimer = 0;

			// 전체 라이트를 distance 값 기준으로 내림차순 정렬
			sort(m_allLights.begin(), m_allLights.end(), 
				[](weak_ptr<LightClass> a, weak_ptr<LightClass> b) {
				return a.lock()->distance > b.lock()->distance; }
			);
		}
		else
		{
			size_t numLights = m_allLights.size();
			size_t sortStart = (numLights < 16) ? 0 : numLights - 16;

			// 마지막 16개만 삽입 정렬
			InsertionSortInPlace(m_allLights, sortStart, numLights);
			m_frameTimer++;
		}
	}
}*/

void LightManager::SetDirectionalLight(LightClass* light)
{
	m_directionalLight = light;
}

LightClass** LightManager::GetLights()
{
	return m_lights;
}

void LightManager::InsertionSortInPlace(vector<weak_ptr<LightClass>> lights, size_t start, size_t end)
{
	auto beginIt = lights.begin() + start;
	auto endIt = lights.begin() + end;
	
	for (auto it = beginIt + 1; it != endIt; ++it) {
		LightClass* key = it->lock().get();
		auto j = it;

		while (j != beginIt && (j - 1)->lock().get()->distance < key->distance) {
			*j = *(j - 1);
			j--;
		}
		j = it;
	}
}

bool LightManager::Shutdown()
{
	if (m_directionalLight)
	{
		m_directionalLight->Shutdown();
		delete m_directionalLight;
		m_directionalLight = 0;
	}

	if (m_defaultDirectionalLight)
	{
		m_defaultDirectionalLight->Shutdown();
		delete m_defaultDirectionalLight;
		m_defaultDirectionalLight = 0;
	}

	m_allLights.clear();

	for (int i = 7; i >= 0; --i)
	{
		m_lights[i]->Shutdown();
		delete m_lights[i];
		m_lights[i] = nullptr;

		m_defaultLight[i]->Shutdown();
		delete m_defaultLight[i];
		m_lights[i] = nullptr;
	}
	
	m_cameraResolver = 0;

	return true;
}

void LightManager::PrevRender()
{
	SelectLight();
}

LightClass* LightManager::GetDirectionalLight()
{
	if (!m_directionalLight) return m_defaultDirectionalLight;
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

void LightManager::SelectLight()
{
	int i = 0;
	for (int j = m_allLights.size() - 1; j >=0; j--)
	{
		if (m_allLights[j].lock().get()->active)
		{
			m_lights[i] = m_allLights[j].lock().get();
			i++;
		}
		if (i >= 8) break;
	}
	for (i; i < 8; i++)
	{
		m_lights[i] = m_defaultLight[i];
	}
}