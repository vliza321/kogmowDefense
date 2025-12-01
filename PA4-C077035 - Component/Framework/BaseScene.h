#ifndef _SCENE_H
#define _SCENE_H

#include <string>
#include <vector>
#include <map>
#include <d3d11.h>
#include <directxmath.h>
#include <mutex>

#include "d3dclass.h"

#include "textureshaderclass.h"
#include "lightshaderclass.h"

#include "Collision.h"

#include "GameObject.h"
#include "Component.h"

#include "RenderManager.h"
#include "WorldSpaceUIRenderManager.h"
#include "CanvasRenderManager.h"

#include "LightManager.h"
#include "CameraManager.h"
#include "CameraResolver.h"

#pragma once
enum class SceneState
{
	Unloaded,       // 로드 전
	Loading,        // 로드 중
	Loaded,         // 로드 완료, 실행 전
	Running,        // 실행 중
	Unloading       // 언로드 중
};

class BaseScene
{
public:
	BaseScene(std::string sceneName);
	virtual ~BaseScene();

protected:
	vector<GameObject*> m_gameObjects;
private:
	CameraResolver* m_cameraResolver;
	LightManager* m_lightManager;
	Collision* m_collisionDetecter;
	RenderManager* m_renderManager;
	WorldSpaceUIRenderManager* m_worldSpaceUIRenderManager;
	CanvasRenderManager* m_canvasRenderManager;
private:
	D3DClass* m_d3d;
	TextureShaderClass* m_textureShader;
	LightShaderClass* m_lightShader;

private:
	string m_sceneName;
	SceneState m_sceneState;
	int ID;

	mutex m_sceneMutex;
	unique_ptr<unique_lock<mutex>> m_sceneLock;
	HWND m_hwnd;
public:
	void LockScene()
	{
		m_sceneLock = make_unique<unique_lock<mutex>>(m_sceneMutex);
	}

	void UnlockScene()
	{
		m_sceneLock.reset();
	}

public:
	bool SceneInitialize();
	bool SceneStart();
	bool SceneEnd();

	const SceneState GetSceneState() const
	{
		return m_sceneState;
	}

	const int GetSceneID() const
	{
		return ID;
	}

	void SetSceneID(int id)
	{
		ID = id;
	}
private:
	LightClass& GetLights(int i);
	wstring StringToWString(const std::string& str);
public:
	void AddSceneRef(D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass, HWND);
	void CreateBaseObject();
	virtual void CreateGameObject() = 0;

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

	void PrevRender();
	bool WorldSpaceUIRender();
	bool Render();
	bool LightRender();
	bool UIRender();

	void Shutdown();

public:
	const string GetSceneName() const {	return m_sceneName;	}

	CameraResolver* GetCameraresolver() { return m_cameraResolver; }

	//const LightManager* GetLightManager() const { return m_lightManager; }
	LightManager* GetLightManager() { return m_lightManager; }

	//const Collision* GetCollision() const { return m_collisionDetecter; }
	Collision* GetCollision() { return m_collisionDetecter; }

	//const RenderManager* GetRenderManager() const { return m_renderManager; }
	RenderManager* GetRenderManager() { return m_renderManager; }

	//const WorldSpaceUIRenderManager* GetWorldSpaceUIRenderManager() const { return m_worldSpaceUIRenderManager; }
	WorldSpaceUIRenderManager* GetWorldSpaceUIRenderManager() { return m_worldSpaceUIRenderManager; }

	//const CanvasRenderManager* GetCanvasRenderManager() const { return m_canvasRenderManager; }
	CanvasRenderManager* GetCanvasRenderManager() { return m_canvasRenderManager; }

	//const D3DClass* GetD3DClass() const { return m_d3d; }
	D3DClass* GetD3DClass() { return m_d3d; }

	//const TextureShaderClass* GetTextureShaderClass() const { return m_textureShader; }
	TextureShaderClass* GetTextureShaderClass() { return m_textureShader; }

	//const LightShaderClass* GetLightShaderClass() const { return m_lightShader; }
	LightShaderClass* GetLightShaderClass() { return m_lightShader; }
};

#endif