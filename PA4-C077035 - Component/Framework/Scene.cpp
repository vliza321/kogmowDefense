#include "Scene.h"
#include "graphicsclass.h"

Scene::Scene(string sceneName) : m_sceneState(SceneState::Unloaded), m_sceneName(sceneName)
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

Scene::~Scene()
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


bool Scene::SceneInitialize(int screenWidth, int screenHeight, HWND hwnd)
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

void Scene::AddSceneRef(D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass)
{
	m_d3d = d3dclass;
	m_lightShader = lightshaderclass;
	m_textureShader = textureshaderclass;
}

bool Scene::SceneStart()
{
	if (m_sceneState == SceneState::Loaded)
	{
		m_sceneState = SceneState::Running;
	}
	else return false;
	return true;
}

bool Scene::SceneEnd()
{
	m_sceneState = SceneState::Unloading;
	LockScene();
	Shutdown();
	UnlockScne();
	return true;
}

bool Scene::Render()
{
	return m_renderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix());
}

bool Scene::WorldSpaceUIRender()
{
	return m_worldSpaceUIRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix());
}

bool Scene::LightRender()
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return m_renderManager->RenderAll(m_lightShader, m_d3d, m_cameraManager->GetCamera(), m_lightManager, diffuseColor, lightPosition);
}

bool Scene::UIRender()
{
	return m_canvasRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraManager->GetViewMatrix() );
}


GameObject* Scene::Find(string name)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->name == name)
			{
				return gameObject;
			}
		}
	}
	return nullptr;
}

GameObject* Scene::FindObjectWithTag(Tag tag)
{
	if (m_gameObjects[tag].size() != 0) return m_gameObjects[tag].front();
	return nullptr;
}

vector<GameObject*> Scene::FindObjectsWithTag(Tag tag)
{
	return m_gameObjects[tag];
}

void Scene::RegistGameObject(GameObject* Entity)
{
	m_gameObjects[Entity->tag].push_back(Entity);
	Entity->SetRoot(this);
}

LightClass& Scene::GetLights(int i)
{
	return m_lightManager->GetLights(i);
}

bool Scene::InitializeSet(HWND hwnd)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeSet())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool Scene::Initialize(HWND hwnd)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->Initialize())
			{
				MessageBox(hwnd, L"Could not Initialize GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool Scene::InitializeRef(HWND hwnd)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeRef())
			{
				MessageBox(hwnd, L"Could not InitializeRef GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool Scene::InitializeRender(HWND hwnd)
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

bool Scene::InitializeSynchronization(HWND hwnd)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeSynchronization())
			{
				MessageBox(hwnd, L"Could not InitializeSynchronization GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool Scene::PostInitialize(HWND hwnd)
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->PostInitialize())
			{
				MessageBox(hwnd, L"Could not PostInitialize GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	m_sceneState = SceneState::Loaded;
	return true;
}

void Scene::CollisionDetection()
{
	m_collisionDetecter->ProcessCollision();
}

void Scene::FixedExecute()
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->FixedExecute();
			}
		}
	}
}

void Scene::Execute()
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active) gameObject->Execute();
		}
	}
}

void Scene::LateExecute()
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->LateExecute();
			}
		}
	}
}

void Scene::PostExecute()
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->PostExecute();
			}
		}
	}
	for (auto& v : m_gameObjects)
	{
		for (auto gameObject = v.second.end() - 1; gameObject != v.second.begin(); gameObject--)
		{
			if ((*gameObject)->isDestroy)
			{
				(*gameObject)->ApplyDestroy();
			}
		}
	}
}

void Scene::Shutdown()
{
	for (auto& v : m_gameObjects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->Shutdown();
			}
		}
	}
	m_gameObjects.clear();

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
