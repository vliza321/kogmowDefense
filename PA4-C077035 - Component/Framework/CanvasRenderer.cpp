#include "CanvasRenderer.h"
#include "CanvasRenderManager.h"


CanvasRenderer::CanvasRenderer(const WCHAR* TextureFilename, int InstanceCoutner)
	:Component()
{
	m_model = 0;

	m_modelFileName = L"./data/Plane.obj";
	m_textureFileName = TextureFilename;
	m_instanceCounter = InstanceCoutner;
}

CanvasRenderer::~CanvasRenderer()
{

}

bool CanvasRenderer::InitializeSet()
{
	m_model = new PanelModelClass();
	m_rectTransform = this->gameObject->GetComponent<RectTransform>();
	auto rect = m_rectTransform.lock();
	if (!rect)
	{
		auto newRectTransform = std::make_shared<RectTransform>();
		this->gameObject->AddComponent(newRectTransform);
		m_rectTransform = newRectTransform;
	}
	return true;
}

bool CanvasRenderer::InitializeRef()
{
	CanvasRenderManager::GetInstance().RegisterRenderer(this);
	return true;
}

bool CanvasRenderer::InitializeRender(ID3D11Device* device)
{
	bool result = true;

	auto rectTransform = m_rectTransform.lock();
	if (!rectTransform) {
		std::cerr << "RectTransform no longer exists!\n";
		return false;
	}

	result = m_model->InitializeRender(device, m_textureFileName, m_instanceCounter, rectTransform->panelRect);

	return result;
}

void CanvasRenderer::Render(ID3D11DeviceContext* DeviceContext)
{
	m_model->Render(DeviceContext);
}

bool CanvasRenderer::Shutdown()
{
	if (m_model != 0)
	{
		m_model->Shutdown();
		delete m_model;
		m_model = 0;
	}
	return true;
}

ID3D11ShaderResourceView* CanvasRenderer::GetModelTexture()
{
	return m_model->GetTexture();
}

PanelModelClass* CanvasRenderer::GetModelData()
{
	return m_model;
}

int CanvasRenderer::GetModelIndexCount()
{
	return m_model->GetIndexCount();
}

int CanvasRenderer::GetModelVertexCount()
{
	return m_model->GetIndexCount();
}

int CanvasRenderer::GetModelInstanceCount()
{
	return m_instanceCounter;
}

