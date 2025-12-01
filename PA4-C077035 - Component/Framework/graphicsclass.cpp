////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"
#include <string>

GraphicsClass::GraphicsClass()
{
	m_Input = 0;
	m_sceneConverter = 0;

	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_Input = &InputClass::GetInstance();
	if (!m_Input)
	{
		return false;
	}

	m_d3d = new D3DClass();
	if (!m_d3d)
	{
		return false;
	}

	result = m_d3d->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not Scene initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	m_textureShader = new TextureShaderClass;
	if (!m_textureShader)
	{
		return false;
	}

	result = m_textureShader->Initialize(m_d3d->GetDevice(), hwnd);
	if (!result)
	{

		MessageBox(hwnd, L"Could not Scene initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}

	m_lightShader = new LightShaderClass;
	if (!m_lightShader)
	{
		return false;
	}

	result = m_lightShader->Initialize(m_d3d->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not Scene initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	
	m_sceneConverter = &SceneManager::GetInstance();
	result = m_sceneConverter->Initialize(
		screenWidth, screenHeight, hwnd,
		m_d3d, m_lightShader,m_textureShader);
	if (!result)
	{
		MessageBox(
			hwnd, 
			L"Could not initialize the SceneManager object.",
			L"Error",
			MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	if (m_d3d)
	{
		m_d3d->Shutdown();
		delete m_d3d;
		m_d3d = 0;
	}
	if (m_lightShader)
	{
		m_lightShader->Shutdown();
		delete m_lightShader;
		m_lightShader = 0;
	}
	if (m_textureShader)
	{
		m_textureShader->Shutdown();
		delete m_textureShader;
		m_textureShader = 0;
	}

	return;
}


bool GraphicsClass::Frame()
{
	bool result = true;

	TimerClass::GetInstance().Execute();

	m_sceneConverter->SceneChange();
	m_sceneConverter->FixedExecute();
	m_sceneConverter->CollisionDetection();
	m_sceneConverter->Execute();
	m_sceneConverter->LateExecute();
	m_sceneConverter->PostExecute();

	result = Render();
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::Render()
{
	bool result = true;
	
	m_sceneConverter->PrevRender();

	// Clear the buffers to begin the scene.
	m_d3d->BeginScene(0.0f, 0.0f, 0.0f, 0.0f);

	m_d3d->TurnZBufferOn();
	m_d3d->TurnOffAlphaBlending();
	m_d3d->TurnOnCullBackMode();

	result = m_sceneConverter->LightRender();
	result = m_sceneConverter->Render();
	if (!result)
	{
		return false;
	}

	m_d3d->TurnOnAlphaBlending();
	m_d3d->TurnOnCullNoneMode();

	result = m_sceneConverter->WorldSpaceUIRender();
	if (!result)
	{
		return false;
	}

	m_d3d->TurnZBufferOff();
	m_d3d->TurnOnCullNoneMode();

	result = m_sceneConverter->UIRender();
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_d3d->EndScene();

	return true;
}