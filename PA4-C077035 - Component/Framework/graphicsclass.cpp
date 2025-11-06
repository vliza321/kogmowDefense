////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"
#include <string>

GraphicsClass::GraphicsClass()
{
	m_Input = 0;
	m_sceneManager = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd, InputClass* input)
{
	bool result;

	m_Input = input;
	if (!m_Input)
	{
		return false;
	}

	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		return false;
	}
	result = m_sceneManager->Initialize(screenWidth, screenHeight, hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the SceneManager object.", L"Error", MB_OK);
		return false;
	}

	m_sceneManager->CreateBaseObject();
	m_sceneManager->CreateGameObject();

	m_sceneManager->InitializeSet();
	m_sceneManager->Initialize();
	m_sceneManager->InitializeRef();
	m_sceneManager->InitializeRender();
	m_sceneManager->InitializeSynchronization();
	m_sceneManager->PostInitialize();
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
	m_sceneManager->BeginRender();
	
	m_sceneManager->TurnZBufferOn();
	m_sceneManager->TurnOffAlphaBlending();
	m_sceneManager->TurnOnCullBackMode();

	result = m_sceneManager->LightRender();
	result = m_sceneManager->Render();
	if (!result)
	{
		return false;
	}

	m_sceneManager->TurnOnAlphaBlending();
	m_sceneManager->TurnOnCullNoneMode();

	result = m_sceneManager->WorldSpaceUIRender();
	if (!result)
	{
		return false;
	}

	m_sceneManager->TurnZBufferOff();
	m_sceneManager->TurnOnCullNoneMode();

	result = m_sceneManager->UIRender();
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_sceneManager->EndRender();

	return true;
} 