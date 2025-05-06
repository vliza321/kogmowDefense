#include "ObjectClass.h"

ObjectClass::ObjectClass()
{
	m_cameraManager = 0;
	m_lightManager = 0;
}

ObjectClass::~ObjectClass()
{

}

void ObjectClass::CreateBaseObject()
{
	GameObject* CameraManagerObject = new GameObject(true, Tag::Camera, "CameraManager");
	CameraManagerObject->AddComponent<Transform>(XMFLOAT3(0,10,-10),XMFLOAT3(0,0,0), XMFLOAT3(0,0,0),XMFLOAT3(0,180 * 0.0174533f,0));
	CameraManagerObject->AddComponent<CameraManager>();
	m_cameraManager = CameraManagerObject->GetComponent<CameraManager>().get();
	RegistGameObject(CameraManagerObject);

	GameObject* LightSet = new GameObject(true, Tag::Default, "LightManager");
	LightSet->AddComponent<LightManager>();
	m_lightManager = LightSet->GetComponent<LightManager>().get();
	RegistGameObject(LightSet);

	GameObject* SkyDome = new GameObject(true, Tag::Default, "SkyDome");
	SkyDome->AddComponent<Transform>(XMFLOAT3(0, -10, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.1f, 0.1f, 0.1f), XMFLOAT3(0, 0, 0));
	SkyDome->AddComponent<Renderer>(L"./data/spacesphere.obj", L"./data/spacesphere.dds", 0);
	RegistGameObject(SkyDome);

	GameObject* Terrain0 = new GameObject(true, Tag::Default, "Terrain0");
	Terrain0->AddComponent<Renderer>(L"./data/1.obj", L"./data/1.dds", 0);
	Terrain0->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain0);

	GameObject* Terrain1 = new GameObject(true, Tag::Default, "Terrain1");
	Terrain1->AddComponent<Renderer>(L"./data/1-1.obj", L"./data/1.dds", 0);
	Terrain1->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain1);

	GameObject* Terrain2 = new GameObject(true, Tag::Default, "Terrain2");
	Terrain2->AddComponent<Renderer>(L"./data/2.obj", L"./data/2.dds", 0);
	Terrain2->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain2);

	GameObject* Terrain3 = new GameObject(true, Tag::Default, "Terrain3");
	Terrain3->AddComponent<Renderer>(L"./data/2-1.obj", L"./data/2.dds", 0);
	Terrain3->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain3);

	GameObject* Terrain4 = new GameObject(true, Tag::Default, "Terrain4");
	Terrain4->AddComponent<Renderer>(L"./data/3.obj", L"./data/3.dds", 0);
	Terrain4->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain4);

	GameObject* Terrain5 = new GameObject(true, Tag::Default, "Terrain5");
	Terrain5->AddComponent<Renderer>(L"./data/4.obj", L"./data/4.dds", 0);
	Terrain5->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain5);

	GameObject* Terrain6 = new GameObject(true, Tag::Default, "Terrain6");
	Terrain6->AddComponent<Renderer>(L"./data/5.obj", L"./data/5.dds", 0);
	Terrain6->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain6);

	GameObject* Terrain7 = new GameObject(true, Tag::Default, "Terrain7");
	Terrain7->AddComponent<Renderer>(L"./data/6.obj", L"./data/6.dds", 0);
	Terrain7->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain7);

	GameObject* Terrain8 = new GameObject(true, Tag::Default, "Terrain8");
	Terrain8->AddComponent<Renderer>(L"./data/7.obj", L"./data/7.dds", 0);
	Terrain8->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain8);

	GameObject* Terrain9 = new GameObject(true, Tag::Default, "Terrain9");
	Terrain9->AddComponent<Renderer>(L"./data/8.obj", L"./data/8.dds", 0);
	Terrain9->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain9);

	GameObject* Terrain10 = new GameObject(true, Tag::Default, "Terrain10");
	Terrain10->AddComponent<Renderer>(L"./data/9.obj", L"./data/9.dds", 0);
	Terrain10->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain10);

	GameObject* Terrain11 = new GameObject(true, Tag::Default, "Terrain11");
	Terrain11->AddComponent<Renderer>(L"./data/9-1.obj", L"./data/9.dds", 0);
	Terrain11->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain11);

	GameObject* Terrain12 = new GameObject(true, Tag::Default, "Terrain12");
	Terrain12->AddComponent<Renderer>(L"./data/10.obj", L"./data/10.dds", 0);
	Terrain12->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain12);

	GameObject* Terrain13 = new GameObject(true, Tag::Default, "Terrain13");
	Terrain13->AddComponent<Renderer>(L"./data/11.obj", L"./data/11.dds", 0);
	Terrain13->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain13);

	GameObject* Terrain14 = new GameObject(true, Tag::Default, "Terrain14");
	Terrain14->AddComponent<Renderer>(L"./data/12.obj", L"./data/12.dds", 0);
	Terrain14->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain14);

	GameObject* Terrain15 = new GameObject(true, Tag::Default, "Terrain15");
	Terrain15->AddComponent<Renderer>(L"./data/13.obj", L"./data/13.dds", 0);
	Terrain15->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain15);

	GameObject* Terrain16 = new GameObject(true, Tag::Default, "Terrain16");
	Terrain16->AddComponent<Renderer>(L"./data/14.obj", L"./data/14.dds", 0);
	Terrain16->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain16);

	GameObject* Terrain17 = new GameObject(true, Tag::Default, "Terrain17");
	Terrain17->AddComponent<Renderer>(L"./data/15.obj", L"./data/15.dds", 0);
	Terrain17->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain17);

	GameObject* Terrain18 = new GameObject(true, Tag::Default, "Terrain18");
	Terrain18->AddComponent<Renderer>(L"./data/16.obj", L"./data/16.dds", 0);
	Terrain18->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain18);

	GameObject* Terrain19 = new GameObject(true, Tag::Default, "Terrain19");
	Terrain19->AddComponent<Renderer>(L"./data/17.obj", L"./data/16.dds", 0);
	Terrain19->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain19);

	GameObject* Terrain20 = new GameObject(true, Tag::Default, "Terrain20");
	Terrain20->AddComponent<Renderer>(L"./data/foliage.obj", L"./data/foliage.dds", 0);
	Terrain20->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain20);

	GameObject* Terrain21 = new GameObject(true, Tag::Default, "Terrain21");
	Terrain21->AddComponent<Renderer>(L"./data/foliage1.obj", L"./data/foliage.dds", 0);
	Terrain21->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain21);

	GameObject* Terrain22 = new GameObject(true, Tag::Default, "Terrain22");
	Terrain22->AddComponent<Renderer>(L"./data/foliage2.obj", L"./data/foliage.dds", 0);
	Terrain22->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain22);

	GameObject* Terrain23 = new GameObject(true, Tag::Default, "Terrain23");
	Terrain23->AddComponent<Renderer>(L"./data/plant.obj", L"./data/plant.dds", 0);
	Terrain23->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain23);

	GameObject* Terrain24 = new GameObject(true, Tag::Default, "Terrain24");
	Terrain24->AddComponent<Renderer>(L"./data/props.obj", L"./data/props.dds", 0);
	Terrain24->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain24);

	GameObject* Terrain25 = new GameObject(true, Tag::Default, "Terrain25");
	Terrain25->AddComponent<Renderer>(L"./data/rock-blue.obj", L"./data/rock-blue.dds", 0);
	Terrain25->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain25);

	GameObject* Terrain26 = new GameObject(true, Tag::Default, "Terrain26");
	Terrain26->AddComponent<Renderer>(L"./data/rock-blue1.obj", L"./data/rock-blue.dds", 0);
	Terrain26->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain26);

	GameObject* Terrain27 = new GameObject(true, Tag::Default, "Terrain27");
	Terrain27->AddComponent<Renderer>(L"./data/rock-red.obj", L"./data/rock-red.dds", 0);
	Terrain27->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain27);

	GameObject* Terrain28 = new GameObject(true, Tag::Default, "Terrain28");
	Terrain28->AddComponent<Renderer>(L"./data/Campfire.obj", L"./data/Campfire.dds", 0);
	Terrain28->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain28);
}

