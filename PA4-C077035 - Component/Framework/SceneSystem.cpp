#include "SceneSystem.h"
#include "ObjectClass.h"
#include "DummyScene.h"
#include "TestScene0.h"
#include "TestScene1.h"
#include "TestScene2.h"
#include "TestScene3.h"

SceneSystem::SceneSystem()
{
	m_currentScene = 0;
	m_waitingScene = 0;
	m_dummyScene = 0;

	m_hwnd = 0;
	m_screenWidth = 0;
	m_screenHeight = 0;
	m_requestSceneChange = false;
	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;
	m_threadPool = 0;
}

SceneSystem::~SceneSystem()
{
	this->Shutdown();
}

/*=================================================================================*/
//내부에서 씬 추가
bool SceneSystem::AddScene(int id, const std::shared_ptr<BaseScene>& scene)
{
	if (m_sceneMap.find(id) == m_sceneMap.end())
	{
		m_sceneMap[id] = scene;
		scene->SetSceneID(id);
		scene->AddSceneRef(m_d3d, m_lightShader, m_textureShader, m_hwnd);
		return true;
	}
	return true;
}

/*=================================================================================*/
//내부에서 씬 로드  

bool SceneSystem::SceneLoader(shared_ptr<BaseScene>& scene)
{
	SceneState state = scene->GetSceneState();
	if (state == SceneState::Loading ||
		state == SceneState::Loaded || 
		state == SceneState::Running)
	{
		return true;
	}

	scene->LockScene();
	if (state != SceneState::Unloaded)
	{
		scene->UnlockScene();
		return true;
	}
	scene->SceneInitialize();
	scene->CreateBaseObject();
	scene->CreateGameObject();
	scene->InitializeSet();
	scene->Initialize();
	scene->InitializeRef();
	scene->InitializeRender();
	scene->InitializeSynchronization();
	scene->PostInitialize();
	scene->UnlockScene();

	return true;
}


/*=================================================================================*/
bool SceneSystem::SceneStart(std::shared_ptr<BaseScene>& scene)
{
	m_requestSceneChange = true;

	// 대기 중인 씬이 없는 경우
	if (m_currentScene == scene)
	{
		m_currentScene = m_dummyScene;
		m_waitingScene = scene;
		int id = scene->GetSceneID();
		auto shutdownTarget = m_sceneMap[id];
		m_threadPool->Enqueue([shutdownTarget]() {
			shutdownTarget->LockScene();
			shutdownTarget->Shutdown();
			shutdownTarget->SceneInitialize();
			shutdownTarget->CreateBaseObject();
			shutdownTarget->CreateGameObject();
			shutdownTarget->InitializeSet();
			shutdownTarget->Initialize();
			shutdownTarget->InitializeRef();
			shutdownTarget->InitializeRender();
			shutdownTarget->InitializeSynchronization();
			shutdownTarget->PostInitialize();
			shutdownTarget->UnlockScene();
			});
	}
	else
	{
		m_shutdownQueue.push(m_currentScene->GetSceneID());
	}

	if (m_waitingScene == nullptr)
	{
		SceneLoad(scene);
		return true;
	}
	// 대기 하던 씬이 있는 상태
	else
	{
		// 대기하고 있는 씬이 시작할 씬이랑 서로 다르면
		if (scene->GetSceneID() != m_waitingScene->GetSceneID())
		{
			// 기존에 있던 대기하고 있는 씬은 shutdown
			/*==================로드 중 로드 해체 상황=====================*/
			m_shutdownQueue.push(m_waitingScene->GetSceneID());
			/*======================================*/
			// 씬 로드 시작
			SceneLoad(scene);
			return true;
		}
		// 대기하고 있는 씬이 시작할 씬이랑 같으면 문제 없이 진행
		else
		{
			return true;
		}
	}
	return false;
}

