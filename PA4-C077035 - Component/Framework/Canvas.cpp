#include "Canvas.h"

Canvas::Canvas()
{
	m_UI.clear();

	m_Title = 0;
	m_NormalSightUI = 0;
	m_ScopeSightUI = 0;
	m_ArtillerySightUI = 0;
}

Canvas::~Canvas()
{

}

bool Canvas::Initialize(HWND hwnd, ID3D11Device* device)
{
	bool result = false;
	m_Title = new ImageUI(XMFLOAT4(800, -450, -800, 450), XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), L"./data/Panel.obj", L"./data/title.dds", 0);

	m_NormalSightUI = new ImageUI(XMFLOAT4(800, -450, -800, 450),
		XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0),
		L"./data/Panel.obj", L"./data/TempNormalLineOfSight.dds", 0);
	m_ScopeSightUI = new ImageUI(XMFLOAT4(800, -450, -800, 450),
		XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0),
		L"./data/Panel.obj", L"./data/TempScopeLineOfSight.dds", 0);
	m_ArtillerySightUI = new ImageUI(XMFLOAT4(800, -450, -800, 450),
		XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0),
		L"./data/Panel.obj", L"./data/TempArtilleryLineOfSight.dds", 0);

	m_UI.push_back(m_Title);
	m_UI.push_back(m_NormalSightUI);
	m_UI.push_back(m_ScopeSightUI);
	m_UI.push_back(m_ArtillerySightUI);

	for (auto ui = m_UI.begin(); ui != m_UI.end(); ui++)
	{
		result = (*ui)->Initialize(device);
		if (!result)
		{
			MessageBox(hwnd, L"Could not initialize UI.", L"Error", MB_OK);
			return false;
		}
	}

	m_UI.clear();

	return result;
}

bool Canvas::UIRender(TextureShaderClass* shader, D3DClass* d3d, ID3D11DeviceContext* deviceContext, XMFLOAT3 camerapos,
	XMMATRIX rMatrix, XMMATRIX wMatrix, XMMATRIX vMatrix, XMMATRIX pMatrix, int SceneCount, ShootType shootType)
{
	XMMATRIX rotationMatrix = rMatrix, worldMatrix = wMatrix, viewMatrix = vMatrix, projectionMatrix = pMatrix;
	bool result = true;

	XMVECTOR position = XMVectorSet(0.0f, 0.0f, 10.0f, 0.0f);
	XMVECTOR lookAt = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR up = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

	//viewMatrix »ý¼º
	viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

	d3d->GetWorldMatrix(worldMatrix);
	// Turn off the Z buffer to begin all 2D rendering.
	d3d->TurnZBufferOff();
	for (auto ui = m_UI.begin(); ui != m_UI.end(); ui++)
	{
		if ((*ui)->GetActive())
		{
			(*ui)->Render(deviceContext);
			result = shader->Render(deviceContext, (*ui)->GetModelIndexCount(), (*ui)->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, (*ui)->GetModelTexture());
		}
	}
	switch (shootType)
	{
	case ShootType::Title:
		m_Title->Render(deviceContext);
		result = shader->Render(deviceContext, m_Title->GetModelIndexCount(), m_Title->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_Title->GetModelTexture());
		break;
	case ShootType::FPC:
		m_NormalSightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_NormalSightUI->GetModelIndexCount(), m_NormalSightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_NormalSightUI->GetModelTexture());
		break;
	case ShootType::TPC:
		m_NormalSightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_NormalSightUI->GetModelIndexCount(), m_NormalSightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_NormalSightUI->GetModelTexture()); break;
	case ShootType::Scope:
		m_NormalSightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_NormalSightUI->GetModelIndexCount(), m_NormalSightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_NormalSightUI->GetModelTexture()); 
		m_ScopeSightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_ScopeSightUI->GetModelIndexCount(), m_ScopeSightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_ScopeSightUI->GetModelTexture());
		break;
	case ShootType::Artillery:
		m_NormalSightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_NormalSightUI->GetModelIndexCount(), m_NormalSightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_NormalSightUI->GetModelTexture());
		m_ArtillerySightUI->Render(deviceContext);
		result = shader->Render(deviceContext, m_ArtillerySightUI->GetModelIndexCount(), m_ArtillerySightUI->GetModelInstanceCount(), rotationMatrix, worldMatrix, viewMatrix, projectionMatrix, m_ArtillerySightUI->GetModelTexture());
		break;
	case ShootType::Num:
		break;
	default:
		break;
	}

	d3d->TurnZBufferOn();
	return result;
}

void Canvas::Shutdown()
{
	if (m_Title)
	{
		delete m_Title;
		m_Title = 0;
	}

	m_UI.clear();
}

void Canvas::SetScene(int SceneCounter)
{
	switch (SceneCounter)
	{
	case 0:
		m_Title->SetActive(true);
		break;
	case 1:
		m_Title->SetActive(false);
		break;
	}
}

void Canvas::Execute(XMFLOAT3, int)
{
}

void Canvas::LateExecute()
{
}