void ObjectClass::CreateGameObject()
{
	GameObject* player = new GameObject(true, Tag::Player, "Player");
	player->AddComponent<Renderer>(L"./data/KogMaw.obj", L"./data/KogMaw.dds", 0);
	player->AddComponent<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
	player->AddComponent<SphereCollider>(0.3f, true);
	player->AddComponent<Player>();
	player->AddComponent<BulletManager>();
	RegistGameObject(player);

	GameObject* test = new GameObject(true, Tag::Default, "Cube");
	test->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test->AddComponent<Transform>(XMFLOAT3(3, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	//test->AddComponent<SphereCollider>(0.5f, true);
	test->AddComponent<BoxCollider>(true,XMFLOAT3(3,0,0),XMFLOAT3(0,0,0), XMFLOAT3(0.5f,0.5f,0.5f));
	RegistGameObject(test);

}

bool ObjectClass::InitializeSet(HWND hwnd, ID3D11Device* device)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeSet())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool ObjectClass::Initialize(HWND hwnd, ID3D11Device* device)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->Initialize())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool ObjectClass::InitializeRef(HWND hwnd, ID3D11Device* device)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeRef())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool ObjectClass::InitializeRender(HWND hwnd, ID3D11Device* device)
{
	if (!(GUIRenderManager::GetInstance().InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not GUI InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(RenderManager::GetInstance().InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Render InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(CanvasRenderManager::GetInstance().InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Canvas InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	return true;
}

bool ObjectClass::InitializeSynchronization(HWND hwnd, ID3D11Device* device)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->InitializeSynchronization())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

bool ObjectClass::PostInitialize(HWND hwnd, ID3D11Device* device)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (!gameObject->PostInitialize())
			{
				MessageBox(hwnd, L"Could not InitializeSet GameObjects.", L"Error", MB_OK);
				return false;
			}
		}
	}
	return true;
}

