#include "CameraManager.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
	m_currentCameraType = ShootType::FPC;
}

CameraManager::~CameraManager()
{

}

bool CameraManager::InitializeSet()
{
	m_cameraMapSet.clear();
	return true;
}

bool CameraManager::Initialize()
{
	return true;
}

bool CameraManager::InitializeRef()
{
	auto tpc = GetComponent<ThirdPersonCamera>().get();
	if (tpc)
	{
		m_cameraMapSet[ShootType::TPC] = tpc;
	}

	auto fpc = GetComponent<FirstPersonCamera>().get();
	if (fpc)
	{
		m_cameraMapSet[ShootType::FPC] = fpc;
	}

	auto sc = GetComponent<ScopeCamera>().get();
	if (sc)
	{
		m_cameraMapSet[ShootType::Scope] = sc;
	}

	auto ac = GetComponent<ArtilleryCamera>().get();
	if (ac)
	{
		m_cameraMapSet[ShootType::Artillery] = ac;
	}
	return true;
}

bool CameraManager::InitializeSynchronization()
{
	for (auto cms : m_cameraMapSet)
	{
		cms.second->active = false;
	}
	return true;
}

bool CameraManager::PostInitialize()
{
	SetCamera(ShootType::TPC);
	return true;
}

void CameraManager::Execute()
{
	m_cameraMapSet[m_currentCameraType]->Execute();
}

bool CameraManager::Shutdown()
{
	for (auto cms : m_cameraMapSet)
	{
		cms.second->Shutdown();
	}
	m_cameraMapSet.clear();
	return true;
}

void CameraManager::SetCamera(ShootType type)
{
	if (m_currentCameraType == type) return;

	if (m_cameraMapSet[m_currentCameraType] != nullptr)
	{
		m_cameraMapSet[m_currentCameraType]->CameraEnd();
		m_cameraMapSet[m_currentCameraType]->active = false;
	}
	m_currentCameraType = type;
	if (m_cameraMapSet[m_currentCameraType] != nullptr)
	{
		m_cameraMapSet[m_currentCameraType]->CameraStart();
		m_cameraMapSet[m_currentCameraType]->active = true;
	}
}

XMMATRIX CameraManager::GetViewMatrix()
{
	return  m_cameraMapSet[m_currentCameraType]->GetViewMatrix();
}

XMVECTOR CameraManager::GetLookAt()
{
	return m_cameraMapSet[m_currentCameraType]->GetLookAt();
}

CameraObject* CameraManager::GetCamera()
{
	return m_cameraMapSet[m_currentCameraType];
}