bool SceneSystem::SceneLoad(shared_ptr<BaseScene>& scene)
{
	// 씬 로드 요청 받은 씬이 이미 로드 중이거나 로드가 끝난 상태면
	if (scene->GetSceneState() == SceneState::Loading ||
		scene->GetSceneState() == SceneState::Loaded) return true;

	// 씬 로드 요청 받은 씬이 해제 중 이거나, 동작 중이면
	else if (scene->GetSceneState() == SceneState::Unloading ||
		scene->GetSceneState() == SceneState::Running) return false;
	
	// 대기하고 있는 씬이 있는 상황
	if (m_waitingScene != nullptr)
	{
		m_shutdownQueue.push(m_waitingScene->GetSceneID());
	}

	m_waitingScene = scene;
	m_threadPool->Enqueue([this]() {
		SceneLoader(m_waitingScene);
		});
	return true;
}

/* "대기하고 있는 씬이 있는 상황" 대체 가능*/
////대기하고 있는 씬이 없는 상황
//if (m_waitingScene == nullptr)
//{
//	m_waitingScene = scene;
//	m_threadPool->Enqueue([this]() {
//		SceneLoader(m_waitingScene);
//		});
//}
//// 대기하고 있는 씬이 있는데 로드할 씬이랑 서로 다르면
//else if (scene->GetSceneID() != m_waitingScene->GetSceneID())
//{
//	// 대기하고 있던 씬이 없더라도 새로 로드할 씬 등록하고 로드 시작
//	/*==================로드 중 로드 해체 상황=====================*/
//	m_shutdownQueue.push(m_waitingScene);
//	/*======================================*/
//	m_waitingScene = scene;
//	m_threadPool->Enqueue([this]() {
//		SceneLoader(m_waitingScene);
//		});
//}

/*=================================================================================*/
//씬 교체 동작을 Frame 맨 앞에서 씬 교체 동작이 필요한지 검색

void SceneSystem::SceneChange()
{
	while (!m_shutdownQueue.empty())
	{
		int id = m_shutdownQueue.front();
		auto shutdownTarget = m_sceneMap[id];
		if (id != DUMMYSCENEID)
			m_threadPool->Enqueue([shutdownTarget]() {
				shutdownTarget->SceneEnd();
				});
		m_shutdownQueue.pop();
	}


	// 씬교체 요청도 없고 대기 중인 씬도 없으면 종료
	if (!m_requestSceneChange || m_waitingScene == nullptr) return;

	//대기 하고 있는 씬이 존재
	switch (m_waitingScene->GetSceneState())
	{
		//로드 시작도 못함
	case SceneState::Unloaded:
		m_threadPool->Enqueue([this]() {
			SceneLoader(m_waitingScene);
			});
		m_currentScene = m_dummyScene;
		break;
		//로드 중
	case SceneState::Loading:
		m_currentScene = m_dummyScene;
		break;
		//로드 완료

	case SceneState::Loaded:
		m_currentScene = m_waitingScene;
		m_currentScene->SceneStart();
		if (m_waitingScene->GetSceneID() != DUMMYSCENEID)
		{
			m_requestSceneChange = false;
		}
		m_waitingScene = nullptr;
		break;
	case SceneState::Unloading:

		break;
		//대기 중인 씬이 언로드 중 혹은 동작 중
	default:
		MessageBox(m_hwnd, L"Could not SceneChange, WaitingScene was in Running.", L"Error", MB_OK);
		break;
	}
}

/*=================================================================================*/

