#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <unordered_map>
#include "Scene.h"
#include "ThreadPool.h"
#include <queue>

#define DUMMYSCENEID 40116

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}
private:
	HWND m_hwnd;
	int m_screenWidth;
	int m_screenHeight;
	bool m_requestSceneChange;
	D3DClass* m_d3d;
	TextureShaderClass* m_textureShader;
	LightShaderClass* m_lightShader;

	ThreadPool* m_threadPool;

private:
	unordered_map<int, shared_ptr<Scene>> m_sceneMap;
	std::shared_ptr<Scene> m_currentScene;
	std::shared_ptr<Scene> m_waitingScene;
	std::shared_ptr<Scene> m_dummyScene;
	std::queue<shared_ptr<Scene>> m_shutdownQueue;

	bool AddScene(int, const std::shared_ptr<Scene>& scene);
	bool SceneLoader(shared_ptr<Scene>&);
	bool StartScene(shared_ptr<Scene>&);
	bool LoadScene(shared_ptr<Scene>& scene);

public:
	bool LoadScene(int);
	bool LoadScene(string);

	bool StartScene();
	bool StartScene(int count);
	bool StartScene(string sceneName);
public:
	bool Initialize(int, int, HWND, D3DClass*, LightShaderClass*, TextureShaderClass*);
	void Shutdown();
public:
	void CreateBaseObject();
	void CreateGameObject();

	bool InitializeSet();
	bool Initialize();
	bool InitializeRef();
	bool InitializeRender();
	bool InitializeSynchronization();
	bool PostInitialize();

	void CollisionDetection();

	void SceneChange();
	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

	bool WorldSpaceUIRender();
	bool Render();
	bool LightRender();
	bool UIRender();
};

#endif 