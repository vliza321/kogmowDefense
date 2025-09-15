#include "GUIRenderer.h"
#include "GUIRenderManager.h"
#include "ObjectClass.h"

GUIRenderer::GUIRenderer(const WCHAR* TextureFilename, int InstanceCoutner)
	:Component()
{
	m_model = 0;

	m_modelFileName = L"./data/Plane.obj";
	m_textureFileName = TextureFilename;
	m_instanceCounter = InstanceCoutner;
}

GUIRenderer::~GUIRenderer()
{
}

bool GUIRenderer::InitializeSet()
{
	m_model = new PanelModelClass();
	return true;
}

bool GUIRenderer::InitializeRef()
{
	GUIRenderManager::GetInstance().RegisterRenderer(this);

	m_rectTransform = this->gameObject->GetComponent<RectTransform>();
	m_transform = this->gameObject->GetComponent<Transform>();
	auto rect = m_rectTransform.lock();
	if (!rect)
	{
		auto newRectTransform = std::make_shared<RectTransform>();
		this->gameObject->AddComponent(newRectTransform);
		m_rectTransform = newRectTransform;
	}
	auto tf = m_rectTransform.lock();
	if (!tf)
	{
		auto newTransform = std::make_shared<Transform>();
		this->gameObject->AddComponent(newTransform);
		m_transform = newTransform;
	}
	m_cameraManager = gameObject->Root().Find("CameraManager")->GetComponent<CameraManager>();
	return true;
}


bool GUIRenderer::InitializeRender(ID3D11Device* Device)
{
	bool result = true;

	auto rectTransform = m_rectTransform.lock();
	if (!rectTransform) {
		std::cerr << "RectTransform no longer exists!\n";
		return false;
	}

	result = m_model->InitializeRender(Device, m_textureFileName, m_instanceCounter, rectTransform->panelRect);

	return result;
}

void GUIRenderer::Render(ID3D11DeviceContext* DeviceContext)
{
	m_model->Render(DeviceContext);
}

bool GUIRenderer::Shutdown()
{
	if (m_model != 0)
	{
		m_model->Shutdown();
		delete m_model;
		m_model = 0;
	}
	return true;
}

ID3D11ShaderResourceView* GUIRenderer::GetModelTexture()
{
	return m_model->GetTexture();
}

PanelModelClass* GUIRenderer::GetModelData()
{
	return m_model;
}

int GUIRenderer::GetModelIndexCount()
{
	return  m_model->GetIndexCount();
}

int GUIRenderer::GetModelVertexCount()
{
	return  m_model->GetIndexCount();
}

int GUIRenderer::GetModelInstanceCount()
{
	return m_instanceCounter;
}

void GUIRenderer::PostExecute()
{
	auto MainCamera = m_cameraManager.lock().get()->GetCamera()->GetPosition();
	auto CameraLookAt = m_cameraManager.lock()->GetLookAt();
	auto tf = m_transform.lock();

	XMVECTOR Camera = XMVector3Normalize(XMVectorSet(MainCamera.x - XMVectorGetX(CameraLookAt), MainCamera.y - XMVectorGetY(CameraLookAt), MainCamera.z - XMVectorGetZ(CameraLookAt), 1));

	double angle = atan2(XMVectorGetX(Camera), XMVectorGetZ(Camera));

	float delta = angle - tf->eulerRotation.z;

	// ¹üÀ§¸¦ -¥ð ~ +¥ð ·Î ¸ÂÃçÁÜ
	if (delta > XM_PI)  angle -= XM_2PI;
	if (delta < -XM_PI) angle += XM_2PI;

	if (MainCamera.y - tf->position.y > 5)
	{
		tf->eulerRotation.x = XM_PIDIV2;
	}
	else
	{
		tf->eulerRotation.x = 0;
		tf->eulerRotation.y = angle + XM_PI;
	}
}
