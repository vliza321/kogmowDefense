#ifndef _Scene_H
#define _Scene_H

#include <string>
#include <vector>
#include <map>
#include <d3d11.h>
#include <directxmath.h>

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

class Scene
{
public:
	Scene(std::string sceneName);
	~Scene();
	void SceneStart();
	void SceneEnd();

	SceneState GetSceneState()
	{
		return m_sceneState;
	}
public:
	virtual void CreateBaseObject() = 0;
	virtual void CreateGameObject() = 0;

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

	void Shutdown();

protected:
	unordered_map<Tag, vector<GameObject*>> m_gameObjects;
public:
	GameObject* Find(std::string);
	GameObject* FindObjectWithTag(Tag);
	vector<GameObject*> FindObjectsWithTag(Tag);
protected:
	void RegistGameObject(GameObject*);
	LightClass& GetLights(int i);
protected:
	CameraManager* m_cameraManager;
	LightManager* m_lightManager;
protected:
	Collision* m_collisionDetecter;
	RenderManager* m_renderManager;
	WorldSpaceUIRenderManager* m_worldSpaceUIRenderManager;
	CanvasRenderManager* m_canvasRenderManager;

private:
	string m_sceneName;
	SceneState m_sceneState;

public:
	const string GetSceneName() const {	return m_sceneName;	}

	const CameraManager* GetCameraManager() const { return m_cameraManager; }
	CameraManager* GetCameraManager() { return m_cameraManager; }

	const LightManager* GetLightManager() const { return m_lightManager; }
	LightManager* GetLightManager() { return m_lightManager; }

	const Collision* GetCollision() const { return m_collisionDetecter; }
	Collision* GetCollision() { return m_collisionDetecter; }

	const RenderManager* GetRenderManager() const { return m_renderManager; }
	RenderManager* GetRenderManager() { return m_renderManager; }

	const WorldSpaceUIRenderManager* GetWorldSpaceUIRenderManager() const { return m_worldSpaceUIRenderManager; }
	WorldSpaceUIRenderManager* GetWorldSpaceUIRenderManager() { return m_worldSpaceUIRenderManager; }

	const CanvasRenderManager* GetCanvasRenderManager() const { return m_canvasRenderManager; }
	CanvasRenderManager* GetCanvasRenderManager() { return m_canvasRenderManager; }

};

#endif
