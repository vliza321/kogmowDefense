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
	vector<GameObject*> m_vGameObjects;
protected:
	CameraManager* m_cameraManager;
	LightManager* m_lightManager;
protected:
	Collision* m_collisionDetecter;
	RenderManager* m_renderManager;
	WorldSpaceUIRenderManager* m_worldSpaceUIRenderManager;
	CanvasRenderManager* m_canvasRenderManager;

	D3DClass* m_d3d;
	TextureShaderClass* m_textureShader;
	LightShaderClass* m_lightShader;
private:
	string m_sceneName;
	SceneState m_sceneState;
	int ID;

	mutex m_sceneMutex;
	unique_ptr<unique_lock<mutex>> m_sceneLock;

public:
	void LockScene()
	{
		m_sceneLock = make_unique<unique_lock<mutex>>(m_sceneMutex);
	}

	void UnlockScne()
	{
		m_sceneLock.reset();
	}

public:
	bool SceneInitialize(int, int, HWND);
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
protected:
	LightClass& GetLights(int i);
public:
	void AddSceneRef(D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass);
	virtual void CreateBaseObject() = 0;
	virtual void CreateGameObject() = 0;

	bool InitializeSet(HWND);
	bool Initialize(HWND);
	bool InitializeRef(HWND);
	bool InitializeRender(HWND);
	bool InitializeSynchronization(HWND);
	bool PostInitialize(HWND);

	void CollisionDetection();

	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

	bool WorldSpaceUIRender();
	bool Render();
	bool LightRender();
	bool UIRender();

	void Shutdown();

public:
	const string GetSceneName() const {	return m_sceneName;	}

	//const CameraManager* GetCameraManager() const { return m_cameraManager; }
	CameraManager* GetCameraManager() { return m_cameraManager; }

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
