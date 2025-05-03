#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

#include <vector>
#include <map>
#include <d3d11.h>
#include <directxmath.h>

#include "textureshaderclass.h"
#include "d3dclass.h"
#include "lightshaderclass.h"

#include "Component.h"
#include "GameObject.h"
#include "CameraObject.h"

#include "RenderManager.h"
#include "GUIRenderManager.h"
#include "CanvasRenderManager.h"

#include "LightManager.h"
#include "lightclass.h"

#include "ImageUI.h"
#include "Collision.h"
#include "ColliderType.h"

#include "CameraManager.h"
#include "Player.h"

class ObjectClass
{
public:

	ObjectClass();
	~ObjectClass();


public:
	void CreateBaseObject();
	void CreateGameObject();

	bool InitializeSet(HWND hwnd, ID3D11Device* device);
	bool Initialize(HWND hwnd, ID3D11Device* device);
	bool InitializeRef(HWND hwnd, ID3D11Device* device);
	bool InitializeRender(HWND hwnd, ID3D11Device* device);
	bool InitializeSynchronization(HWND hwnd, ID3D11Device* device);
	bool PostInitialize(HWND hwnd, ID3D11Device* device);

	void CollisionDetection();

	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

	bool GUIRender(TextureShaderClass*, D3DClass*, int);
	bool Render(LightShaderClass*, D3DClass*, int);
	bool UIRender(TextureShaderClass*, D3DClass*, int);
	
	void Shutdown();
public:
	LightClass& GetLights(int i);

private:
	map<Tag, vector<GameObject*>> m_gameOjbects;

public:
	GameObject* Find(string);
	GameObject* FindObjectWithTag(Tag);
	vector<GameObject*> FindObjectsWithTag(Tag);
private:
	void RegistGameObject(GameObject*);
private:
	CameraManager* m_cameraManager;
	LightManager* m_lightManager;
};

#endif