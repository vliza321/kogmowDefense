#include "BaseScene.h"
#include "graphicsclass.h"
#include "GameScene.h"
#include "atlstr.h"

BaseScene::BaseScene(string sceneName) : m_sceneState(SceneState::Unloaded), m_sceneName(sceneName)
{
	m_renderManager = 0;
	m_worldSpaceUIRenderManager = 0;
	m_canvasRenderManager = 0;

	m_cameraResolver = 0;
	m_lightManager = 0;

	m_collisionDetecter = 0;

	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;
}

BaseScene::~BaseScene()
{
	this->Shutdown();
	m_renderManager = 0;
	m_worldSpaceUIRenderManager = 0;
	m_canvasRenderManager = 0;

	m_cameraResolver = 0;
	m_lightManager = 0;

	m_collisionDetecter = 0;

	m_d3d = 0;
	m_textureShader = 0;
	m_lightShader = 0;

	m_sceneLock.reset();
}


bool BaseScene::SceneInitialize()
{
	bool result = true;

	m_sceneState = SceneState::Loading;

	m_renderManager = new RenderManager();
	if (!m_renderManager)
	{
		return false;
	}

	m_worldSpaceUIRenderManager = new WorldSpaceUIRenderManager();
	if (!m_worldSpaceUIRenderManager)
	{
		return false;
	}

	m_canvasRenderManager = new CanvasRenderManager();
	if (!m_canvasRenderManager)
	{
		return false;
	}

	m_collisionDetecter = new Collision();
	if (!m_collisionDetecter)
	{
		return false;
	}

	return true;
}

void BaseScene::CreateBaseObject()
{
	GameScene* gameScene = dynamic_cast<GameScene*>(this);

	GameObject* AllCameraResolver = new GameObject(true, Tag::Default, "CameraResolver");
	AllCameraResolver->AddComponent<CameraResolver>();
	m_cameraResolver = AllCameraResolver->GetComponent<CameraResolver>().get();
	m_gameObjects.push_back(AllCameraResolver);

	AllCameraResolver->SetRoot(gameScene);
	AllCameraResolver->SetParent(nullptr);
	AllCameraResolver->SetObjectID(m_gameObjects.size());

	GameObject* LightSet = new GameObject(true, Tag::Default, "LightManager");
	LightSet->AddComponent<LightManager>();
	m_lightManager = LightSet->GetComponent<LightManager>().get();
	m_gameObjects.push_back(LightSet);
	
	LightSet->SetRoot(gameScene);
	LightSet->SetParent(nullptr);
	LightSet->SetObjectID(m_gameObjects.size());
}

void BaseScene::AddSceneRef(D3DClass* d3dclass, LightShaderClass* lightshaderclass, TextureShaderClass* textureshaderclass, HWND hwnd)
{
	m_d3d = d3dclass;
	m_lightShader = lightshaderclass;
	m_textureShader = textureshaderclass;
	m_hwnd = hwnd;
}

bool BaseScene::SceneStart()
{
	if (m_sceneState == SceneState::Loaded)
	{
		m_sceneState = SceneState::Running;
	}
	else return false;
	return true;
}

bool BaseScene::SceneEnd()
{
	LockScene();
	Shutdown();
	UnlockScene(); 
	return true;
}

bool BaseScene::Render()
{
	return m_renderManager->RenderAll(m_textureShader, m_d3d, m_cameraResolver->GetViewMatrix());
}

void BaseScene::PrevRender()
{
	m_cameraResolver->PrevRender();
	m_lightManager->PrevRender();
}

bool BaseScene::WorldSpaceUIRender()
{
	return m_worldSpaceUIRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraResolver->GetViewMatrix());
}

bool BaseScene::LightRender()
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return m_renderManager->RenderAll(m_lightShader, m_d3d, m_cameraResolver->GetCamera(), m_lightManager, diffuseColor, lightPosition);
}

