#include "SceneManager.h"
#include "ObjectClass.h"
#include "DummyScene.h"

SceneManager::SceneManager() 
	: SceneSystem()
{

}

SceneManager::~SceneManager()
{

}

/*=================================================================================*/
//외부에서 미리 로드된 씬 시작 호출
bool SceneManager::StartScene()
{
	if (!m_waitingScene)
	{
		int id = m_currentScene->GetSceneID();
		if (m_sceneMap.find(id + 1) != m_sceneMap.end())
		{
			
			return SceneStart(m_sceneMap[id + 1]);
		}
	}
	
	return false;
}

bool SceneManager::StartScene(int count)
{
	if (m_sceneMap.find(count) == m_sceneMap.end())
	{
		return false;
	}
	SceneStart(m_sceneMap[count]);
}

bool SceneManager::StartScene(string sceneName)
{
	for (auto& scene : m_sceneMap)
	{
		if (scene.second->GetSceneName() == sceneName)
		{
			return SceneStart(scene.second);
		}
	}
	return false;
}

/*=================================================================================*/
//외부에서 씬 로드 시작
bool SceneManager::LoadScene(int count)
{
	if (m_sceneMap.find(count) != m_sceneMap.end())
	{
		return SceneLoad(m_sceneMap[count]);
	}
	return false;
}

bool SceneManager::LoadScene(string sceneName)
{
	for (auto& scene : m_sceneMap)
	{
		if (scene.second->GetSceneName() == sceneName)
		{
			return SceneLoad(scene.second);
		}
	}
	return false;
}