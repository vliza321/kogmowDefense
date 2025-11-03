#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_currentScene = 0;
	m_waitingScene = 0;
	m_hwnd = 0;
}

SceneManager::~SceneManager()
{

}

/*=================================================================================*/

void SceneManager::ChangeScene(const std::shared_ptr<Scene>& scene)
{
	if (m_currentScene != nullptr)
	{
		m_currentScene->SceneEnd();
	}
	m_currentScene = scene;
	m_currentScene->SceneStart();
}

/*=================================================================================*/

bool SceneManager::AddScene(int count, const std::shared_ptr<Scene>& scene)
{
	if (m_sceneMap.find(count) != m_sceneMap.end())
	{
		return false;
	}
	m_sceneMap[count] = scene;
	return true;
}

bool SceneManager::LoadScene(shared_ptr<Scene>& scene)
{
	scene->InitializeSet(m_hwnd, );

	return true;
}
 
/*=================================================================================*/

bool SceneManager::LoadScene(int count)
{
	if (m_sceneMap.find(count) != m_sceneMap.end())
	{
		return LoadScene(m_sceneMap[count]);
	}
	return false;
}

bool SceneManager::LoadScene(string sceneName)
{
	for (auto& scene : m_sceneMap)
	{
		if (scene.second->GetSceneName() == sceneName)
		{
			return LoadScene(scene.second);
		}
	}
	return false;
}


void SceneManager::StartScene()
{
	ChangeScene(m_waitingScene);
}

void SceneManager::StartScene(int count)
{
	ChangeScene(m_sceneMap[count]);
}

void SceneManager::StartScene(string sceneName)
{
	for (auto& scene : m_sceneMap)
	{
		if (scene.second->GetSceneName() == sceneName)
		{
			ChangeScene(scene.second);
		}
	}
}

/*=================================================================================*/

bool SceneManager::Initialize(HWND hwnd)
{
	bool result = true;
	
	m_hwnd = hwnd;

	shared_ptr<ObjectClass> objectClass = std::make_shared<ObjectClass>();
	result = AddScene(0, objectClass);
	if (!result)
	{
		return result;
	}
	shared_ptr<ObjectClass> objectClass1 = std::make_shared<ObjectClass>();
	result = AddScene(1, objectClass1);
	if (!result)
	{
		return result;
	}

	StartScene(0);

	return result;
}

void SceneManager::Shutdown()
{
	if (m_waitingScene != 0)
	{
		m_waitingScene->Shutdown();
		m_waitingScene = 0;
	}
	if (m_currentScene != 0)
	{
		m_currentScene->Shutdown();
		m_currentScene = 0;
	}
	m_sceneMap.clear();
}

void SceneManager::CreateBaseObject()
{
	m_currentScene->CreateBaseObject();
}

void SceneManager::CreateGameObject()
{
	m_currentScene->CreateGameObject();
}

bool SceneManager::InitializeSet(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->InitializeSet(hwnd, device);
}

bool SceneManager::Initialize(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->Initialize(hwnd, device);
}

bool SceneManager::InitializeRef(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->InitializeRef(hwnd, device);
}

bool SceneManager::InitializeRender(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->InitializeRender(hwnd, device);
}

bool SceneManager::InitializeSynchronization(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->InitializeSynchronization(hwnd, device);
}

bool SceneManager::PostInitialize(HWND hwnd, ID3D11Device* device)
{
	return m_currentScene->PostInitialize(hwnd, device);
}

void SceneManager::CollisionDetection()
{
	if (m_currentScene->GetLoadDone()) m_currentScene->CollisionDetection();
}

void SceneManager::FixedExecute()
{
	if (m_currentScene->GetLoadDone()) m_currentScene->FixedExecute();
}

void SceneManager::Execute()
{
	if (m_currentScene->GetLoadDone()) m_currentScene->Execute();
}

void SceneManager::LateExecute()
{
	if (m_currentScene->GetLoadDone()) m_currentScene->LateExecute();
}

void SceneManager::PostExecute()
{
	if (m_currentScene->GetLoadDone()) m_currentScene->PostExecute();
}

bool SceneManager::WorldSpaceUIRender(TextureShaderClass* textureShaderClass, D3DClass* d3dClass, int count)
{
	if (m_currentScene->GetLoadDone()) {
		return m_currentScene->WorldSpaceUIRender(textureShaderClass, d3dClass, count);
	}
	return true;
}

bool SceneManager::Render(LightShaderClass* LightShaderClass, D3DClass* d3dClass, int count)
{
	if (m_currentScene->GetLoadDone()) {
		return m_currentScene->Render(LightShaderClass, d3dClass, count);
	}
	return true;
}

bool SceneManager::Render(TextureShaderClass* textureShaderClass, D3DClass* d3dClass, int count)
{
	if (m_currentScene->GetLoadDone()) {
		return m_currentScene->Render(textureShaderClass, d3dClass, count);
	}
	return true;
}

bool SceneManager::UIRender(TextureShaderClass* textureShaderClass, D3DClass* d3dClass, int count)
{
	if (m_currentScene->GetLoadDone()) {
		return m_currentScene->UIRender(textureShaderClass, d3dClass, count);
	}
	return true;
}
