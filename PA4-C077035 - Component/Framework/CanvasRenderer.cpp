#include "CanvasRenderer.h"
#include "CanvasRenderManager.h"


CanvasRenderer::CanvasRenderer(const WCHAR* TextureFilename, XMFLOAT4 PanelRect)
	:Component()
{
	m_model = 0;

	m_modelFileName = L"./data/panel.obj";
	m_textureFileName = TextureFilename;
	m_instanceCounter = 0;

	auto newTransform = std::make_shared<RectTransform>(PanelRect, XMFLOAT2(0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
	m_rectTransform = newTransform;
}

CanvasRenderer::~CanvasRenderer()
{

}

bool CanvasRenderer::InitializeSet()
{
	m_model = new PanelModelClass();
	m_baseModel = new ModelClass();

	auto rect = m_rectTransform;
	if (!rect)
	{
		auto newRectTransform = std::make_shared<RectTransform>();
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

	auto rectTransform = m_rectTransform;
	
	if (!rectTransform) {
		return false;
	}

	result = m_model->InitializeRender(device, m_textureFileName, m_instanceCounter, rectTransform->panelRect);
	result = m_baseModel->InitializeRenderer(device, m_modelFileName, m_textureFileName, 0);
	return result;
}

void CanvasRenderer::Render(ID3D11DeviceContext* DeviceContext)
{
	m_baseModel->Render(DeviceContext);
}

bool CanvasRenderer::Shutdown()
{
	if (m_model != 0)
	{
		m_model->Shutdown();
		delete m_model;
		m_model = 0;
	}
	if (m_baseModel != 0)
	{
		m_baseModel->Shutdown();
		delete m_baseModel;
		m_baseModel = 0;
	}
	return true;
}

ID3D11ShaderResourceView* CanvasRenderer::GetModelTexture()
{
	return m_model->GetTexture();
	//return m_baseModel->GetTexture();
}

PanelModelClass* CanvasRenderer::GetModelData()
{
	return m_model;
}

ModelClass* CanvasRenderer::GetModelData1()
{
	return m_baseModel;
}

int CanvasRenderer::GetModelIndexCount()
{
	return m_model->GetIndexCount();
	//return m_baseModel->GetIndexCount();
}

int CanvasRenderer::GetModelVertexCount()
{
	return m_model->GetIndexCount();
	//return m_baseModel->GetIndexCount();
}

int CanvasRenderer::GetModelInstanceCount()
{
	return m_model->GetIndexCount();
}

RectTransform* CanvasRenderer::GetRectTransform()
{
	return m_rectTransform.get();
}

