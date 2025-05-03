#include "CameraManager.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
	m_CurrentCameraType = ShootType::Debug;
}

CameraManager::~CameraManager()
{

}

bool CameraManager::InitializeSet()
{
	/*
	m_CameraMapSet[ShootType::Title] = make_unique<TitleCamera>();
	m_CameraMapSet[ShootType::FPC] = make_unique<FirstPersonCamera>();
	m_CameraMapSet[ShootType::TPC] = make_unique<ThirdPersonCamera>();
	m_CameraMapSet[ShootType::Scope] = make_unique<ScopeCamera>();
	m_CameraMapSet[ShootType::Artillery] = make_unique<ArtilleryCamera>();
	*/
	m_CameraMapSet[ShootType::Debug] = make_unique<BaseCamera>();
	return true;
}

bool CameraManager::Initialize()
{
	/*
	if (!m_CameraMapSet[ShootType::Title].get()->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::FPC].get()->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::TPC].get()->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Scope].get()->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Artillery].get()->Initialize()) return false;
	*/
	if (!m_CameraMapSet[ShootType::Debug].get()->Initialize()) return false;
	return true;
}

bool CameraManager::InitializeRef()
{
	return false;
}

bool CameraManager::InitializeSynchronization()
{
	return false;
}

bool CameraManager::PostInitialize()
{
	return false;
}

void CameraManager::Execute()
{
	m_CameraMapSet[m_CurrentCameraType].get()->Execute();
}

bool CameraManager::Shutdown()
{
	/*
	m_CameraMapSet[ShootType::Title]->Shutdown();
	m_CameraMapSet[ShootType::FPC]->Shutdown();
	m_CameraMapSet[ShootType::TPC]->Shutdown();
	m_CameraMapSet[ShootType::Scope]->Shutdown();
	m_CameraMapSet[ShootType::Artillery]->Shutdown();
	*/
	m_CameraMapSet[ShootType::Debug]->Shutdown();
	return true;
}

void CameraManager::SetCameraInfo(Transform PlayerPos)
{
	m_CameraMapSet[m_CurrentCameraType].get()->SetCameraInfo(PlayerPos);
}

void CameraManager::SetCamera(ShootType type, Transform transform)
{
	if (m_CurrentCameraType == type) return;

	m_CameraMapSet[m_CurrentCameraType].get()->CameraEnd();
	m_CurrentCameraType = type;
	m_CameraMapSet[m_CurrentCameraType].get()->CameraStart(transform);
}

XMMATRIX CameraManager::GetViewMatrix()
{
	return  m_CameraMapSet[m_CurrentCameraType].get()->GetViewMatrix();
}

XMVECTOR CameraManager::GetLookAt()
{
	return m_CameraMapSet[m_CurrentCameraType].get()->GetLookAt();
}

CameraObject* CameraManager::GetCamera()
{
	return m_CameraMapSet[m_CurrentCameraType].get();
}