#include "GUIRenderer.h"
#include "GUIRenderManager.h"

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
	m_rectTransform = this->gameObject->GetComponentIncludingBase<RectTransform>();
	auto rect = m_rectTransform.lock();
	if (!rect)
	{
		auto newRectTransform = std::make_shared<RectTransform>();
		this->gameObject->AddComponent(newRectTransform);
		m_rectTransform = newRectTransform;
	}
	return true;
}

bool GUIRenderer::InitializeRef()
{
	GUIRenderManager::GetInstance().RegisterRenderer(this);
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
