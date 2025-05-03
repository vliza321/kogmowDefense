#include "CanvasObject.h"
#include "algorithm"


CanvasObject::CanvasObject()
{
	//objs.clear();
	//pendingObjs.clear();
	m_panelModel = 0;
	m_modelFileName = L"./data/Panel.obj";

	isActive = true;
	timer = 0;
}

CanvasObject::CanvasObject(XMFLOAT4 panelRect, XMFLOAT2 position, XMFLOAT3 rotation, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
{
	transform.panelRect = panelRect;
	transform.position = position;
	transform.rotation = rotation;
	m_InstanceCounter = instanceCounter;

	m_TextureFileName = textureFilename;
	m_modelFileName = L"./data/Panel.obj";
	m_panelModel = 0;

	isActive = true;
	timer = 0;
	
}

CanvasObject::~CanvasObject()
{

}

void CanvasObject::SetActive(bool Active)
{
	isActive = Active;
}

bool CanvasObject::GetActive()
{
	return isActive;
}

void CanvasObject::Execute(XMFLOAT3 pos)
{

}


void CanvasObject::LateExecute(XMFLOAT3 pos)
{

}


void CanvasObject::Render(ID3D11DeviceContext* deviceContext)
{
	if (isActive)
	{
		m_panelModel->Render(deviceContext);
	}
}


ID3D11ShaderResourceView* CanvasObject::GetModelTexture()
{
	return m_panelModel->GetTexture();
}


void CanvasObject::Translate(XMFLOAT3 p)
{
	transform.position.x += p.x;
	transform.position.y += p.y;
}

PanelModelClass* CanvasObject::GetModelData()
{
	return m_panelModel;
}

int CanvasObject::GetModelIndexCount()
{
	return m_panelModel->GetIndexCount();
}

int CanvasObject::GetModelVertexCount()
{
	return m_panelModel->GetIndexCount();
}

int CanvasObject::GetModelInstanceCount()
{
	return m_panelModel->GetInstanceCount();
}