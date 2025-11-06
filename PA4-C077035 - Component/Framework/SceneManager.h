#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <unordered_map>

#include "Scene.h"
#include "ObjectClass.h"
#include "DummyScene.h"

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
private:
	HWND m_hwnd;
	int m_screenWidth;
	int m_screenHeight;
private:
	unordered_map<int, shared_ptr<Scene>> m_sceneMap;
	std::shared_ptr<Scene> m_currentScene;
	std::shared_ptr<Scene> m_waitingScene;
	std::shared_ptr<Scene> m_dummyScene;

	bool AddScene(int, const std::shared_ptr<Scene>& scene);
	bool InitScene(shared_ptr<Scene>&);
	void ChangeScene(shared_ptr<Scene>&);
	bool LoadScene(shared_ptr<Scene>& scene);

public:
	bool LoadScene(int);
	bool LoadScene(string);

	void StartScene();
	void StartScene(int count);
	void StartScene(string sceneName);

	void ChangeScene();
public:
	bool Initialize(int, int, HWND);
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

	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

	bool WorldSpaceUIRender();
	bool Render();
	bool LightRender();
	bool UIRender();

	void BeginRender();
	void EndRender();
	void TurnZBufferOn();
	void TurnZBufferOff();
	void TurnOffAlphaBlending();
	void TurnOnAlphaBlending();
	void TurnOnCullBackMode();
	void TurnOnCullNoneMode();
};

#endif 