void ObjectClass::CollisionDetection()
{
	Collision::GetInstance().ProcessCollision();
}

void ObjectClass::FixedExecute()
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->FixedExecute();
			}
		}
	}
}

void ObjectClass::Execute()
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->Execute();
			}
		}
	}
}

void ObjectClass::LateExecute()
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->LateExecute();
			}
		}
	}
}

void ObjectClass::PostExecute()
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->PostExecute();
			}
		}
	}
	for (auto& v : m_gameOjbects)
	{
		for (auto gameObject = v.second.end(); gameObject != v.second.begin(); gameObject--)
		{
			if ((*gameObject)->isDestroy)
			{
				(*gameObject)->ApplyDestroy();
			}
		}
	}
}

bool ObjectClass::GUIRender(TextureShaderClass* textureShader, D3DClass* d3d, int sceneCounter)
{
	return GUIRenderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
}

bool ObjectClass::Render(LightShaderClass* lightShader, D3DClass* d3d, int)
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return RenderManager::GetInstance().RenderAll(lightShader, d3d, m_cameraManager->GetCamera(), m_lightManager, diffuseColor, lightPosition);
}

bool ObjectClass::UIRender(TextureShaderClass* textureShader, D3DClass* d3d, int)
{
	return CanvasRenderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
}

void ObjectClass::Shutdown()
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->active)
			{
				gameObject->Shutdown();
			}
		}
	}
}

LightClass& ObjectClass::GetLights(int i)
{
	return m_lightManager->GetLights(i);
}

GameObject* ObjectClass::Find(string name)
{
	for (auto& v : m_gameOjbects)
	{
		for (auto& gameObject : v.second)
		{
			if (gameObject->name == name)
			{
				return gameObject;
			}
		}
	}
	return nullptr;
}

GameObject* ObjectClass::FindObjectWithTag(Tag tag)
{
	if (m_gameOjbects[tag].size() != 0) return m_gameOjbects[tag].front();
	return nullptr;
}

vector<GameObject*> ObjectClass::FindObjectsWithTag(Tag tag)
{
	return m_gameOjbects[tag];
}

void ObjectClass::RegistGameObject(GameObject* Entity)
{
	m_gameOjbects[Entity->tag].push_back(Entity);
	Entity->SetRoot(this);
}