bool BaseScene::UIRender()
{
	return m_canvasRenderManager->RenderAll(m_textureShader, m_d3d, m_cameraResolver->GetViewMatrix() );
}

LightClass& BaseScene::GetLights(int i)
{
	return m_lightManager->GetLights(i);
}

bool BaseScene::InitializeSet()
{
	for (auto& v : m_gameObjects)
	{
		v->InitializeSet();
	}

	return true;
}

bool BaseScene::Initialize()
{
	for (auto& v : m_gameObjects)
	{
		v->Initialize();
	}


	return true;
}

bool BaseScene::InitializeRef()
{
	for (auto& v : m_gameObjects)
	{
		if (!v->InitializeRef())
		{
			wstring ws = StringToWString(v->name);
			MessageBox(m_hwnd, ws.c_str(), L"Error", MB_OK);
		}
	}

	return true;
}

wstring BaseScene::StringToWString(const std::string& str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0,
		str.c_str(), (int)str.size(), NULL, 0);

	std::wstring wstr(size_needed, 0);

	MultiByteToWideChar(CP_UTF8, 0,
		str.c_str(), (int)str.size(), &wstr[0], size_needed);

	return wstr;
}

bool BaseScene::InitializeRender()
{
	
	if (!(m_worldSpaceUIRenderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(m_hwnd, L"Could not GUI InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_canvasRenderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(m_hwnd, L"Could not Canvas InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(m_renderManager->InitializeRender(m_d3d->GetDevice())))
	{
		MessageBox(m_hwnd, L"Could not Render InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	return true;
}

bool BaseScene::InitializeSynchronization()
{
	for (auto& v : m_gameObjects)
	{
		v->InitializeSynchronization();
	}

	return true;
}

bool BaseScene::PostInitialize()
{
	for (auto& v : m_gameObjects)
	{
		v->PostInitialize();
	}

	m_sceneState = SceneState::Loaded;
	return true;
}

void BaseScene::CollisionDetection()
{
	m_collisionDetecter->ProcessCollision();
}

void BaseScene::FixedExecute()
{
	for (auto& v : m_gameObjects)
	{
		if(v->active) v->FixedExecute();
	}
}

void BaseScene::Execute()
{
	for (auto& v : m_gameObjects)
	{
		if (v->active) v->Execute();
	}
}

void BaseScene::LateExecute()
{
	for (auto& go : m_gameObjects)
	{
		if (go->active) go->LateExecute();
	}
}

void BaseScene::PostExecute()
{
	for (auto& v : m_gameObjects)
	{
		if (v->active) v->PostExecute();
	}
	for (int i = (int)m_gameObjects.size() - 1; i >= 0; i--)
	{
		GameObject* obj = m_gameObjects[i];

		if (obj->isDestroy)
		{
			obj->ApplyDestroy();
			delete obj;

			// 벡터에서 제거
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
	}
}

void BaseScene::Shutdown()
{
	m_sceneState = SceneState::Unloading;
	for (auto& v : m_gameObjects)
	{
		v->Shutdown();
	}
	m_gameObjects.clear();

	
	if (m_cameraResolver != 0)
	{
		m_cameraResolver = 0;
	}
	if (m_lightManager != 0)
	{
		m_lightManager = 0;
	}
	if (m_collisionDetecter != 0)
	{
		m_collisionDetecter->Shutdown();
		delete m_collisionDetecter;
		m_collisionDetecter = 0;
	}
	if (m_renderManager != 0)
	{
		m_renderManager->Shutdown();
		delete m_renderManager;
		m_renderManager = 0;
	}
	if (m_worldSpaceUIRenderManager != 0)
	{
		m_worldSpaceUIRenderManager->Shutdown();
		delete m_worldSpaceUIRenderManager;
		m_worldSpaceUIRenderManager = 0;
	}
	if (m_canvasRenderManager != 0)
	{
		m_canvasRenderManager->Shutdown();
		delete m_canvasRenderManager;
		m_canvasRenderManager = 0;
	}

	m_sceneState = SceneState::Unloaded;
}