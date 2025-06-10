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
	m_CameraMapSet[ShootType::Debug] = new BaseCamera();
	m_CameraMapSet[ShootType::TPC] = new ThirdPersonCamera();
	m_CameraMapSet[ShootType::FPC] = new FirstPersonCamera();
	m_CameraMapSet[ShootType::Scope] = new ScopeCamera();
	m_CameraMapSet[ShootType::Artillery] = new ArtilleryCamera();

	m_CameraMapSet[ShootType::Debug]->gameObject = this->gameObject;
	m_CameraMapSet[ShootType::TPC]->gameObject = this->gameObject;
	m_CameraMapSet[ShootType::FPC]->gameObject = this->gameObject;
	m_CameraMapSet[ShootType::Scope]->gameObject = this->gameObject;
	m_CameraMapSet[ShootType::Artillery]->gameObject = this->gameObject;
	return true;
}

bool CameraManager::Initialize()
{
	if (!m_CameraMapSet[ShootType::Debug]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::TPC]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::FPC]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Scope]->Initialize()) return false;
	if (!m_CameraMapSet[ShootType::Artillery]->Initialize()) return false;
	return true;
}

bool CameraManager::InitializeRef()
{
	if (!m_CameraMapSet[ShootType::Debug]->InitializeRef()) return false;
	if (!m_CameraMapSet[ShootType::TPC]->InitializeRef()) return false;
	if (!m_CameraMapSet[ShootType::FPC]->InitializeRef()) return false;
	if (!m_CameraMapSet[ShootType::Scope]->InitializeRef()) return false;
	if (!m_CameraMapSet[ShootType::Artillery]->InitializeRef()) return false;
	if (!m_CameraMapSet[ShootType::Artillery]->InitializeRef()) return false;

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
	m_CameraMapSet[ShootType::TPC]->Shutdown();
	m_CameraMapSet[ShootType::FPC]->Shutdown();
	m_CameraMapSet[ShootType::Scope]->Shutdown();
	m_CameraMapSet[ShootType::Artillery]->Shutdown();
	m_CameraMapSet[ShootType::Debug]->Shutdown();
	return true;
}

void CameraManager::SetCameraInfo()
{
	m_CameraMapSet[m_CurrentCameraType]->SetCameraInfo();
}

void CameraManager::SetCamera(ShootType type)
{
	if (m_CurrentCameraType == type) return;

	m_CameraMapSet[m_CurrentCameraType]->CameraEnd();
	m_CurrentCameraType = type;
	m_CameraMapSet[m_CurrentCameraType]->CameraStart();
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