#include "CameraResolver.h"
#include "GameScene.h"

CameraResolver::CameraResolver()
{
	m_cameras.clear();
	m_selectedCamera = nullptr;
	m_dummyCamera = nullptr;
}

CameraResolver::~CameraResolver()
{
}

bool CameraResolver::InitializeSet()
{
	m_dummyCamera = new BaseCamera();
	if (!m_dummyCamera) return false;
	m_dummyCamera->Initialize();
	return true;
}

bool CameraResolver::Initialize()
{
	return true;
}

bool CameraResolver::InitializeRef()
{
	vector<shared_ptr<CameraObject>> AllCamera = this->gameObject->root->GetAllComponents<CameraObject>();
	for (auto ac : AllCamera) m_cameras.push_back(ac); 
	return true;
}

bool CameraResolver::InitializeSynchronization()
{
	PrevRender();
	return true;
}

bool CameraResolver::PostInitialize()
{
	return true;
}

void CameraResolver::PostExecute()
{

}

void CameraResolver::PrevRender()
{
	for (int i = m_cameras.size() - 1; i >= 0; i--)
	{
		if (m_cameras[i].expired())
		{
			m_cameras.erase(m_cameras.begin() + i);
		}
	}
	for (int i = m_cameras.size() - 1; i >= 0; i--)
	{
		if (auto cam = m_cameras[i].lock())
		{
			if (cam->active &&
				cam->gameObject->active)
			{
				m_selectedCamera = cam.get();
				break;
			}
		}
	}
	if (m_selectedCamera == nullptr) m_selectedCamera = m_dummyCamera;
}

bool CameraResolver::Shutdown()
{
	if (m_dummyCamera != 0)
	{
		m_dummyCamera->Shutdown();
		delete m_dummyCamera;
		m_dummyCamera = 0;
	}
	m_cameras.clear();
	m_selectedCamera = 0;

	return true;
}

CameraObject* CameraResolver::GetCamera() 
{
	return m_selectedCamera ? m_selectedCamera : m_dummyCamera;
}

XMMATRIX CameraResolver::GetViewMatrix() 
{
	return m_selectedCamera ? m_selectedCamera->GetViewMatrix() : m_dummyCamera->GetViewMatrix();
}

XMVECTOR CameraResolver::GetLookAt() 
{
	return m_selectedCamera ? m_selectedCamera->GetLookAt() : m_dummyCamera->GetLookAt();
}

XMFLOAT3 CameraResolver::GetCameraPosition() 
{
	return m_selectedCamera ? m_selectedCamera->GetPosition() : m_dummyCamera->GetPosition();
}