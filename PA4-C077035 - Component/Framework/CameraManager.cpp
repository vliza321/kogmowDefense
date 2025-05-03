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
	m_CameraMapSet[ShootType::Debug] = new BaseCamera();
	return true;
}

bool CameraManager::Initialize()
{
	/*
	if (!m_CameraMapSet[ShootType::Title]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::FPC]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::TPC]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Scope]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Artillery]->Initialize()) return false;
	*/
	if (!m_CameraMapSet[ShootType::Debug]->Initialize()) return false;
	return true;
}

bool CameraManager::InitializeRef()
{
	this->gameObject->AddComponent(m_CameraMapSet[ShootType::Debug]);

	if (!m_CameraMapSet[ShootType::Debug]->InitializeRef()) return false;

	return true;
}

bool CameraManager::InitializeSynchronization()
{
	return true;
}

bool CameraManager::PostInitialize()
{
	return true;
}

void CameraManager::Execute()
{
	m_CameraMapSet[m_CurrentCameraType]->Execute();
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

void CameraManager::SetCameraInfo(Transform& PlayerPos)
{
	m_CameraMapSet[m_CurrentCameraType]->SetCameraInfo(PlayerPos);
}

void CameraManager::SetCamera(ShootType type, const Transform& transform)
{
	if (m_CurrentCameraType == type) return;

	m_CameraMapSet[m_CurrentCameraType]->CameraEnd();
	m_CurrentCameraType = type;
	m_CameraMapSet[m_CurrentCameraType]->CameraStart(transform);
}

XMMATRIX CameraManager::GetViewMatrix()
{
	return  m_CameraMapSet[m_CurrentCameraType]->GetViewMatrix();
}

XMVECTOR CameraManager::GetLookAt()
{
	return m_CameraMapSet[m_CurrentCameraType]->GetLookAt();
}

CameraObject* CameraManager::GetCamera()
{
	return m_CameraMapSet[m_CurrentCameraType];
}