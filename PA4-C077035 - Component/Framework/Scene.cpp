#include "Scene.h"

Scene::Scene(string sceneName)
{
	m_renderManager = 0;
	m_worldSpaceUIRenderManager = 0;
	m_canvasRenderManager = 0;

	m_cameraManager = 0;
	m_lightManager = 0;

	m_collisionDetecter = 0;

	m_sceneName = sceneName;
	m_sceneState = SceneState::Unloaded;
}

Scene::~Scene()
{

}

void Scene::SceneStart()
{
	m_renderManager = new RenderManager();
	m_worldSpaceUIRenderManager = new WorldSpaceUIRenderManager();
	m_canvasRenderManager = new CanvasRenderManager();

	m_collisionDetecter = new Collision();
}

void Scene::SceneEnd()
{
	Shutdown();
}

bool Scene::Render(TextureShaderClass* textureShader, D3DClass* d3d, int)
{
	return m_renderManager->RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
	//return m_renderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
}

bool Scene::WorldSpaceUIRender(TextureShaderClass* textureShader, D3DClass* d3d, int sceneCounter)
{
	return m_worldSpaceUIRenderManager->RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
	//return m_worldSpaceUIRenderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
}

bool Scene::Render(LightShaderClass* lightShader, D3DClass* d3d, int)
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return m_renderManager->RenderAll(lightShader, d3d, m_cameraManager->GetCamera(), m_lightManager, diffuseColor, lightPosition);
	//return m_renderManager::GetInstance().RenderAll(lightShader, d3d, m_cameraManager->GetCamera(), m_lightManager, diffuseColor, lightPosition);
}

bool Scene::UIRender(TextureShaderClass* textureShader, D3DClass* d3d, int)
{
	return m_canvasRenderManager->RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix() );
	//return m_canvasRenderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
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


bool Scene::InitializeSet(HWND hwnd, ID3D11Device* device)
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

bool Scene::Initialize(HWND hwnd, ID3D11Device* device)
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

bool Scene::InitializeRef(HWND hwnd, ID3D11Device* device)
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

bool Scene::InitializeRender(HWND hwnd, ID3D11Device* device)
{
	if (!(m_worldSpaceUIRenderManager->InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not GUI InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_canvasRenderManager->InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Canvas InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_renderManager->InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Render InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	return true;
}

bool Scene::InitializeSynchronization(HWND hwnd, ID3D11Device* device)
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

bool Scene::PostInitialize(HWND hwnd, ID3D11Device* device)
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
			if (gameObject->active)
			{
				gameObject->Execute();
			}
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

	if (m_renderManager != 0)
	{
		m_renderManager->Shutdown();
		delete m_renderManager;
	}
	if (m_worldSpaceUIRenderManager != 0)
	{
		m_worldSpaceUIRenderManager->Shutdown();
		delete m_worldSpaceUIRenderManager;
	}
	if (m_canvasRenderManager != 0)
	{
		m_canvasRenderManager->Shutdown();
		delete m_canvasRenderManager;
	}
	if (m_cameraManager != 0)
	{
		m_cameraManager->Shutdown();
		delete m_cameraManager;
	}
	if (m_lightManager != 0)
	{
		m_lightManager->Shutdown();
		delete m_lightManager;
	}
	if (m_collisionDetecter != 0)
	{
		m_collisionDetecter->Shutdown();
		delete m_collisionDetecter;
	}
}