bool SceneSystem::Initialize(int screenWidth, int screenHeight, HWND hwnd, D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass)
{
	bool result = true;

	m_hwnd = hwnd;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_d3d = d3dclass;
	m_lightShader = lightshaderclass;
	m_textureShader = textureshaderclass;

	m_threadPool = new ThreadPool(4);
	if (!m_threadPool)
	{
		return false;
	}

	m_dummyScene = std::make_shared<DummyScene>();
	result = AddScene(DUMMYSCENEID, m_dummyScene);
	if (!result)
	{
		return result;
	}
	SceneLoader(m_dummyScene);
	m_dummyScene->SceneStart();
	m_currentScene = m_dummyScene;

	shared_ptr<TestScene0> testScene0 = std::make_shared<TestScene0>();
	result = AddScene(0, testScene0);
	if (!result)
	{
		return result;
	}

	shared_ptr<TestScene1> testScene1 = std::make_shared<TestScene1>();
	result = AddScene(1, testScene1);
	if (!result)
	{
		return result;
	}

	shared_ptr<TestScene2> testScene2 = std::make_shared<TestScene2>();
	result = AddScene(2, testScene2);
	if (!result)
	{
		return result;
	}

	shared_ptr<TestScene3> testScene3 = std::make_shared<TestScene3>();
	result = AddScene(3, testScene3);
	if (!result)
	{
		return result;
	}

	shared_ptr<ObjectClass> objectClass = std::make_shared<ObjectClass>();
	result = AddScene(4, objectClass);
	if (!result)
	{
		return result;
	}

	int startSceneid = 0;
	if (m_sceneMap.find(startSceneid) == m_sceneMap.end())
	{
		return false;
	}
	SceneStart(m_sceneMap[startSceneid]);

	return result;
}

void SceneSystem::Shutdown()
{
	if (m_dummyScene != 0)
	{
		m_dummyScene->Shutdown();
		m_dummyScene = nullptr;
	}
	if (m_waitingScene != 0)
	{
		m_waitingScene->Shutdown();
		m_waitingScene = nullptr;
	}
	if (m_currentScene != 0)
	{
		m_currentScene->Shutdown();
		m_currentScene = nullptr;
	}
	for (auto& scene : m_sceneMap)
	{
		scene.second->Shutdown();
	}
	m_sceneMap.clear();
}

void SceneSystem::CreateBaseObject()
{
	m_currentScene->CreateBaseObject();
}

void SceneSystem::CreateGameObject()
{
	m_currentScene->CreateGameObject();
}

bool SceneSystem::InitializeSet()
{
	return m_currentScene->InitializeSet();
}

bool SceneSystem::Initialize()
{
	return m_currentScene->Initialize();
}

bool SceneSystem::InitializeRef()
{
	return m_currentScene->InitializeRef();
}

bool SceneSystem::InitializeRender()
{
	return m_currentScene->InitializeRender();
}

bool SceneSystem::InitializeSynchronization()
{
	return m_currentScene->InitializeSynchronization();
}

bool SceneSystem::PostInitialize()
{
	return m_currentScene->PostInitialize();
}

void SceneSystem::CollisionDetection()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->CollisionDetection();
}

void SceneSystem::FixedExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->FixedExecute();
}

void SceneSystem::Execute()
{
	if (m_currentScene->GetSceneState() 
		== SceneState::Running)
		m_currentScene->Execute();
}

void SceneSystem::LateExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->LateExecute();
}

void SceneSystem::PostExecute()
{
	if (m_currentScene->GetSceneState() == SceneState::Running) m_currentScene->PostExecute();
}

bool SceneSystem::WorldSpaceUIRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running && m_currentScene->GetSceneID() != DUMMYSCENEID) { return m_currentScene->WorldSpaceUIRender(); }
	return true;
}

bool SceneSystem::Render()
{
	if (m_currentScene->GetSceneState() == SceneState::Running && m_currentScene->GetSceneID() != DUMMYSCENEID) { return m_currentScene->Render(); }
	return true;
}

bool SceneSystem::LightRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running && m_currentScene->GetSceneID() != DUMMYSCENEID) { return m_currentScene->LightRender(); }
	return true;
}

bool SceneSystem::UIRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running && m_currentScene->GetSceneID() != DUMMYSCENEID) { return m_currentScene->UIRender(); }
	return true;
}

void SceneSystem::PrevRender()
{
	if (m_currentScene->GetSceneState() == SceneState::Running && m_currentScene->GetSceneID() != DUMMYSCENEID) { return m_currentScene->PrevRender(); }
}