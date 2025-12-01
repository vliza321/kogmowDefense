#include "TestScene3.h"

TestScene3::TestScene3()
	: GameScene(std::string("TestScene3"))
{
}

TestScene3::~TestScene3()
{

}

void TestScene3::CreateGameObject()
{
	GameObject* DirectionalLight = new GameObject(true, Tag::DirectionalLight, "DirectionalLight");
	DirectionalLight->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 00.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f),
		128.0f);
	RegistGameObject(DirectionalLight);

	GameObject* SkyDome = new GameObject(true, Tag::Default, "SkyDome");
	SkyDome->AddComponent<Transform>(XMFLOAT3(0.0f, -10.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.1f, 0.1f, 0.1f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	SkyDome->AddComponent<Renderer>(L"./data/spacesphere.obj", L"./data/spacesphere.dds", 0);
	RegistGameObject(SkyDome);


	GameObject* Terrain0 = new GameObject(true, Tag::Default, "Terrain0");
	Terrain0->AddComponent<Renderer>(L"./data/1.obj", L"./data/1.dds", 0);
	Terrain0->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain0);

	GameObject* Terrain1 = new GameObject(true, Tag::Default, "Terrain1");
	Terrain1->AddComponent<Renderer>(L"./data/1-1.obj", L"./data/1.dds", 0);
	Terrain1->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain1);

	GameObject* Terrain2 = new GameObject(true, Tag::Default, "Terrain2");
	Terrain2->AddComponent<Renderer>(L"./data/2.obj", L"./data/2.dds", 0);
	Terrain2->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain2);

	GameObject* Terrain3 = new GameObject(true, Tag::Default, "Terrain3");
	Terrain3->AddComponent<Renderer>(L"./data/2-1.obj", L"./data/2.dds", 0);
	Terrain3->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain3);

	GameObject* Terrain4 = new GameObject(true, Tag::Default, "Terrain4");
	Terrain4->AddComponent<Renderer>(L"./data/3.obj", L"./data/3.dds", 0);
	Terrain4->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain4);

	GameObject* Terrain5 = new GameObject(true, Tag::Default, "Terrain5");
	Terrain5->AddComponent<Renderer>(L"./data/4.obj", L"./data/4.dds", 0);
	Terrain5->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain5);

	GameObject* Terrain6 = new GameObject(true, Tag::Default, "Terrain6");
	Terrain6->AddComponent<Renderer>(L"./data/5.obj", L"./data/5.dds", 0);
	Terrain6->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain6);

	GameObject* Terrain7 = new GameObject(true, Tag::Default, "Terrain7");
	Terrain7->AddComponent<Renderer>(L"./data/6.obj", L"./data/6.dds", 0);
	Terrain7->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain7);

	GameObject* Terrain8 = new GameObject(true, Tag::Default, "Terrain8");
	Terrain8->AddComponent<Renderer>(L"./data/7.obj", L"./data/7.dds", 0);
	Terrain8->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain8);

	GameObject* Terrain9 = new GameObject(true, Tag::Default, "Terrain9");
	Terrain9->AddComponent<Renderer>(L"./data/8.obj", L"./data/8.dds", 0);
	Terrain9->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Terrain9);

	GameObject* Terrain10 = new GameObject(true, Tag::Default, "Terrain10");
	Terrain10->AddComponent<Renderer>(L"./data/9.obj", L"./data/9.dds", 0);
	Terrain10->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain10);

	GameObject* Terrain11 = new GameObject(true, Tag::Default, "Terrain11");
	Terrain11->AddComponent<Renderer>(L"./data/9-1.obj", L"./data/9.dds", 0);
	Terrain11->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain11);

	GameObject* Terrain12 = new GameObject(true, Tag::Default, "Terrain12");
	Terrain12->AddComponent<Renderer>(L"./data/10.obj", L"./data/10.dds", 0);
	Terrain12->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain12);

	GameObject* Terrain13 = new GameObject(true, Tag::Default, "Terrain13");
	Terrain13->AddComponent<Renderer>(L"./data/11.obj", L"./data/11.dds", 0);
	Terrain13->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain13);

	GameObject* Terrain14 = new GameObject(true, Tag::Default, "Terrain14");
	Terrain14->AddComponent<Renderer>(L"./data/12.obj", L"./data/12.dds", 0);
	Terrain14->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain14);

	GameObject* Terrain15 = new GameObject(true, Tag::Default, "Terrain15");
	Terrain15->AddComponent<Renderer>(L"./data/13.obj", L"./data/13.dds", 0);
	Terrain15->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain15);

	GameObject* Terrain16 = new GameObject(true, Tag::Default, "Terrain16");
	Terrain16->AddComponent<Renderer>(L"./data/14.obj", L"./data/14.dds", 0);
	Terrain16->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain16);

	GameObject* Terrain17 = new GameObject(true, Tag::Default, "Terrain17");
	Terrain17->AddComponent<Renderer>(L"./data/15.obj", L"./data/15.dds", 0);
	Terrain17->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain17);

	GameObject* Terrain18 = new GameObject(true, Tag::Default, "Terrain18");
	Terrain18->AddComponent<Renderer>(L"./data/16.obj", L"./data/16.dds", 0);
	Terrain18->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain18);

	GameObject* Terrain19 = new GameObject(true, Tag::Default, "Terrain19");
	Terrain19->AddComponent<Renderer>(L"./data/17.obj", L"./data/16.dds", 0);
	Terrain19->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain19);

	GameObject* Terrain20 = new GameObject(true, Tag::Default, "Terrain20");
	Terrain20->AddComponent<Renderer>(L"./data/foliage.obj", L"./data/foliage.dds", 0);
	Terrain20->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain20);

	GameObject* Terrain21 = new GameObject(true, Tag::Default, "Terrain21");
	Terrain21->AddComponent<Renderer>(L"./data/foliage1.obj", L"./data/foliage.dds", 0);
	Terrain21->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain21);

	GameObject* Terrain22 = new GameObject(true, Tag::Default, "Terrain22");
	Terrain22->AddComponent<Renderer>(L"./data/foliage2.obj", L"./data/foliage.dds", 0);
	Terrain22->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain22);

	GameObject* Terrain23 = new GameObject(true, Tag::Default, "Terrain23");
	Terrain23->AddComponent<Renderer>(L"./data/plant.obj", L"./data/plant.dds", 0);
	Terrain23->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain23);

	GameObject* Terrain24 = new GameObject(true, Tag::Default, "Terrain24");
	Terrain24->AddComponent<Renderer>(L"./data/props.obj", L"./data/props.dds", 0);
	Terrain24->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain24);

	GameObject* Terrain25 = new GameObject(true, Tag::Default, "Terrain25");
	Terrain25->AddComponent<Renderer>(L"./data/rock-blue.obj", L"./data/rock-blue.dds", 0);
	Terrain25->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain25);

	GameObject* Terrain26 = new GameObject(true, Tag::Default, "Terrain26");
	Terrain26->AddComponent<Renderer>(L"./data/rock-blue1.obj", L"./data/rock-blue.dds", 0);
	Terrain26->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain26);

	/*GameObject* Terrain27 = new GameObject(true, Tag::Default, "Terrain27");
	Terrain27->AddComponent<Renderer>(L"./data/rock-red.obj", L"./data/rock-red.dds", 0);
	Terrain27->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain27);*/


	GameObject* player = new GameObject(true, Tag::Player, "Player");
	player->AddComponent<Renderer>(L"./data/KogMaw.obj", L"./data/KogMaw.dds", 0);
	player->AddComponent<Transform>
		(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
	player->AddComponent<SphereCollider>(0.3f, true);
	player->AddComponent<TestPlayer>();
	player->AddComponent<SceneChangerController>();
	RegistGameObject(player);


	GameObject* CameraManagerObject = new GameObject(true, Tag::Camera, "CameraManager");
	CameraManagerObject->AddComponent<Transform>(XMFLOAT3(0.0f, 10.0f, -20.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0, 180 * 0.0174533f, 0));
	CameraManagerObject->AddComponent<CameraManager>();
	CameraManagerObject->AddComponent<ThirdPersonCamera>();
	RegistGameObject(CameraManagerObject);

	int lightcount = 24;
	const int segment = lightcount / 3;

	for (int i = 0; i < lightcount; i++)
	{
		float degree = (360.0f / lightcount) * i;
		float rad = degree * (XM_PI / 180.0f);

		float x = 5.5f * std::cos(rad);
		float z = 5.5f * std::sin(rad);

		int phase = i / segment;         
		float t = (i % segment) / (float)(segment - 1); 

		float r = 0, g = 0, b = 0;

		if (phase == 0) {
			r = 1.0f - t;
			g = t;
			b = 0;
		}
		else if (phase == 1) {
			g = 1.0f - t;
			b = t;
			r = 0;
		}
		else {
			b = 1.0f - t;
			r = t;
			g = 0;
		}

		GameObject* Light12 = new GameObject(true, Tag::Light, "Light" + std::to_string(i));
		Light12->AddComponent<LightClass>(
			XMFLOAT3(1.0f, 0.0f, 1.0f),
			XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f),
			XMFLOAT4(r, g, b, 1.0f),
			XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
			XMFLOAT4(x + 2.5f, 0.35, z + 1.1f, 1.0f),
			32.0f);

		RegistGameObject(Light12);
	}
}
