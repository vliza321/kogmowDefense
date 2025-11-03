////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"
#include <string>

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Input = 0;
	m_TextureShader = 0;
	m_sceneManager = 0;

	m_LightShader = 0;
	SceneCount = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd, InputClass* input,int SceneCount)
{
	bool result;

	this->SceneCount = SceneCount;

	m_Input = input;
	if (!m_Input)
	{
		return false;
	}

	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		return false;
	}
	result = m_sceneManager->Initialize(hwnd, );
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the SceneManager object.", L"Error", MB_OK);
		return false;
	}

	m_TextureShader = new TextureShaderClass;
	if(!m_TextureShader)
	{
		return false;
	}
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if(!result)
	{

		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}

	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}
	m_sceneManager->CreateBaseObject();
	m_sceneManager->CreateGameObject();

	m_sceneManager->InitializeSet(hwnd, m_D3D->GetDevice());
	m_sceneManager->Initialize(hwnd, m_D3D->GetDevice());
	m_sceneManager->InitializeRef(hwnd, m_D3D->GetDevice());
	m_sceneManager->InitializeRender(hwnd, m_D3D->GetDevice());
	m_sceneManager->InitializeSynchronization(hwnd, m_D3D->GetDevice());
	m_sceneManager->PostInitialize(hwnd, m_D3D->GetDevice());
	return true;
}


void GraphicsClass::Shutdown()
{
	if (m_sceneManager)
	{
		m_sceneManager->Shutdown();
		delete m_sceneManager;
		m_sceneManager = 0;
	}

	// Release the texture shader object.
	if(m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	return;
}


bool GraphicsClass::Frame()
{
	bool result = true;
	TimerClass::GetInstance().Execute();
	m_sceneManager->FixedExecute();
	m_sceneManager->CollisionDetection();
	m_sceneManager->Execute();
	m_sceneManager->LateExecute();
	m_sceneManager->PostExecute();

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

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	
	m_D3D->TurnZBufferOn();
	m_D3D->TurnOffAlphaBlending();
	m_D3D->TurnOnCullBackMode();

	result = m_sceneManager->Render(m_LightShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	m_D3D->TurnOnAlphaBlending();
	m_D3D->TurnOnCullNoneMode();

	result = m_sceneManager->WorldSpaceUIRender(m_TextureShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	m_D3D->TurnZBufferOff();
	m_D3D->TurnOnCullNoneMode();

	result = m_sceneManager->UIRender(m_TextureShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}