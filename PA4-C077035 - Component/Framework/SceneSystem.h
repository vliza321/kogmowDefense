#ifndef _SCENESYSTEM_H
#define _SCENESYSTEM_H

#include <unordered_map>
#include "BaseScene.h"
#include "ThreadPool.h"
#include <queue>

#define DUMMYSCENEID 40116

using namespace std;

class SceneSystem
{
public:
	SceneSystem();
	virtual ~SceneSystem();

protected:
	HWND m_hwnd;
	int m_screenWidth;
	int m_screenHeight;
	bool m_requestSceneChange;
	D3DClass* m_d3d;
	TextureShaderClass* m_textureShader;
	LightShaderClass* m_lightShader;

	unordered_map<int, shared_ptr<BaseScene>> m_sceneMap;
	shared_ptr<BaseScene> m_currentScene;
	shared_ptr<BaseScene> m_waitingScene;
	shared_ptr<BaseScene> m_dummyScene;
	queue<shared_ptr<BaseScene>> m_shutdownQueue;

protected:
	bool AddScene(int, const std::shared_ptr<BaseScene>& scene);
	bool SceneLoader(shared_ptr<BaseScene>&);

	bool SceneStart(shared_ptr<BaseScene>&);
	bool SceneLoad(shared_ptr<BaseScene>& scene);

private:
	ThreadPool* m_threadPool;

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

