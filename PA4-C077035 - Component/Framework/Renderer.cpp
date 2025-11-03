#include "Renderer.h"
#include "Scene.h"
#include "RenderManager.h"

Renderer::Renderer(const WCHAR* ModelFilename, const WCHAR* TextureFilename, int InstanceCoutner)
{
	m_model = 0;

	m_modelFileName = ModelFilename;
	m_textureFileName = TextureFilename;
	m_instanceCounter = InstanceCoutner;
}

Renderer::~Renderer()
{

}

bool Renderer::InitializeSet()
{
	m_model = new ModelClass();
	return true;
}

bool Renderer::InitializeRef()
{
	gameObject->root->GetRenderManager()->RegisterRenderer(this);
	//RenderManager::GetInstance().RegisterRenderer(this);
	return true;
}

bool Renderer::InitializeRender(ID3D11Device* Device)
{
	bool result = true;

	result = m_model->InitializeRenderer(Device, m_modelFileName, m_textureFileName, m_instanceCounter);

	return result;
}

void Renderer::Render(ID3D11DeviceContext* deviceContext)
{
	m_model->Render(deviceContext);
}

bool Renderer::Shutdown()
{
	if (m_model != 0)
	{
		m_model->Shutdown();
		delete m_model;
		m_model = 0;
	}
	return true;
}

ID3D11ShaderResourceView* Renderer::GetModelTexture()
{
	return m_model->GetTexture();
}

ID3D11ShaderResourceView** Renderer::GetModelTextureArray()
{
	return m_model->GetTextureArray();
}

ModelClass* Renderer::GetModelData()
{
	return m_model;
}

int Renderer::GetModelIndexCount()
{
	return m_model->GetIndexCount();
}

int Renderer::GetModelVertexCount()
{
	return m_model->GetIndexCount();
}

int Renderer::GetModelInstanceCount()
{
	return m_model->GetInstanceCount();
}
