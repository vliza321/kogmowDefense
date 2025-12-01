#include "TestScene2.h"


TestScene2::TestScene2()
	: GameScene(std::string("TestScene2"))
{

}

TestScene2::~TestScene2()
{

}

void TestScene2::CreateGameObject()
{
	GameObject* DirectionalLight = new GameObject(true, Tag::DirectionalLight, "DirectionalLight");
	DirectionalLight->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 00.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f),
		64.0f);
	RegistGameObject(DirectionalLight);

	GameObject* player = new GameObject(true, Tag::Player, "Player");
	player->AddComponent<Renderer>(L"./data/KogMaw.obj", L"./data/KogMaw.dds", 0);
	player->AddComponent<TestLoop>();
	player->AddComponent<Transform>
		(XMFLOAT3(7, 5, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.06f, 0.06f, 0.06f), XMFLOAT3(0, 0, 0));
	player->AddComponent<SceneChangerController>();
	RegistGameObject(player);

	GameObject* monster = new GameObject(true, Tag::Default, "monster");
	monster->AddComponent<Renderer>(L"./data/golem.obj", L"./data/golem.dds", 0);
	monster->AddComponent<TestLoop>();
	monster->AddComponent<Transform>
		(XMFLOAT3(7, 5.5f, 3), XMFLOAT3(0, XM_PI, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	RegistGameObject(monster);

	GameObject* Plane = new GameObject(true, Tag::Default, "Plane");
	Plane->AddComponent<Renderer>(L"./data/cube.obj", L"./data/stone.dds", 0);
	Plane->AddComponent<Transform>
		(XMFLOAT3(7, 5, 0), XMFLOAT3(0, XM_PI, 0), XMFLOAT3(300.0f, 0.01f, 300.f), XMFLOAT3(0, 0, 0));
	RegistGameObject(Plane);

	GameObject* CameraManagerObject = new GameObject(true, Tag::Camera, "CameraManager");
	CameraManagerObject->AddComponent<Transform>(XMFLOAT3(0.0f, 10.0f, -20.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0, 180 * 0.0174533f, 0));
	CameraManagerObject->AddComponent<BaseCamera>();
	RegistGameObject(CameraManagerObject);
	
	GameObject* monster1 = new GameObject(true, Tag::Default, "Wolf");
	monster1->AddComponent<Renderer>(L"./data/Wolf.obj", L"./data/Wolf.dds", 0);
	monster1->AddComponent<Transform>
		(XMFLOAT3(7, 5, -3), XMFLOAT3(0, XM_PI, 0), XMFLOAT3(0.1f, 0.1f, 0.1f), XMFLOAT3(0, 0, 0));
	monster1->AddComponent<TestLoop>();
	RegistGameObject(monster1);

	GameObject* Light1 = new GameObject(true, Tag::Light, "Light1");
	Light1->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f),
		XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(8.5f, 5.5f, 1.5f, 1.0f),
		32.0f);
	RegistGameObject(Light1);

	GameObject* Light2 = new GameObject(true, Tag::Light, "Light2");
	Light2->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f),
		XMFLOAT4(0.0f, 01.0f, 0.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(8.5f, 5.5f, -1.5f, 1.0f),
		32.0f);
	RegistGameObject(Light2);

	GameObject* Light3 = new GameObject(true, Tag::Light, "Light3");
	Light3->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(5.5f, 5.5f, 1.5f, 1.0f),
		32.0f);
	RegistGameObject(Light3);

	GameObject* Light4 = new GameObject(true, Tag::Light, "Light4");
	Light4->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(5.5f, 5.5f, -1.5f, 1.0f),
		32.0f);
	RegistGameObject(Light4);
}
