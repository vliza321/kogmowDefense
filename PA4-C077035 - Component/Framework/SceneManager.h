#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include <unordered_map>

#include "Scene.h"
#include "ObjectClass.h"

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
private:
	unordered_map<int, shared_ptr<Scene>> m_sceneMap;
	std::shared_ptr<Scene> m_currentScene;
	std::shared_ptr<Scene> m_waitingScene;

	HWND& m_hwnd;

	bool AddScene(int, const std::shared_ptr<Scene>& scene);
	bool LoadScene(shared_ptr<Scene>&);
	void ChangeScene(const shared_ptr<Scene>&);
public:
	bool LoadScene(int);
	bool LoadScene(string);

	void StartScene();
	void StartScene(int count);
	void StartScene(string sceneName);

public:
	bool Initialize(HWND);
	void Shutdown();
public:
	void CreateBaseObject();
	void CreateGameObject();

	bool InitializeSet(HWND, ID3D11Device*);
	bool Initialize(HWND, ID3D11Device*);
	bool InitializeRef(HWND, ID3D11Device*);
	bool InitializeRender(HWND, ID3D11Device*);
	bool InitializeSynchronization(HWND, ID3D11Device*);
	bool PostInitialize(HWND, ID3D11Device*);

	void CollisionDetection();

	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

	bool WorldSpaceUIRender(TextureShaderClass*, D3DClass*, int);
	bool Render(LightShaderClass*, D3DClass*, int);
	bool Render(TextureShaderClass*, D3DClass*, int);
	bool UIRender(TextureShaderClass*, D3DClass*, int);
};

#endif // !_SCENEMANAGER_H


