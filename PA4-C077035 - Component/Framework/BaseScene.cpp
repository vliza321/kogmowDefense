#include "BaseScene.h"
#include "graphicsclass.h"

BaseScene::BaseScene(string sceneName) : m_sceneState(SceneState::Unloaded), m_sceneName(sceneName)
{
	m_renderManager = 0;
	m_worldSpaceUIRenderManager = 0;
	m_canvasRenderManager = 0;

	m_cameraManager = 0;
	m_lightManager = 0;

	m_collisionDetecter = 0;

	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;
}

BaseScene::~BaseScene()
{
	this->Shutdown();
	m_renderManager = 0;
	m_worldSpaceUIRenderManager = 0;
	m_canvasRenderManager = 0;

	m_cameraManager = 0;
	m_lightManager = 0;

	m_collisionDetecter = 0;

	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;

	m_sceneLock.reset();
	
}


bool BaseScene::SceneInitialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result = true;

	m_sceneState = SceneState::Loading;

	m_renderManager = new RenderManager();
	if (!m_renderManager)
	{
		return false;
	}

	m_worldSpaceUIRenderManager = new WorldSpaceUIRenderManager();
	if (!m_worldSpaceUIRenderManager)
	{
		return false;
	}

	m_canvasRenderManager = new CanvasRenderManager();
	if (!m_canvasRenderManager)
	{
		return false;
	}

	m_collisionDetecter = new Collision();
	if (!m_collisionDetecter)
	{
		return false;
	}

	result = m_renderManager->InitializeRender(m_d3d->GetDevice());
	if(!result)
	{
		MessageBox(hwnd, L"Could not Scene initialize Render.", L"Error", MB_OK);
		return false;
	}

	result = m_worldSpaceUIRenderManager->InitializeRender(m_d3d->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not Scene initialize worldSpaceUIRender.", L"Error", MB_OK);
		return false;
	}

	result = m_canvasRenderManager->InitializeRender(m_d3d->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not Scene initialize canvasRender.", L"Error", MB_OK);
		return false;
	}

	return true;
}

void BaseScene::AddSceneRef(D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass)
{
	m_d3d = d3dclass;
	m_lightShader = lightshaderclass;
	m_textureShader = textureshaderclass;
}

bool BaseScene::SceneStart()
{
	if (m_sceneState == SceneState::Loaded)
	{
		m_sceneState = SceneState::Running;
	}
	else return false;
	return true;
}

bool BaseScene::SceneEnd()
{
	m_sceneState = SceneState::Unloading;
	LockScene();
	Shutdown();
	UnlockScne();
	return true;
}

bool BaseScene::Render()
{
	return m_renderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix());
}

bool BaseScene::WorldSpaceUIRender()
{
	return m_worldSpaceUIRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix());
}

bool BaseScene::LightRender()
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return m_renderManager->RenderAll(m_lightShader, m_d3d, m_cameraManager->GetCamera(), m_lightManager, diffuseColor, lightPosition);
}

bool BaseScene::UIRender()
{
	return m_canvasRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix() );
}

LightClass& BaseScene::GetLights(int i)
{
	return m_lightManager->GetLights(i);
}

bool BaseScene::InitializeSet(HWND hwnd)
{
	for (auto& v : m_vGameObjects)
	{
		v->InitializeSet();
	}

	return true;
}

bool BaseScene::Initialize(HWND hwnd)
{
	for (auto& v : m_vGameObjects)
	{
		v->Initialize();
	}


	return true;
}

bool BaseScene::InitializeRef(HWND hwnd)
{
	for (auto& v : m_vGameObjects)
	{
		v->InitializeRef();
	}

	return true;
}

bool BaseScene::InitializeRender(HWND hwnd)
{
	if (!(m_worldSpaceUIRenderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(hwnd, L"Could not GUI InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_canvasRenderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(hwnd, L"Could not Canvas InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_renderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(hwnd, L"Could not Render InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	return true;
}

bool BaseScene::InitializeSynchronization(HWND hwnd)
{
	for (auto& v : m_vGameObjects)
	{
		v->InitializeSynchronization();
	}

	return true;
}

bool BaseScene::PostInitialize(HWND hwnd)
{
	for (auto& v : m_vGameObjects)
	{
		v->PostInitialize();
	}

	m_sceneState = SceneState::Loaded;
	return true;
}

void BaseScene::CollisionDetection()
{
	m_collisionDetecter->ProcessCollision();
}

void BaseScene::FixedExecute()
{
	for (auto& v : m_vGameObjects)
	{
		if(v->active) v->FixedExecute();
	}
}

void BaseScene::Execute()
{
	for (auto& v : m_vGameObjects)
	{
		if (v->active) v->Execute();
	}
}

void BaseScene::LateExecute()
{
	for (auto& v : m_vGameObjects)
	{
		if (v->active) v->LateExecute();
	}
}

void BaseScene::PostExecute()
{
	for (auto& v : m_vGameObjects)
	{
		if (v->active) v->PostExecute();
	}
	for (int i = (int)m_vGameObjects.size() - 1; i >= 0; i--)
	{
		GameObject* obj = m_vGameObjects[i];

		if (obj->isDestroy)
		{
			obj->ApplyDestroy();
			delete obj;

			// 벡터에서 제거
			m_vGameObjects.erase(m_vGameObjects.begin() + i);
		}
	}
}

void BaseScene::Shutdown()
{
	for (auto& v : m_vGameObjects)
	{
		v->Shutdown();
	}
	m_vGameObjects.clear();

	if (m_cameraManager != 0)
	{
		m_cameraManager->Shutdown();
		delete m_cameraManager;
		m_cameraManager = 0;
	}
	if (m_lightManager != 0)
	{
		m_lightManager->Shutdown();
		delete m_lightManager;
		m_lightManager = 0;
	}
	if (m_collisionDetecter != 0)
	{
		m_collisionDetecter->Shutdown();
		delete m_collisionDetecter;
		m_collisionDetecter = 0;
	}
	if (m_renderManager != 0)
	{
		m_renderManager->Shutdown();
		delete m_renderManager;
		m_renderManager = 0;
	}
	if (m_worldSpaceUIRenderManager != 0)
	{
		m_worldSpaceUIRenderManager->Shutdown();
		delete m_worldSpaceUIRenderManager;
		m_worldSpaceUIRenderManager = 0;
	}
	if (m_canvasRenderManager != 0)
	{
		m_canvasRenderManager->Shutdown();
		delete m_canvasRenderManager;
		m_canvasRenderManager = 0;
	}

	m_sceneState = SceneState::Unloaded;
}
