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
	m_Object = 0;

	m_LightShader = 0;
	timer = 60;
	canInput = true;
	isPause = false;

	intensity = 5;
	pointLightColor = white;
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
	m_Object = new ObjectClass;
	if (!m_Object)
	{
		return false;
	}
	result = m_Object->Initialize(hwnd, m_D3D->GetDevice());
	if (!result)
	{
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
	
	m_Object->CreateBaseObject();
	m_Object->CreateGameObject();

	m_Object->InitializeSet(hwnd, m_D3D->GetDevice());
	m_Object->Initialize(hwnd, m_D3D->GetDevice());
	m_Object->InitializeRef(hwnd, m_D3D->GetDevice());
	m_Object->InitializeRender(hwnd, m_D3D->GetDevice());
	m_Object->InitializeSynchronization(hwnd, m_D3D->GetDevice());
	m_Object->PostInitialize(hwnd, m_D3D->GetDevice());

	return true;
}


void GraphicsClass::Shutdown()
{
	if (m_Object)
	{
		m_Object->Shutdown();
		delete m_Object;
		m_Object = 0;
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
	m_Object->FixedExecute();
	m_Object->CollisionDetection();
	m_Object->Execute();
	m_Object->LateExecute();
	m_Object->PostExecute();

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

	result = m_Object->Render(m_LightShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	m_D3D->TurnOnAlphaBlending();
	m_D3D->TurnOnCullNoneMode();

	result = m_Object->GUIRender(m_TextureShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	m_D3D->TurnZBufferOff();
	m_D3D->TurnOnCullNoneMode();

	result = m_Object->UIRender(m_TextureShader, m_D3D, SceneCount);
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}