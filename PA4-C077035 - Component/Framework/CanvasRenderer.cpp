#include "CanvasRenderer.h"
#include "CanvasRenderManager.h"
#include "GameScene.h"


CanvasRenderer::CanvasRenderer(const WCHAR* TextureFilename, XMFLOAT4 PanelRect)
	: RenderComponent()
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
	gameObject->Root().GetCanvasRenderManager()->RegisterRenderer(this);
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
	if (m_rectTransform != 0)
	{
		m_rectTransform->Shutdown();
		m_rectTransform.reset();
		m_rectTransform = 0;
	}
	return true;
}

ID3D11ShaderResourceView* CanvasRenderer::GetModelTexture()
{
	return m_model->GetTexture();
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
	return m_model->GetIndexCount();
}

RectTransform* CanvasRenderer::GetRectTransform()
{
	return m_rectTransform.get();
}

