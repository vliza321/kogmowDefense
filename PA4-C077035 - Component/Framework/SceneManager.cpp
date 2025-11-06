#include "SceneManager.h"

SceneManager::SceneManager()
{
	m_currentScene = 0;
	m_waitingScene = 0;
	m_dummyScene = 0;

	m_hwnd = 0;
	m_screenWidth = 0;
	m_screenHeight = 0;
}

SceneManager::~SceneManager()
{

}

/*=================================================================================*/
void SceneManager::ChangeScene()
{
	if (true) // 씬 교체 요청이 있는가 && 교체 대상 씬의 로드가 종료 되었는가 && shutdown이 종료 되었는가
	{
		m_currentScene = m_waitingScene;
		m_waitingScene = m_sceneMap[-1];
	}
}

void SceneManager::ChangeScene(std::shared_ptr<Scene>& scene)
{
	// 기존씬 할당 해제
	if (m_currentScene != nullptr)
	{
		m_currentScene->SceneEnd();
	}
	// 완전 로드 전
	if (scene->GetSceneState() == SceneState::Unloaded)
	{
		m_currentScene = m_sceneMap[-1];
		LoadScene(scene);
	}
	// 로드 중
	if (scene->GetSceneState() == SceneState::Unloading)
	{
		m_currentScene = m_sceneMap[-1];
		// 로드 완료까지 대기 
		if (scene->GetSceneState() == SceneState::Loaded)
		{
			// 로드 완료시 씬 시작
			scene->SceneStart();
			m_currentScene = scene;
		}
	}
	// 로드 완료 
	if (scene->GetSceneState() == SceneState::Loaded)
	{
		// 바로 씬 시작
		scene->SceneStart();
		m_currentScene = scene;
	}
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

bool SceneManager::InitScene(shared_ptr<Scene>& scene)
{
	scene->SceneLoadStart(m_screenWidth, m_screenHeight, m_hwnd);
	scene->CreateBaseObject();
	scene->CreateGameObject();
	scene->InitializeSet(m_hwnd);
	scene->Initialize(m_hwnd);
	scene->InitializeRef(m_hwnd);
	scene->InitializeRender(m_hwnd);
	scene->InitializeSynchronization(m_hwnd);
	scene->PostInitialize(m_hwnd);

	return true;
}
 
/*=================================================================================*/

bool SceneManager::LoadScene(shared_ptr<Scene>& scene)
{
	m_waitingScene = scene;
	return InitScene(m_waitingScene);
}

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

/*=================================================================================*/

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

bool SceneManager::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result = true;

	m_hwnd = hwnd;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	shared_ptr<DummyScene> dummyScene = std::make_shared<DummyScene>();
	result = AddScene(-1, dummyScene);
	if (!result)
	{
		return result;
	}

	shared_ptr<ObjectClass> objectClass = std::make_shared<ObjectClass>();
	result = AddScene(0, objectClass);
	if (!result)
	{
		return result;
	}
	StartScene(0);

	/*
	shared_ptr<ObjectClass> objectClass1 = std::make_shared<ObjectClass>();
	result = AddScene(1, objectClass1);
	if (!result)
	{
		return result;
	}

	*/
	return result;
}

void SceneManager::Shutdown()
{
	if (m_dummyScene != 0)
	{
		m_dummyScene->Shutdown();
		m_dummyScene = 0;
	}
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

bool SceneManager::InitializeSet()
{
	return m_currentScene->InitializeSet(m_hwnd);
}

bool SceneManager::Initialize()
{
	return m_currentScene->Initialize(m_hwnd);
}

bool SceneManager::InitializeRef()
{
	return m_currentScene->InitializeRef(m_hwnd);
}

bool SceneManager::InitializeRender( )
{
	return m_currentScene->InitializeRender(m_hwnd);
}

bool SceneManager::InitializeSynchronization()
{
	return m_currentScene->InitializeSynchronization(m_hwnd);
}

bool SceneManager::PostInitialize()
{
	return m_currentScene->PostInitialize(m_hwnd);
}

void SceneManager::CollisionDetection()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->CollisionDetection();
}

void SceneManager::FixedExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->FixedExecute();
}

void SceneManager::Execute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->Execute();
}

void SceneManager::LateExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->LateExecute();
}

void SceneManager::PostExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->PostExecute();
}

bool SceneManager::WorldSpaceUIRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) { return m_currentScene->WorldSpaceUIRender(); }
	return true;
}

bool SceneManager::Render()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) { return m_currentScene->Render(); }
	return true;
}

bool SceneManager::LightRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) { return m_currentScene->Render(); }
	return true;
}

bool SceneManager::UIRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) { return m_currentScene->UIRender(); }
	return true;
}

void SceneManager::BeginRender()
{
	m_currentScene->GetD3DClass()->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
}

void SceneManager::EndRender()
{
	m_currentScene->GetD3DClass()->EndScene();
}

void SceneManager::TurnZBufferOn()
{
	m_currentScene->GetD3DClass()->TurnZBufferOn();
}

void SceneManager::TurnZBufferOff()
{
	m_currentScene->GetD3DClass()->TurnZBufferOff();
}

void SceneManager::TurnOffAlphaBlending()
{
	m_currentScene->GetD3DClass()->TurnOffAlphaBlending();
}

void SceneManager::TurnOnAlphaBlending()
{
	m_currentScene->GetD3DClass()->TurnOnAlphaBlending();
}

void SceneManager::TurnOnCullBackMode()
{
	m_currentScene->GetD3DClass()->TurnOnCullBackMode();
}

void SceneManager::TurnOnCullNoneMode()
{
	m_currentScene->GetD3DClass()->TurnOnCullNoneMode();
}