#include "ObjectClass.h"

ObjectClass::ObjectClass()
	: GameScene(std::string("PlayScene"))
{
}

ObjectClass::~ObjectClass()
{

}

void ObjectClass::CreateGameObject()
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

	GameObject* Terrain27 = new GameObject(true, Tag::Default, "Terrain27");
	Terrain27->AddComponent<Renderer>(L"./data/rock-red.obj", L"./data/rock-red.dds", 0);
	Terrain27->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain27);

	GameObject* Terrain28 = new GameObject(true, Tag::Default, "Terrain28");
	Terrain28->AddComponent<Renderer>(L"./data/Campfire.obj", L"./data/Campfire.dds", 0);
	Terrain28->AddComponent<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.2f, 0.2f, 0.2f), XMFLOAT3(0.0f, 0.0f, 0.0f));
	RegistGameObject(Terrain28);

	GameObject* bluetower1 = new GameObject(true, Tag::Default, "bluetower1");
	//bluetower1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower1->AddComponent<Transform>(XMFLOAT3(9.20f, 0.0f, 6.20f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower1->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower1);

	GameObject* bluetower2 = new GameObject(true, Tag::Default, "bluetower2");
	//blue2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower2->AddComponent<Transform>(XMFLOAT3(29.540f, 0, -12.050f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower2->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower2);

	GameObject* bluetower3 = new GameObject(true, Tag::Default, "bluetower3");
	//bluetower3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower3->AddComponent<Transform>(XMFLOAT3(29.60f, 0, 5.080f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower3->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower3);

	GameObject* bluetower4 = new GameObject(true, Tag::Default, "bluetower4");
	//blue4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower4->AddComponent<Transform>(XMFLOAT3(28.90f, 0, 14.870f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower4->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower4);

	GameObject* bluetower5 = new GameObject(true, Tag::Default, "bluetower5");
	//blue5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower5->AddComponent<Transform>(XMFLOAT3(20.40f, 0, 18.90f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower5->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower5);

	GameObject* bluetower6 = new GameObject(true, Tag::Default, "bluetower6");
	//bluetower6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower6->AddComponent<Transform>(XMFLOAT3(13.780f, 0, 13.750f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower6->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower6);

	GameObject* bluetower7 = new GameObject(true, Tag::Default, "bluetower7");
	//bluetower7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower7->AddComponent<Transform>(XMFLOAT3(16.50f, 0, 27.370f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower7->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower7);

	GameObject* bluetower8 = new GameObject(true, Tag::Default, "bluetower8");
	//bluetower8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower8->AddComponent<Transform>(XMFLOAT3(6.620f, 0, 27.90f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower8->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower8);

	GameObject* bluetower9 = new GameObject(true, Tag::Default, "bluetower9");
	//bluetower9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluetower9->AddComponent<Transform>(XMFLOAT3(-10, 0, 28), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	bluetower9->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(bluetower9);

	GameObject* redtower1 = new GameObject(true, Tag::Default, "redtower1");
	//redtower1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower1->AddComponent<Transform>(XMFLOAT3(-4.10f, 0, -4.00f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower1->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower1);

	GameObject* redtower2 = new GameObject(true, Tag::Default, "redtower2");
	//redtower2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower2->AddComponent<Transform>(XMFLOAT3(-8.70f, 0, -11.750f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower2->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower2);

	GameObject* redtower3 = new GameObject(true, Tag::Default, "redtower3");
	//redtower3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower3->AddComponent<Transform>(XMFLOAT3(-15.110f, 0, -16.560f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower3->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower3);

	GameObject* redtower4 = new GameObject(true, Tag::Default, "redtower4");
	//redtower4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower4->AddComponent<Transform>(XMFLOAT3(-23.830f, 0, -13.00f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower4->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower4);

	GameObject* redtower5 = new GameObject(true, Tag::Default, "redtower5");
	//redtower5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower5->AddComponent<Transform>(XMFLOAT3(-24.50f, 0, -3.1800f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower5->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower5);

	GameObject* redtower6 = new GameObject(true, Tag::Default, "redtower6");
	//redtower6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower6->AddComponent<Transform>(XMFLOAT3(-24.50f, 0, 13.60f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower6->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower6);

	GameObject* redtower7 = new GameObject(true, Tag::Default, "redtower7");
	//redtower7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower7->AddComponent<Transform>(XMFLOAT3(-11.250f, 0, -25.30f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower7->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower7);

	GameObject* redtower8 = new GameObject(true, Tag::Default, "redtower8");
	//redtower8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower8->AddComponent<Transform>(XMFLOAT3(-1.630f, 0, -26.020f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower8->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower8);

	GameObject* redtower9 = new GameObject(true, Tag::Default, "redtower9");
	//redtower9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	redtower9->AddComponent<Transform>(XMFLOAT3(15.250f, 0, -26.110f), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	redtower9->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(redtower9);

	GameObject* bluenexus = new GameObject(true, Tag::Default, "bluenexus");
	//bluenexus->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluenexus->AddComponent<Transform>(XMFLOAT3(25.880f, 0, 24.130f), XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2), XMFLOAT3(0, 0, 0));
	bluenexus->AddComponent<SphereCollider>(2.6f, true);
	RegistGameObject(bluenexus);

	GameObject* rednexus = new GameObject(true, Tag::Default, "rednexus");
	//rednexus->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	rednexus->AddComponent<Transform>(XMFLOAT3(-20.50f, 0, -22.230f), XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2), XMFLOAT3(0, 0, 0));
	rednexus->AddComponent<SphereCollider>(2.6f, true);
	RegistGameObject(rednexus);

	GameObject* test1 = new GameObject(true, Tag::Default, "test1");
	//test1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test1->AddComponent<Transform>(XMFLOAT3(8.20f, 0.50f, 0), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test1->AddComponent<BoxCollider>(true, XMFLOAT3(8.20f, 0.50f, 0), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(02.0f, 0.2f, 0.5f));
	RegistGameObject(test1);

	GameObject* test2 = new GameObject(true, Tag::Default, "test2");
	//test2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test2->AddComponent<Transform>(XMFLOAT3(3.60f, 0.50f, -4.50f), XMFLOAT3(0, 47 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test2->AddComponent<BoxCollider>(true, XMFLOAT3(3.60f, 0.50f, -4.50f), XMFLOAT3(0, 47 * XM_PI / 180.0f, 0), XMFLOAT3(02.0f, 0.2f, 0.5f));
	RegistGameObject(test2);

	GameObject* test3 = new GameObject(true, Tag::Default, "test3");
	//test3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test3->AddComponent<Transform>(XMFLOAT3(1.250f, 0.50f, 6.70f), XMFLOAT3(0, 48 * XM_PI / 180.0f, 0), XMFLOAT3(4.40f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test3->AddComponent<BoxCollider>(true, XMFLOAT3(1.250f, 0.50f, 6.70f), XMFLOAT3(0, 48 * XM_PI / 180.0f, 0), XMFLOAT3(02.2f, 0.2f, 0.5f));
	RegistGameObject(test3);

	GameObject* test4 = new GameObject(true, Tag::Default, "test4");
	//test4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test4->AddComponent<Transform>(XMFLOAT3(-3.40f, 0.50f, 2.10f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(4.40f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test4->AddComponent<BoxCollider>(true, XMFLOAT3(-3.40f, 0.50f, 2.10f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(02.2f, 0.2f, 0.5f));
	RegistGameObject(test4);

	GameObject* test5 = new GameObject(true, Tag::Default, "test5");
	//test5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test5->AddComponent<Transform>(XMFLOAT3(-6.110f, 0.50f, -2.90f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(4.60f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test5->AddComponent<BoxCollider>(true, XMFLOAT3(-6.110f, 0.50f, -2.90f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test5);

	GameObject* test6 = new GameObject(true, Tag::Default, "test6");
	//test6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test6->AddComponent<Transform>(XMFLOAT3(-6.000f, 0.50f, -1.800f), XMFLOAT3(0, -70 * XM_PI / 180.0f, 0), XMFLOAT3(2.50f, 0.40f, 1.600f), XMFLOAT3(0, 0, 0));
	test6->AddComponent<BoxCollider>(true, XMFLOAT3(-6.000f, 0.50f, -1.80f), XMFLOAT3(0, -70 * XM_PI / 180.0f, 0), XMFLOAT3(01.25f, 0.2f, 0.80f));
	RegistGameObject(test6);

	GameObject* test7 = new GameObject(true, Tag::Default, "test7");
	//test7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test7->AddComponent<Transform>(XMFLOAT3(-7.20f, 0.50f, -2.600f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(3.200f, 0.40f, 0.700f), XMFLOAT3(0, 0, 0));
	test7->AddComponent<BoxCollider>(true, XMFLOAT3(-7.20f, 0.50f, -2.600f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(01.6f, 0.2f, 0.35f));
	RegistGameObject(test7);

	GameObject* test8 = new GameObject(true, Tag::Default, "test8");
	//test8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test8->AddComponent<Transform>(XMFLOAT3(11.30f, 0.50f, 4.90f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(4.60f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test8->AddComponent<BoxCollider>(true, XMFLOAT3(11.30f, 0.50f, 4.90f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test8);

	GameObject* test9 = new GameObject(true, Tag::Default, "test9");
	//test9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test9->AddComponent<Transform>(XMFLOAT3(11.20f, 0.50f, 3.90f), XMFLOAT3(0, -63 * XM_PI / 180.0f, 0), XMFLOAT3(2.60f, 0.40f, 1.600f), XMFLOAT3(0, 0, 0));
	test9->AddComponent<BoxCollider>(true, XMFLOAT3(11.20f, 0.50f, 3.90f), XMFLOAT3(0, -63 * XM_PI / 180.0f, 0), XMFLOAT3(01.3f, 0.2f, 0.80f));
	RegistGameObject(test9);

	GameObject* test10 = new GameObject(true, Tag::Default, "test10");
	//test10->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test10->AddComponent<Transform>(XMFLOAT3(12.170f, 0.50f, 4.570f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(3.200f, 0.40f, 0.700f), XMFLOAT3(0, 0, 0));
	test10->AddComponent<BoxCollider>(true, XMFLOAT3(12.170f, 0.50f, 4.570f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(01.6f, 0.2f, 0.35f));
	RegistGameObject(test10);

	GameObject* test11 = new GameObject(true, Tag::Default, "test11");
	//test11->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test11->AddComponent<Transform>(XMFLOAT3(7.30f, 0.50f, 10.60f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(4.60f, 0.40f, 0.70f), XMFLOAT3(0, 0, 0));
	test11->AddComponent<BoxCollider>(true, XMFLOAT3(7.30f, 0.50f, 10.60f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test11);

	GameObject* test12 = new GameObject(true, Tag::Default, "test12");
	//test12->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test12->AddComponent<Transform>(XMFLOAT3(6.170f, 0.50f, 12.640f), XMFLOAT3(0, -75 * XM_PI / 180.0f, 0), XMFLOAT3(4.800f, 0.40f, 0.900f), XMFLOAT3(0, 0, 0));
	test12->AddComponent<BoxCollider>(true, XMFLOAT3(6.170f, 0.50f, 12.640f), XMFLOAT3(0, -75 * XM_PI / 180.0f, 0), XMFLOAT3(02.4f, 0.2f, 0.45f));
	RegistGameObject(test12);

	GameObject* test13 = new GameObject(true, Tag::Default, "test13");
	//test13->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test13->AddComponent<Transform>(XMFLOAT3(7.050f, 0.50f, 11.90f), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(3.00f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test13->AddComponent<BoxCollider>(true, XMFLOAT3(7.050f, 0.50f, 11.90f), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.4f));
	RegistGameObject(test13);

	GameObject* test14 = new GameObject(true, Tag::Default, "test14");
	//test14->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test14->AddComponent<Transform>(XMFLOAT3(8.50f, 0.50f, 11.40f), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(1.800f, 0.40f, 0.70f), XMFLOAT3(0, 0, 0));
	test14->AddComponent<BoxCollider>(true, XMFLOAT3(8.50f, 0.50f, 11.40f), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(00.9f, 0.2f, 0.35f));
	RegistGameObject(test14);

	GameObject* test15 = new GameObject(true, Tag::Default, "test15");
	//test15->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test15->AddComponent<Transform>(XMFLOAT3(4.830f, 0.50f, 9.40f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.000f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test15->AddComponent<BoxCollider>(true, XMFLOAT3(4.830f, 0.50f, 9.40f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(01.0f, 0.2f, 0.6f));
	RegistGameObject(test15);

	GameObject* test16 = new GameObject(true, Tag::Default, "test16");
	//test16->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test16->AddComponent<Transform>(XMFLOAT3(3.00f, 0.50f, 10.70f), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(3.00f, 0.40f, 1.200f), XMFLOAT3(0, 0, 0));
	test16->AddComponent<BoxCollider>(true, XMFLOAT3(3.00f, 0.50f, 10.70f), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.6f));
	RegistGameObject(test16);

	GameObject* test17 = new GameObject(true, Tag::Default, "test17");
	//test17->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test17->AddComponent<Transform>(XMFLOAT3(11.10f, 0.50f, 17.20f), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(4.80f, 0.40f, 3.80f), XMFLOAT3(0, 0, 0));
	test17->AddComponent<BoxCollider>(true, XMFLOAT3(11.10f, 0.50f, 17.20f), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(02.4f, 0.2f, 01.9f));
	RegistGameObject(test17);

	GameObject* test18 = new GameObject(true, Tag::Default, "test18");
	//test18->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test18->AddComponent<Transform>(XMFLOAT3(10.230f, 0.50f, 19.280f), XMFLOAT3(0, -120 * XM_PI / 180.0f, 0), XMFLOAT3(1.20f, 0.40f, 3.0f), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(10.230f, 0.50f, 19.280f), XMFLOAT3(0, -120 * XM_PI / 180.0f, 0), XMFLOAT3(00.6f, 0.2f, 01.5f));
	RegistGameObject(test18);

	GameObject* test19 = new GameObject(true, Tag::Default, "test19");
	//test19->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test19->AddComponent<Transform>(XMFLOAT3(6.60f, 0.50f, 23.470f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.00f, 0.40f, 8.50f), XMFLOAT3(0, 0, 0));
	test19->AddComponent<BoxCollider>(true, XMFLOAT3(6.60f, 0.50f, 23.470f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 04.25f));
	RegistGameObject(test19);

	GameObject* test20 = new GameObject(true, Tag::Default, "test20");
	//test20->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test20->AddComponent<Transform>(XMFLOAT3(7.580f, 0.50f, 22.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.80f, 0.40f, 5.00f), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(7.580f, 0.50f, 22.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 02.5f));
	RegistGameObject(test20);

	GameObject* test21 = new GameObject(true, Tag::Default, "test21");
	//test21->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test21->AddComponent<Transform>(XMFLOAT3(7.80f, 0.50f, 22.20f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.60f, 0.40f, 3.30f), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(7.80f, 0.50f, 22.20f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.3f, 0.2f, 01.65f));
	RegistGameObject(test21);

	GameObject* test22 = new GameObject(true, Tag::Default, "test22");
	//test22->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test22->AddComponent<Transform>(XMFLOAT3(-6.10f, 0.50f, 23.440f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.200f, 0.40f, 9.20f), XMFLOAT3(0, 0, 0));
	test22->AddComponent<BoxCollider>(true, XMFLOAT3(-6.10f, 0.50f, 23.440f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 04.6f));
	RegistGameObject(test22);

	GameObject* test23 = new GameObject(true, Tag::Default, "test23");
	//test23->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test23->AddComponent<Transform>(XMFLOAT3(-6.40f, 0.50f, 22.60f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.80f, 0.40f, 6.80f), XMFLOAT3(0, 0, 0));
	test23->AddComponent<BoxCollider>(true, XMFLOAT3(-6.40f, 0.50f, 22.60f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 03.4f));
	RegistGameObject(test23);

	GameObject* test24 = new GameObject(true, Tag::Default, "test24");
	//test24->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test24->AddComponent<Transform>(XMFLOAT3(-3.740f, 0.50f, 22.60f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	test24->AddComponent<BoxCollider>(true, XMFLOAT3(-3.740f, 0.50f, 22.60f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 0.7f));
	RegistGameObject(test24);

	GameObject* test25 = new GameObject(true, Tag::Default, "test25");
	//test25->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test25->AddComponent<Transform>(XMFLOAT3(-7.740f, 0.50f, 22.20f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.80f, 0.40f, 3.40f), XMFLOAT3(0, 0, 0));
	test25->AddComponent<BoxCollider>(true, XMFLOAT3(-7.740f, 0.50f, 22.20f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.2f, 1.7f));
	RegistGameObject(test25);

	GameObject* test26 = new GameObject(true, Tag::Default, "test26");
	//test26->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test26->AddComponent<Transform>(XMFLOAT3(-6.900f, 0.50f, 20.80f), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(1.10f, 0.40f, 1.60f), XMFLOAT3(0, 0, 0));
	test26->AddComponent<BoxCollider>(true, XMFLOAT3(-6.900f, 0.50f, 20.80f), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(0.55f, 0.2f, 0.8f));
	RegistGameObject(test26);

	GameObject* test27 = new GameObject(true, Tag::Default, "test27");
	//test27->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test27->AddComponent<Transform>(XMFLOAT3(-0.40f, 0.50f, 19.20f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(3.00f, 0.40f, 1.0f), XMFLOAT3(0, 0, 0));
	test27->AddComponent<BoxCollider>(true, XMFLOAT3(-0.40f, 0.50f, 19.20f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(01.7f, 0.2f, 0.5f));
	RegistGameObject(test27);

	GameObject* test28 = new GameObject(true, Tag::Default, "test28");
	//test28->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test28->AddComponent<Transform>(XMFLOAT3(-1.10f, 0.50f, 17.40f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(1.40f, 0.40f, 1.80f), XMFLOAT3(0, 0, 0));
	test28->AddComponent<BoxCollider>(true, XMFLOAT3(-1.10f, 0.50f, 17.40f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(0.7f, 0.2f, 00.9f));
	RegistGameObject(test28);

	GameObject* test29 = new GameObject(true, Tag::Default, "test29");
	//test29->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test29->AddComponent<Transform>(XMFLOAT3(3.120f, 0.50f, 16.60f), XMFLOAT3(0, -35 * XM_PI / 180.0f, 0), XMFLOAT3(3.40f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test29->AddComponent<BoxCollider>(true, XMFLOAT3(3.120f, 0.50f, 16.60f), XMFLOAT3(0, -35 * XM_PI / 180.0f, 0), XMFLOAT3(01.7f, 0.2f, 0.4f));
	RegistGameObject(test29);

	GameObject* test30 = new GameObject(true, Tag::Default, "test30");
	//test30->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test30->AddComponent<Transform>(XMFLOAT3(0.880f, 0.50f, 16.180f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.80f, 0.40f, 2.00f), XMFLOAT3(0, 0, 0));
	test30->AddComponent<BoxCollider>(true, XMFLOAT3(0.880f, 0.50f, 16.180f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.2f, 01.0f));
	RegistGameObject(test30);

	GameObject* test31 = new GameObject(true, Tag::Default, "test31");
	//test31->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test31->AddComponent<Transform>(XMFLOAT3(2.480f, 0.50f, 16.60f), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(3.00f, 0.40f, 0.800f), XMFLOAT3(0, 0, 0));
	test31->AddComponent<BoxCollider>(true, XMFLOAT3(2.480f, 0.50f, 16.60f), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.4f));
	RegistGameObject(test31);

	GameObject* test32 = new GameObject(true, Tag::Default, "test32");
	//test32->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test32->AddComponent<Transform>(XMFLOAT3(-0.70f, 0.50f, 16.30f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(1.00f, 0.40f, 2.100f), XMFLOAT3(0, 0, 0));
	test32->AddComponent<BoxCollider>(true, XMFLOAT3(-0.70f, 0.50f, 16.30f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 01.05f));
	RegistGameObject(test32);

	GameObject* test33 = new GameObject(true, Tag::Default, "test33");
	//test33->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test33->AddComponent<Transform>(XMFLOAT3(-0.210f, 0.50f, 16.570f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 2.100f), XMFLOAT3(0, 0, 0));
	test33->AddComponent<BoxCollider>(true, XMFLOAT3(-0.210f, 0.50f, 16.570f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.05f));
	RegistGameObject(test33);

	GameObject* test34 = new GameObject(true, Tag::Default, "test34");
	//test34->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test34->AddComponent<Transform>(XMFLOAT3(-13, 0.50f, 21.40f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	test34->AddComponent<BoxCollider>(true, XMFLOAT3(-13, 0.50f, 21.40f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 0.7f));
	RegistGameObject(test34);

	GameObject* test35 = new GameObject(true, Tag::Default, "test35");
	//test35->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test35->AddComponent<Transform>(XMFLOAT3(-12.10f, 0.50f, 20.280f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1.00f, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	test35->AddComponent<BoxCollider>(true, XMFLOAT3(-12.10f, 0.50f, 20.280f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 0.7f));
	RegistGameObject(test35);

	GameObject* test36 = new GameObject(true, Tag::Default, "test36");
	//test36->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test36->AddComponent<Transform>(XMFLOAT3(-13.70f, 0.50f, 22.630f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.80f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test36->AddComponent<BoxCollider>(true, XMFLOAT3(-13.70f, 0.50f, 22.630f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 0.6f));
	RegistGameObject(test36);

	GameObject* test37 = new GameObject(true, Tag::Default, "test37");
	//test37->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test37->AddComponent<Transform>(XMFLOAT3(-13.80f, 0.50f, 22.060f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(0.80f, 0.40f, 1.60f), XMFLOAT3(0, 0, 0));
	test36->AddComponent<BoxCollider>(true, XMFLOAT3(-13.80f, 0.50f, 22.060f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 0.8f));
	RegistGameObject(test37);

	GameObject* test38 = new GameObject(true, Tag::Default, "test38");
	//test38->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test38->AddComponent<Transform>(XMFLOAT3(-7.10f, 0.50f, 15.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.20f, 0.40f, 4.20f), XMFLOAT3(0, 0, 0));
	test38->AddComponent<BoxCollider>(true, XMFLOAT3(-7.10f, 0.50f, 15.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 02.1f));
	RegistGameObject(test38);

	GameObject* test39 = new GameObject(true, Tag::Default, "test39");
	//test39->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test39->AddComponent<Transform>(XMFLOAT3(-8.40f, 0.50f, 16.70f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.20f, 0.40f, 3.40f), XMFLOAT3(0, 0, 0));
	test39->AddComponent<BoxCollider>(true, XMFLOAT3(-8.40f, 0.50f, 16.70f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 01.7f));
	RegistGameObject(test39);

	GameObject* test40 = new GameObject(true, Tag::Default, "test40");
	//test40->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test40->AddComponent<Transform>(XMFLOAT3(-9.60f, 0.50f, 16.50f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 2.80f), XMFLOAT3(0, 0, 0));
	test40->AddComponent<BoxCollider>(true, XMFLOAT3(-9.60f, 0.50f, 16.50f), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.4f));
	RegistGameObject(test40);

	GameObject* test41 = new GameObject(true, Tag::Default, "test41");
	//test41->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test41->AddComponent<Transform>(XMFLOAT3(-10.0f, 0.50f, 15.80f), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 2.80f), XMFLOAT3(0, 0, 0));
	test41->AddComponent<BoxCollider>(true, XMFLOAT3(-10.00f, 0.50f, 15.80f), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.4f));
	RegistGameObject(test41);

	GameObject* test42 = new GameObject(true, Tag::Default, "test42");
	//test42->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test42->AddComponent<Transform>(XMFLOAT3(-10.10f, 0.50f, 14.30f), XMFLOAT3(0, -105 * XM_PI / 180.0f, 0), XMFLOAT3(2.60f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test42->AddComponent<BoxCollider>(true, XMFLOAT3(-10.10f, 0.50f, 14.30f), XMFLOAT3(0, -105 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.2f, 00.3f));
	RegistGameObject(test42);

	GameObject* test43 = new GameObject(true, Tag::Default, "test43");
	//test43->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test43->AddComponent<Transform>(XMFLOAT3(-9.60f, 0.50f, 14.00f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(2.40f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test43->AddComponent<BoxCollider>(true, XMFLOAT3(-9.60f, 0.50f, 14.00f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.2f, 0.3f));
	RegistGameObject(test43);

	GameObject* test44 = new GameObject(true, Tag::Default, "test44");
	//test44->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test44->AddComponent<Transform>(XMFLOAT3(-4.110f, 0.50f, 13.50f), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(2.80f, 0.80f, 1.20f), XMFLOAT3(0, 0, 0));
	test44->AddComponent<BoxCollider>(true, XMFLOAT3(-4.110f, 0.50f, 13.50f), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.2f, 0.6f));
	RegistGameObject(test44);

	GameObject* test45 = new GameObject(true, Tag::Default, "test45");
	//test45->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test45->AddComponent<Transform>(XMFLOAT3(-4.890f, 0.50f, 15.00f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(2.40f, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	test45->AddComponent<BoxCollider>(true, XMFLOAT3(-4.890f, 0.50f, 15.00f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.2f, 0.7f));
	RegistGameObject(test45);

	GameObject* test46 = new GameObject(true, Tag::Default, "test46");
	//test46->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test46->AddComponent<Transform>(XMFLOAT3(-4.350f, 0.50f, 11.880f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(3.30f, 0.40f, 1.70f), XMFLOAT3(0, 0, 0));
	test46->AddComponent<BoxCollider>(true, XMFLOAT3(-4.350f, 0.50f, 11.880f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(01.65f, 0.2f, 0.85f));
	RegistGameObject(test46);

	GameObject* test47 = new GameObject(true, Tag::Default, "test47");
	//test47->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test47->AddComponent<Transform>(XMFLOAT3(-4.850f, 0.50f, 11.30f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test47->AddComponent<BoxCollider>(true, XMFLOAT3(-4.850f, 0.50f, 11.30f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(02.5f, 0.2f, 0.3f));
	RegistGameObject(test47);

	GameObject* test48 = new GameObject(true, Tag::Default, "test48");
	//test48->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test48->AddComponent<Transform>(XMFLOAT3(-6.00f, 0.50f, 10.60f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.30f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test48->AddComponent<BoxCollider>(true, XMFLOAT3(-6.00f, 0.50f, 10.60f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.15f, 0.2f, 00.4f));
	RegistGameObject(test48);

	GameObject* test49 = new GameObject(true, Tag::Default, "test49");
	//test49->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test49->AddComponent<Transform>(XMFLOAT3(-3.60f, 0.50f, 11.20f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(3.30f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test49->AddComponent<BoxCollider>(true, XMFLOAT3(-3.60f, 0.50f, 11.20f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.2f, 0.5f));
	RegistGameObject(test49);

	GameObject* test50 = new GameObject(true, Tag::Default, "test50");
	//test50->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test50->AddComponent<Transform>(XMFLOAT3(-3.10f, 0.50f, 12.80f), XMFLOAT3(0, 59 * XM_PI / 180.0f, 0), XMFLOAT3(3.30f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test50->AddComponent<BoxCollider>(true, XMFLOAT3(-3.10f, 0.50f, 12.80f), XMFLOAT3(0, 59 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.2f, 0.4f));
	RegistGameObject(test50);

	GameObject* test51 = new GameObject(true, Tag::Default, "test51");
	//test51->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test51->AddComponent<Transform>(XMFLOAT3(19.270f, 0.50f, 11.270f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(3.30f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test51->AddComponent<BoxCollider>(true, XMFLOAT3(19.270f, 0.50f, 11.270f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.2f, 0.4f));
	RegistGameObject(test51);

	GameObject* test52 = new GameObject(true, Tag::Default, "test52");
	//test52->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test52->AddComponent<Transform>(XMFLOAT3(16.90f, 0.50f, 11), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(3.60f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test52->AddComponent<BoxCollider>(true, XMFLOAT3(16.90f, 0.50f, 11), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.2f, 0.5f));
	RegistGameObject(test52);


	GameObject* test53 = new GameObject(true, Tag::Default, "test53");
	//test53->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test53->AddComponent<Transform>(XMFLOAT3(17.40f, 0.50f, 10.50f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test53->AddComponent<BoxCollider>(true, XMFLOAT3(17.40f, 0.50f, 10.50f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(2.0f, 0.2f, 0.5f));
	RegistGameObject(test53);

	GameObject* test54 = new GameObject(true, Tag::Default, "test54");
	//test54->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test54->AddComponent<Transform>(XMFLOAT3(18.80f, 0.50f, 11), XMFLOAT3(0, 10 * XM_PI / 180.0f, 0), XMFLOAT3(3.00f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test54->AddComponent<BoxCollider>(true, XMFLOAT3(18.80f, 0.50f, 11), XMFLOAT3(0, 10 * XM_PI / 180.0f, 0), XMFLOAT3(1.5f, 0.2f, 0.4f));
	RegistGameObject(test54);

	GameObject* test55 = new GameObject(true, Tag::Default, "test55");
	//test55->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test55->AddComponent<Transform>(XMFLOAT3(17.50f, 0.50f, 7.80f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.40f, 0.70f), XMFLOAT3(0, 0, 0));
	test55->AddComponent<BoxCollider>(true, XMFLOAT3(17.50f, 0.50f, 7.80f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(1, 0.2f, 0.35f));
	RegistGameObject(test55);

	GameObject* test56 = new GameObject(true, Tag::Default, "test56");
	//test56->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test56->AddComponent<Transform>(XMFLOAT3(17.160f, 0.50f, 6.80f), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(2.80f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test56->AddComponent<BoxCollider>(true, XMFLOAT3(17.160f, 0.50f, 6.80f), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.2f, 0.3f));
	RegistGameObject(test56);

	GameObject* test57 = new GameObject(true, Tag::Default, "test57");
	//test57->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test57->AddComponent<Transform>(XMFLOAT3(16.650f, 0.50f, 6.70f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(1.60f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test57->AddComponent<BoxCollider>(true, XMFLOAT3(16.650f, 0.50f, 6.70f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 0.5f));
	RegistGameObject(test57);

	GameObject* test58 = new GameObject(true, Tag::Default, "test58");
	//test58->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test58->AddComponent<Transform>(XMFLOAT3(17.950f, 0.50f, 5.660f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(2.60f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test58->AddComponent<BoxCollider>(true, XMFLOAT3(17.950f, 0.50f, 5.660f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.2f, 0.6f));
	RegistGameObject(test58);

	GameObject* test59 = new GameObject(true, Tag::Default, "test59");
	//test59->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test59->AddComponent<Transform>(XMFLOAT3(17.10f, 0.50f, 5.150f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test59->AddComponent<BoxCollider>(true, XMFLOAT3(17.10f, 0.50f, 5.150f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(1.0f, 0.2f, 0.5f));
	RegistGameObject(test59);

	GameObject* test60 = new GameObject(true, Tag::Default, "test60");
	//test60->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test60->AddComponent<Transform>(XMFLOAT3(16.210f, 0.50f, 5.780f), XMFLOAT3(0, 82 * XM_PI / 180.0f, 0), XMFLOAT3(0.70f, 0.40f, 0.50f), XMFLOAT3(0, 0, 0));
	test60->AddComponent<BoxCollider>(true, XMFLOAT3(16.210f, 0.50f, 5.780f), XMFLOAT3(0, 82 * XM_PI / 180.0f, 0), XMFLOAT3(0.35f, 0.2f, 0.25f));
	RegistGameObject(test60);

	GameObject* test61 = new GameObject(true, Tag::Default, "test61");
	//test61->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test61->AddComponent<Transform>(XMFLOAT3(19.740f, 0.50f, 5.340f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test61->AddComponent<BoxCollider>(true, XMFLOAT3(19.740f, 0.50f, 5.340f), XMFLOAT3(0, 150 * XM_PI / 180.0f, 0), XMFLOAT3(1.5f, 0.2f, 0.5f));
	RegistGameObject(test61);

	GameObject* test62 = new GameObject(true, Tag::Default, "test62");
	//test62->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test62->AddComponent<Transform>(XMFLOAT3(18.140f, 0.50f, 4.60f), XMFLOAT3(0, 89 * XM_PI / 180.0f, 0), XMFLOAT3(0.90f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test62->AddComponent<BoxCollider>(true, XMFLOAT3(18.140f, 0.50f, 4.60f), XMFLOAT3(0, 89 * XM_PI / 180.0f, 0), XMFLOAT3(0.45f, 0.2f, 0.6f));
	RegistGameObject(test62);

	GameObject* test63 = new GameObject(true, Tag::Default, "test63");
	//test63->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test63->AddComponent<Transform>(XMFLOAT3(24.720f, 0.50f, 6.20f), XMFLOAT3(0, 87 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.40f, 1.80f), XMFLOAT3(0, 0, 0));
	test62->AddComponent<BoxCollider>(true, XMFLOAT3(24.720f, 0.50f, 6.20f), XMFLOAT3(0, 87 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.9f));
	RegistGameObject(test63);

	GameObject* test64 = new GameObject(true, Tag::Default, "test64");
	//test64->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test64->AddComponent<Transform>(XMFLOAT3(24.770f, 0.50f, -4.350f), XMFLOAT3(0, 92 * XM_PI / 180.0f, 0), XMFLOAT3(5.60f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test64->AddComponent<BoxCollider>(true, XMFLOAT3(24.770f, 0.50f, -4.350f), XMFLOAT3(0, 92 * XM_PI / 180.0f, 0), XMFLOAT3(2.8f, 0.2f, 0.6f));
	RegistGameObject(test64);

	GameObject* test65 = new GameObject(true, Tag::Default, "test65");
	//test65->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test65->AddComponent<Transform>(XMFLOAT3(24.50f, 0.50f, -1.060f), XMFLOAT3(0, 60 * XM_PI / 180.0f, 0), XMFLOAT3(1.80f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test65->AddComponent<BoxCollider>(true, XMFLOAT3(24.50f, 0.50f, -1.060f), XMFLOAT3(0, 60 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.2f, 0.6f));
	RegistGameObject(test65);

	GameObject* test66 = new GameObject(true, Tag::Default, "test66");
	//test66->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test66->AddComponent<Transform>(XMFLOAT3(23.080f, 0.50f, 0.10f), XMFLOAT3(0, 23 * XM_PI / 180.0f, 0), XMFLOAT3(2.80f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	test66->AddComponent<BoxCollider>(true, XMFLOAT3(23.080f, 0.50f, 0.10f), XMFLOAT3(0, 23 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.2f, 0.5f));
	RegistGameObject(test66);


	GameObject* test67 = new GameObject(true, Tag::Default, "test67");
	//test67->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test67->AddComponent<Transform>(XMFLOAT3(23.070f, 0.50f, -0.50f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(3.20f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test67->AddComponent<BoxCollider>(true, XMFLOAT3(23.070f, 0.50f, -0.50f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.2f, 0.3f));
	RegistGameObject(test67);

	GameObject* test68 = new GameObject(true, Tag::Default, "test68");
	//test68->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test68->AddComponent<Transform>(XMFLOAT3(20.850f, 0.50f, -5.850f), XMFLOAT3(0, 68 * XM_PI / 180.0f, 0), XMFLOAT3(7.20f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test68->AddComponent<BoxCollider>(true, XMFLOAT3(20.850f, 0.50f, -5.850f), XMFLOAT3(0, 68 * XM_PI / 180.0f, 0), XMFLOAT3(3.6f, 0.2f, 0.6f));
	RegistGameObject(test68);

	GameObject* test69 = new GameObject(true, Tag::Default, "test69");
	//test69->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test69->AddComponent<Transform>(XMFLOAT3(15.430f, 0.50f, -4.60f), XMFLOAT3(0, 44 * XM_PI / 180.0f, 0), XMFLOAT3(3.60f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test69->AddComponent<BoxCollider>(true, XMFLOAT3(15.430f, 0.50f, -4.60f), XMFLOAT3(0, 44 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.2f, 0.4f));
	RegistGameObject(test69);

	GameObject* test70 = new GameObject(true, Tag::Default, "test70");
	//test70->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test70->AddComponent<Transform>(XMFLOAT3(15.50f, 0.50f, -3.60f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(4.40f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test70->AddComponent<BoxCollider>(true, XMFLOAT3(15.50f, 0.50f, -3.60f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(2.2f, 0.2f, 0.4f));
	RegistGameObject(test70);

	GameObject* test71 = new GameObject(true, Tag::Default, "test71");
	//test71->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test71->AddComponent<Transform>(XMFLOAT3(14, 0.50f, -1.20f), XMFLOAT3(0, 83.5f * XM_PI / 180.0f, 0), XMFLOAT3(4.80f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test71->AddComponent<BoxCollider>(true, XMFLOAT3(14, 0.50f, -1.20f), XMFLOAT3(0, 83.5f * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.2f, 0.4f));
	RegistGameObject(test71);

	GameObject* test72 = new GameObject(true, Tag::Default, "test72");
	//test72->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test72->AddComponent<Transform>(XMFLOAT3(14.40f, 0.50f, -0.50f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(4.20f, 0.40f, 0.80f), XMFLOAT3(0, 0, 0));
	test72->AddComponent<BoxCollider>(true, XMFLOAT3(14.40f, 0.50f, -0.50f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.2f, 0.4f));
	RegistGameObject(test72);

	GameObject* test73 = new GameObject(true, Tag::Default, "test73");
	//test73->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test73->AddComponent<Transform>(XMFLOAT3(14.470f, 0.50f, 1.560f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	test73->AddComponent<BoxCollider>(true, XMFLOAT3(14.470f, 0.50f, 1.560f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1, 0.2f, 0.7f));
	RegistGameObject(test73);

	GameObject* test74 = new GameObject(true, Tag::Default, "test74");
	//test74->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test74->AddComponent<Transform>(XMFLOAT3(16.50f, 0.50f, 2), XMFLOAT3(0, 7 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.40f, 1.10f), XMFLOAT3(0, 0, 0));
	test74->AddComponent<BoxCollider>(true, XMFLOAT3(16.50f, 0.50f, 2), XMFLOAT3(0, 7 * XM_PI / 180.0f, 0), XMFLOAT3(2.0f, 0.2f, 0.55f));
	RegistGameObject(test74);

	GameObject* test75 = new GameObject(true, Tag::Default, "test75");
	//test75->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test75->AddComponent<Transform>(XMFLOAT3(20.050f, 0.50f, -11.480f), XMFLOAT3(0, 67 * XM_PI / 180.0f, 0), XMFLOAT3(4.20f, 0.40f, 0.70f), XMFLOAT3(0, 0, 0));
	test75->AddComponent<BoxCollider>(true, XMFLOAT3(20.050f, 0.50f, -11.480f), XMFLOAT3(0, 67 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.2f, 0.35f));
	RegistGameObject(test75);

	GameObject* test76 = new GameObject(true, Tag::Default, "test76");
	//test76->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test76->AddComponent<Transform>(XMFLOAT3(22.480f, 0.50f, -14.590f), XMFLOAT3(0, 43 * XM_PI / 180.0f, 0), XMFLOAT3(4.20f, 0.40f, 0.90f), XMFLOAT3(0, 0, 0));
	test76->AddComponent<BoxCollider>(true, XMFLOAT3(22.480f, 0.50f, -14.590f), XMFLOAT3(0, 43 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.2f, 0.45f));
	RegistGameObject(test76);

	GameObject* test77 = new GameObject(true, Tag::Default, "test77");
	//test77->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test77->AddComponent<Transform>(XMFLOAT3(21.860f, 0.50f, -13.050f), XMFLOAT3(0, 43 * XM_PI / 180.0f, 0), XMFLOAT3(5.60f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	test77->AddComponent<BoxCollider>(true, XMFLOAT3(21.860f, 0.50f, -13.050f), XMFLOAT3(0, 43 * XM_PI / 180.0f, 0), XMFLOAT3(2.8f, 0.2f, 0.3f));
	RegistGameObject(test77);

	GameObject* test78 = new GameObject(true, Tag::Default, "test78");
	//test78->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test78->AddComponent<Transform>(XMFLOAT3(23.780f, 0.50f, -14.30f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(3.40f, 3, 2.60f), XMFLOAT3(0, 0, 0));
	test78->AddComponent<BoxCollider>(true, XMFLOAT3(23.780f, 0.50f, -14.30f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 1.5f, 1.3f));
	RegistGameObject(test78);

	GameObject* test79 = new GameObject(true, Tag::Default, "test79");
	//test79->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test79->AddComponent<Transform>(XMFLOAT3(24.90f, 0.50f, -12.50f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(4.60f, 0.40f, 1.20f), XMFLOAT3(0, 0, 0));
	test79->AddComponent<BoxCollider>(true, XMFLOAT3(24.90f, 0.50f, -12.50f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(2.3f, 0.2f, 0.6f));
	RegistGameObject(test79);



	GameObject* red1 = new GameObject(true, Tag::Default, "red1");
	//red1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red1->AddComponent<Transform>(XMFLOAT3(2.10f, 0.50f, -8.50f), XMFLOAT3(0, 60 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.40f, 1), XMFLOAT3(0, 0, 0));
	red1->AddComponent<BoxCollider>(true, XMFLOAT3(2.10f, 0.50f, -8.50f), XMFLOAT3(0, 60 * XM_PI / 180.0f, 0), XMFLOAT3(1.5f, 0.2f, 0.5f));
	RegistGameObject(red1);

	GameObject* red2 = new GameObject(true, Tag::Default, "red2");
	//red2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red2->AddComponent<Transform>(XMFLOAT3(0.5250f, 0.50f, -7.620f), XMFLOAT3(0, 12 * XM_PI / 180.0f, 0), XMFLOAT3(2.40f, 0.40f, 1.40f), XMFLOAT3(0, 0, 0));
	red2->AddComponent<BoxCollider>(true, XMFLOAT3(0.5250f, 0.50f, -7.620f), XMFLOAT3(0, 12 * XM_PI / 180.0f, 0), XMFLOAT3(1.20f, 0.20f, 0.70f));
	RegistGameObject(red2);

	GameObject* red3 = new GameObject(true, Tag::Default, "red3");
	//red3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red3->AddComponent<Transform>(XMFLOAT3(-2.40f, 0.50f, -8.60f), XMFLOAT3(0, -42 * XM_PI / 180.0f, 0), XMFLOAT3(3.60f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	red3->AddComponent<BoxCollider>(true, XMFLOAT3(24.90f, 0.50f, -12.50f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(2.3f, 0.2f, 0.6f));
	RegistGameObject(red3);

	GameObject* red4 = new GameObject(true, Tag::Default, "red4");
	//red4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red4->AddComponent<Transform>(XMFLOAT3(-0.850f, 0.50f, -7.20f), XMFLOAT3(0, -24 * XM_PI / 180.0f, 0), XMFLOAT3(1.10f, 0.40f, 0.70f), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-0.850f, 0.50f, -7.20f), XMFLOAT3(0, -24 * XM_PI / 180.0f, 0), XMFLOAT3(0.550f, 0.20f, 0.350f));
	RegistGameObject(red4);

	GameObject* red5 = new GameObject(true, Tag::Default, "red5");
	//red5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red5->AddComponent<Transform>(XMFLOAT3(-1.50f, 0.50f, -9), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(3.60f, 0.40f, 1.60f), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-1.50f, 0.50f, -9), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(1.80f, 0.20f, 0.80f));
	RegistGameObject(red5);

	GameObject* red6 = new GameObject(true, Tag::Default, "red6");
	//red6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red6->AddComponent<Transform>(XMFLOAT3(-1.560f, 0.50f, -10.870f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(4.40f, 0.40f, 1), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-1.560f, 0.50f, -10.870f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(2.20f, 0.20f, 0.50f));
	RegistGameObject(red6);

	GameObject* red7 = new GameObject(true, Tag::Default, "red7");
	//red7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red7->AddComponent<Transform>(XMFLOAT3(-0.840f, 0.50f, -10.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(3.60f, 0.40f, 0.60f), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-0.840f, 0.50f, -10.80f), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.80f, 0.20f, 0.30f));
	RegistGameObject(red7);

	GameObject* red8 = new GameObject(true, Tag::Default, "red8");
	//red8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red8->AddComponent<Transform>(XMFLOAT3(-6.10f, 0.50f, -15.250f), XMFLOAT3(0, 50 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.60f, 3.40f), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-6.10f, 0.50f, -15.250f), XMFLOAT3(0, 50 * XM_PI / 180.0f, 0), XMFLOAT3(2.50f, 0.30f, 1.70f));
	RegistGameObject(red8);

	GameObject* red9 = new GameObject(true, Tag::Default, "red9");
	//red9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red9->AddComponent<Transform>(XMFLOAT3(-6.80f, 0.50f, -16.750f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.60f, 1.40f), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-6.80f, 0.50f, -16.750f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.30f, 0.70f));
	RegistGameObject(red9);

	GameObject* red10 = new GameObject(true, Tag::Default, "red10");
	//red10->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red10->AddComponent<Transform>(XMFLOAT3(-4.650f, 0.50f, -17.30f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(2.20f, 0.60f, 0.80f), XMFLOAT3(0, 0, 0));
	red10->AddComponent<BoxCollider>(true, XMFLOAT3(-4.650f, 0.50f, -17.30f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(1.10f, 0.30f, 0.40f));
	RegistGameObject(red10);

	GameObject* red11 = new GameObject(true, Tag::Default, "red11");
	//red11->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red11->AddComponent<Transform>(XMFLOAT3(-4.80f, 0.50f, -15.080f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.60f, 2), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-4.80f, 0.50f, -15.080f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(1.50f, 0.30f, 1));
	RegistGameObject(red11);

	GameObject* red12 = new GameObject(true, Tag::Default, "red12");
	//red12->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red12->AddComponent<Transform>(XMFLOAT3(-1.70f, 0.50f, -21.520f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(8.40f, 0.60f, 1), XMFLOAT3(0, 0, 0));
	red4->AddComponent<BoxCollider>(true, XMFLOAT3(-1.70f, 0.50f, -21.520f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(4.20f, 0.30f, 0.50f));
	RegistGameObject(red12);

	GameObject* red13 = new GameObject(true, Tag::Default, "red13");
	//red13->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red13->AddComponent<Transform>(XMFLOAT3(-1.490f, 0.50f, -20.580f), XMFLOAT3(0, 22 * XM_PI / 180.0f, 0), XMFLOAT3(3.3f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red13->AddComponent<BoxCollider>(true, XMFLOAT3(-1.490f, 0.50f, -20.580f), XMFLOAT3(0, 22 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.3f, 0.4f));
	RegistGameObject(red13);

	GameObject* red14 = new GameObject(true, Tag::Default, "red14");
	//red14->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red14->AddComponent<Transform>(XMFLOAT3(-2.4f, 0.5f, -20.85f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(3.8f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red14->AddComponent<BoxCollider>(true, XMFLOAT3(-2.4f, 0.5f, -20.85f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.9f, 0.3f, 0.4f));
	RegistGameObject(red14);

	GameObject* red15 = new GameObject(true, Tag::Default, "red15");
	//red15->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red15->AddComponent<Transform>(XMFLOAT3(-3.4f, 0.5f, -20.58f), XMFLOAT3(0, -11 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red15->AddComponent<BoxCollider>(true, XMFLOAT3(-3.4f, 0.5f, -20.58f), XMFLOAT3(0, -11 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 0.7f));
	RegistGameObject(red15);

	GameObject* red16 = new GameObject(true, Tag::Default, "red16");
	//red16->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red16->AddComponent<Transform>(XMFLOAT3(-4.4f, 0.5f, -21.0f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red16->AddComponent<BoxCollider>(true, XMFLOAT3(-4.4f, 0.5f, -21.0f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 0.7f));
	RegistGameObject(red16);

	GameObject* red17 = new GameObject(true, Tag::Default, "red17");
	//red17->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red17->AddComponent<Transform>(XMFLOAT3(11.27f, 0.5f, -21.59f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(9, 0.6f, 1), XMFLOAT3(0, 0, 0));
	red17->AddComponent<BoxCollider>(true, XMFLOAT3(11.27f, 0.5f, -21.59f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(4.5f, 0.3f, 0.5f));
	RegistGameObject(red17);

	GameObject* red18 = new GameObject(true, Tag::Default, "red18");
	//red18->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red18->AddComponent<Transform>(XMFLOAT3(8, 0.5f, -20.7f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red18->AddComponent<BoxCollider>(true, XMFLOAT3(8, 0.5f, -20.7f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(1, 0.3f, 0.4f));
	RegistGameObject(red18);

	GameObject* red19 = new GameObject(true, Tag::Default, "red19");
	//red19->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red19->AddComponent<Transform>(XMFLOAT3(9.4f, 0.5f, -20.8f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(2.2f, 0.6f, 1.6f), XMFLOAT3(0, 0, 0));
	red19->AddComponent<BoxCollider>(true, XMFLOAT3(9.4f, 0.5f, -20.8f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(1.1f, 0.3f, 0.8f));
	RegistGameObject(red19);

	GameObject* red20 = new GameObject(true, Tag::Default, "red20");
	//red20->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red20->AddComponent<Transform>(XMFLOAT3(11.7f, 0.5f, -21), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(7.2f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red20->AddComponent<BoxCollider>(true, XMFLOAT3(24.9f, 0.5f, -12.5f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(2.3f, 0.2f, 0.6f));
	RegistGameObject(red20);

	GameObject* red21 = new GameObject(true, Tag::Default, "red21");
	//red21->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red21->AddComponent<Transform>(XMFLOAT3(12.4f, 0.5f, -20.5f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(5.3f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red21->AddComponent<BoxCollider>(true, XMFLOAT3(12.4f, 0.5f, -20.5f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.65f, 0.3f, 0.4f));
	RegistGameObject(red21);

	GameObject* red22 = new GameObject(true, Tag::Default, "red22");
	//red22->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red22->AddComponent<Transform>(XMFLOAT3(13, 0.5f, -19.8f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red20->AddComponent<BoxCollider>(true, XMFLOAT3(13, 0.5f, -19.8f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(1.5f, 0.3f, 0.6f));
	RegistGameObject(red22);

	GameObject* red23 = new GameObject(true, Tag::Default, "red23");
	//red23->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red23->AddComponent<Transform>(XMFLOAT3(12.3f, 0.5f, -19.8f), XMFLOAT3(0, 72 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red23->AddComponent<BoxCollider>(true, XMFLOAT3(12.3f, 0.5f, -19.8f), XMFLOAT3(0, 72 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.6f));
	RegistGameObject(red23);

	GameObject* red24 = new GameObject(true, Tag::Default, "red24");
	//red24->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red24->AddComponent<Transform>(XMFLOAT3(11.8f, 0.5f, -20), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(2.6f, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red24->AddComponent<BoxCollider>(true, XMFLOAT3(11.8f, 0.5f, -20), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.3f, 0.6f));
	RegistGameObject(red24);

	GameObject* red25 = new GameObject(true, Tag::Default, "red25");
	//red25->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red25->AddComponent<Transform>(XMFLOAT3(17.6f, 0.5f, -18.76f), XMFLOAT3(0, 39 * XM_PI / 180.0f, 0), XMFLOAT3(3.1f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red25->AddComponent<BoxCollider>(true, XMFLOAT3(17.6f, 0.5f, -18.76f), XMFLOAT3(0, 39 * XM_PI / 180.0f, 0), XMFLOAT3(1.55f, 0.3f, 0.4f));
	RegistGameObject(red25);

	GameObject* red26 = new GameObject(true, Tag::Default, "red26");
	//red26->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red26->AddComponent<Transform>(XMFLOAT3(18.2f, 0.5f, -20.2f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(2.8f, 0.6f, 0.65f), XMFLOAT3(0, 0, 0));
	red26->AddComponent<BoxCollider>(true, XMFLOAT3(18.2f, 0.5f, -20.2f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.3f, 0.325f));
	RegistGameObject(red26);

	GameObject* red27 = new GameObject(true, Tag::Default, "red27");
	//red27->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red27->AddComponent<Transform>(XMFLOAT3(19, 0.5f, -20.5f), XMFLOAT3(0, 95 * XM_PI / 180.0f, 0), XMFLOAT3(1, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red27->AddComponent<BoxCollider>(true, XMFLOAT3(19, 0.5f, -20.5f), XMFLOAT3(0, 95 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.3f, 0.35f));
	RegistGameObject(red27);

	GameObject* red28 = new GameObject(true, Tag::Default, "red28");
	//red28->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red28->AddComponent<Transform>(XMFLOAT3(18.9f, 0.5f, -19.9f), XMFLOAT3(0, 57 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red28->AddComponent<BoxCollider>(true, XMFLOAT3(18.9f, 0.5f, -19.9f), XMFLOAT3(0, 57 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.3f, 0.35f));
	RegistGameObject(red28);

	GameObject* red29 = new GameObject(true, Tag::Default, "red29");
	//red29->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red29->AddComponent<Transform>(XMFLOAT3(15.2f, 0.5f, -13.2f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(4.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red29->AddComponent<BoxCollider>(true, XMFLOAT3(15.2f, 0.5f, -13.2f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(2.2f, 0.3f, 0.4f));
	RegistGameObject(red29);

	GameObject* red30 = new GameObject(true, Tag::Default, "red30");
	//red30->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red30->AddComponent<Transform>(XMFLOAT3(15.4f, 0.5f, -13.2f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(3.6f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red30->AddComponent<BoxCollider>(true, XMFLOAT3(15.4f, 0.5f, -13.2f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.3f, 0.4f));
	RegistGameObject(red30);

	GameObject* red31 = new GameObject(true, Tag::Default, "red31");
	//red31->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red31->AddComponent<Transform>(XMFLOAT3(12, 0.5f, -15), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(3.8f, 0.6f, 0.6f), XMFLOAT3(0, 0, 0));
	red31->AddComponent<BoxCollider>(true, XMFLOAT3(12, 0.5f, -15), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(1.9f, 0.3f, 0.3f));
	RegistGameObject(red31);

	GameObject* red32 = new GameObject(true, Tag::Default, "red32");
	//red32->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red32->AddComponent<Transform>(XMFLOAT3(14.6f, 0.5f, -14.58f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 2.4f), XMFLOAT3(0, 0, 0));
	red32->AddComponent<BoxCollider>(true, XMFLOAT3(14.6f, 0.5f, -14.58f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 1.2f));
	RegistGameObject(red32);

	GameObject* red33 = new GameObject(true, Tag::Default, "red33");
	//red33->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red33->AddComponent<Transform>(XMFLOAT3(14.4f, 0.5f, -12.4f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.6f, 0.6f), XMFLOAT3(0, 0, 0));
	red33->AddComponent<BoxCollider>(true, XMFLOAT3(14.4f, 0.5f, -12.4f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.3f, 0.3f));
	RegistGameObject(red33);

	GameObject* red34 = new GameObject(true, Tag::Default, "red34");
	//red34->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red34->AddComponent<Transform>(XMFLOAT3(14.7f, 0.5f, -13.4f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 0.6f), XMFLOAT3(0, 0, 0));
	red34->AddComponent<BoxCollider>(true, XMFLOAT3(14.7f, 0.5f, -13.4f), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 0.3f));
	RegistGameObject(red34);

	GameObject* red35 = new GameObject(true, Tag::Default, "red35");
	//red35->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red35->AddComponent<Transform>(XMFLOAT3(13.6f, 0.5f, -13.4f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(2.6f, 0.6f, 0.6f), XMFLOAT3(0, 0, 0));
	red35->AddComponent<BoxCollider>(true, XMFLOAT3(13.6f, 0.5f, -13.4f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.3f, 0.3f));
	RegistGameObject(red35);

	GameObject* red36 = new GameObject(true, Tag::Default, "red36");
	//red36->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red36->AddComponent<Transform>(XMFLOAT3(12.52f, 0.5f, -14.25f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red36->AddComponent<BoxCollider>(true, XMFLOAT3(12.52f, 0.5f, -14.25f), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.3f, 0.7f));
	RegistGameObject(red36);

	GameObject* red37 = new GameObject(true, Tag::Default, "red37");
	//red37->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red37->AddComponent<Transform>(XMFLOAT3(10.1f, 0.5f, -13.5f), XMFLOAT3(30 * XM_PI / 180.0f, 30 * XM_PI / 180.0f, 60 * XM_PI / 180.0f), XMFLOAT3(2.4f, 2.4f, 0.8f), XMFLOAT3(0, 0, 0));
	red37->AddComponent<BoxCollider>(true, XMFLOAT3(10.1f, 0.5f, -13.5f), XMFLOAT3(30 * XM_PI / 180.0f, 30 * XM_PI / 180.0f, 60 * XM_PI / 180.0f), XMFLOAT3(1.2f, 1.2f, 0.4f));
	RegistGameObject(red37);

	GameObject* red38 = new GameObject(true, Tag::Default, "red38");
	//red38->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red38->AddComponent<Transform>(XMFLOAT3(10.6f, 0.5f, -13.0f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(3.8f, 0.8f, 0.8f), XMFLOAT3(0, 0, 0));
	red38->AddComponent<BoxCollider>(true, XMFLOAT3(10.6f, 0.5f, -13.0f), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(1.9f, 0.4f, 0.4f));
	RegistGameObject(red38);

	GameObject* red39 = new GameObject(true, Tag::Default, "red39");
	//red39->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red39->AddComponent<Transform>(XMFLOAT3(9.2f, 0.5f, -10.8f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(4.2f, 0.8f, 1.4f), XMFLOAT3(0, 0, 0));
	red39->AddComponent<BoxCollider>(true, XMFLOAT3(9.2f, 0.5f, -10.8f), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.4f, 0.7f));
	RegistGameObject(red39);

	GameObject* red40 = new GameObject(true, Tag::Default, "red40");
	//red40->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red40->AddComponent<Transform>(XMFLOAT3(8.7f, 0.5f, -9.2f), XMFLOAT3(0, 165 * XM_PI / 180.0f, 0), XMFLOAT3(2.8f, 0.8f, 1.4f), XMFLOAT3(0, 0, 0));
	red40->AddComponent<BoxCollider>(true, XMFLOAT3(8.7f, 0.5f, -9.2f), XMFLOAT3(0, 165 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.4f, 0.7f));
	RegistGameObject(red40);

	GameObject* red41 = new GameObject(true, Tag::Default, "red41");
	//red41->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red41->AddComponent<Transform>(XMFLOAT3(8, 0.5f, -10), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.8f, 1.0f), XMFLOAT3(0, 0, 0));
	red41->AddComponent<BoxCollider>(true, XMFLOAT3(8, 0.5f, -10), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.4f, 0.5f));
	RegistGameObject(red41);

	GameObject* red42 = new GameObject(true, Tag::Default, "red42");
	//red42->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red42->AddComponent<Transform>(XMFLOAT3(7.3f, 0.5f, -9.4f), XMFLOAT3(0, 120 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.8f, 0.8f), XMFLOAT3(0, 0, 0));
	red42->AddComponent<BoxCollider>(true, XMFLOAT3(7.3f, 0.5f, -9.4f), XMFLOAT3(0, 120 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.4f, 0.4f));
	RegistGameObject(red42);

	GameObject* red43 = new GameObject(true, Tag::Default, "red43");
	//red43->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red43->AddComponent<Transform>(XMFLOAT3(10.9f, 0.5f, -8.5f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.8f, 0.80f), XMFLOAT3(0, 0, 0));
	red43->AddComponent<BoxCollider>(true, XMFLOAT3(10.9f, 0.5f, -8.5f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.05f, 0.4f, 0.4f));
	RegistGameObject(red43);

	GameObject* red44 = new GameObject(true, Tag::Default, "red44");
	//red44->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red44->AddComponent<Transform>(XMFLOAT3(10.3f, 0.5f, -9.3f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(2.0f, 0.8f, 0.60f), XMFLOAT3(0, 0, 0));
	red44->AddComponent<BoxCollider>(true, XMFLOAT3(10.3f, 0.5f, -9.3f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(1.0f, 0.4f, 0.30f));
	RegistGameObject(red44);

	GameObject* red45 = new GameObject(true, Tag::Default, "red45");
	//red45->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red45->AddComponent<Transform>(XMFLOAT3(10.1f, 0.5f, -9.7f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.8f, 0.60f), XMFLOAT3(0, 0, 0));
	red45->AddComponent<BoxCollider>(true, XMFLOAT3(10.1f, 0.5f, -9.7f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.4f, 0.3f));
	RegistGameObject(red45);

	GameObject* red46 = new GameObject(true, Tag::Default, "red46");
	//red46->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red46->AddComponent<Transform>(XMFLOAT3(14, 0.5f, -13.35f), XMFLOAT3(0, 130 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 3, 1.0f), XMFLOAT3(0, 0, 0));
	red46->AddComponent<BoxCollider>(true, XMFLOAT3(14, 0.5f, -13.35f), XMFLOAT3(0, 130 * XM_PI / 180.0f, 0), XMFLOAT3(0.2f, 1.5f, 0.5f));
	RegistGameObject(red46);

	GameObject* red47 = new GameObject(true, Tag::Default, "red47");
	//red47->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red47->AddComponent<Transform>(XMFLOAT3(9.5f, 0.5f, -9.68f), XMFLOAT3(0, 130 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 3, 1.0f), XMFLOAT3(0, 0, 0));
	red47->AddComponent<BoxCollider>(true, XMFLOAT3(9.5f, 0.5f, -9.68f), XMFLOAT3(0, 130 * XM_PI / 180.0f, 0), XMFLOAT3(0.2f, 1.5f, 0.5f));
	RegistGameObject(red47);

	GameObject* red48 = new GameObject(true, Tag::Default, "red48");
	//red48->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red48->AddComponent<Transform>(XMFLOAT3(9.6f, 0.5f, -9.6f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 3, 1.0f), XMFLOAT3(0, 0, 0));
	red48->AddComponent<BoxCollider>(true, XMFLOAT3(9.6f, 0.5f, -9.6f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(0.2f, 1.5f, 0.5f));
	RegistGameObject(red48);

	GameObject* red49 = new GameObject(true, Tag::Default, "red49");
	//red49->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red49->AddComponent<Transform>(XMFLOAT3(2.15f, 0.5f, -14.44f), XMFLOAT3(0, -30 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red49->AddComponent<BoxCollider>(true, XMFLOAT3(2.15f, 0.5f, -14.44f), XMFLOAT3(0, -30 * XM_PI / 180.0f, 0), XMFLOAT3(1.5f, 0.3f, 0.4f));
	RegistGameObject(red49);

	GameObject* red50 = new GameObject(true, Tag::Default, "red50");
	//red50->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red50->AddComponent<Transform>(XMFLOAT3(3, 0.5f, -14.8f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red50->AddComponent<BoxCollider>(true, XMFLOAT3(3, 0.5f, -14.8f), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.3f, 0.4f));
	RegistGameObject(red50);

	GameObject* red51 = new GameObject(true, Tag::Default, "red51");
	//red51->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red51->AddComponent<Transform>(XMFLOAT3(1, 0.5f, -15.3f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.8f, 0.8f), XMFLOAT3(0, 0, 0));
	red51->AddComponent<BoxCollider>(true, XMFLOAT3(1, 0.5f, -15.3f), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.4f, 0.4f));
	RegistGameObject(red51);

	GameObject* red52 = new GameObject(true, Tag::Default, "red52");
	//red52->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red52->AddComponent<Transform>(XMFLOAT3(4.1f, 0.5f, -14.05f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red52->AddComponent<BoxCollider>(true, XMFLOAT3(4.1f, 0.5f, -14.05f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.3f, 0.7f));
	RegistGameObject(red52);

	GameObject* red53 = new GameObject(true, Tag::Default, "red53");
	//red53->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red53->AddComponent<Transform>(XMFLOAT3(5.3f, 0.5f, -14.25f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red53->AddComponent<BoxCollider>(true, XMFLOAT3(5.3f, 0.5f, -14.25f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 0.7f));
	RegistGameObject(red53);

	GameObject* red54 = new GameObject(true, Tag::Default, "red54");
	//red54->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red54->AddComponent<Transform>(XMFLOAT3(5.8f, 0.5f, -15), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.6f, 1.6f), XMFLOAT3(0, 0, 0));
	red54->AddComponent<BoxCollider>(true, XMFLOAT3(5.8f, 0.5f, -15), XMFLOAT3(0, 75 * XM_PI / 180.0f, 0), XMFLOAT3(0.85f, 0.3f, 0.8f));
	RegistGameObject(red54);

	GameObject* red55 = new GameObject(true, Tag::Default, "red55");
	//red55->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red55->AddComponent<Transform>(XMFLOAT3(5.14f, 0.5f, -17.0f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(2.5f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red55->AddComponent<BoxCollider>(true, XMFLOAT3(5.14f, 0.5f, -17.0f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(1.25f, 0.3f, 0.4f));
	RegistGameObject(red55);

	GameObject* red56 = new GameObject(true, Tag::Default, "red56");
	//red56->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red56->AddComponent<Transform>(XMFLOAT3(5.53f, 0.5f, -17.5f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(2.7f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red56->AddComponent<BoxCollider>(true, XMFLOAT3(5.53f, 0.5f, -17.5f), XMFLOAT3(0, 140 * XM_PI / 180.0f, 0), XMFLOAT3(1.35f, 0.3f, 0.4f));
	RegistGameObject(red56);

	GameObject* red57 = new GameObject(true, Tag::Default, "red57");
	//red57->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red57->AddComponent<Transform>(XMFLOAT3(6.1f, 0.5f, -16.3f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red57->AddComponent<BoxCollider>(true, XMFLOAT3(6.1f, 0.5f, -16.3f), XMFLOAT3(0, 88 * XM_PI / 180.0f, 0), XMFLOAT3(0.65f, 0.3f, 0.7f));
	RegistGameObject(red57);

	GameObject* red58 = new GameObject(true, Tag::Default, "red58");
	//red58->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red58->AddComponent<Transform>(XMFLOAT3(-11.76f, 0.5f, -8.9f), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red58->AddComponent<BoxCollider>(true, XMFLOAT3(-11.76f, 0.5f, -8.9f), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.4f));
	RegistGameObject(red58);

	GameObject* red59 = new GameObject(true, Tag::Default, "red59");
	//red59->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red59->AddComponent<Transform>(XMFLOAT3(-14.6f, 0.5f, -9.15f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red59->AddComponent<BoxCollider>(true, XMFLOAT3(-14.6f, 0.5f, -9.15f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.4f));
	RegistGameObject(red59);

	GameObject* red60 = new GameObject(true, Tag::Default, "red60");
	//red60->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red60->AddComponent<Transform>(XMFLOAT3(-12.3f, 0.5f, -8.6f), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red60->AddComponent<BoxCollider>(true, XMFLOAT3(-12.3f, 0.5f, -8.6f), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.4f));
	RegistGameObject(red60);

	GameObject* red61 = new GameObject(true, Tag::Default, "red61");
	//red61->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red61->AddComponent<Transform>(XMFLOAT3(-13.5f, 0.5f, -8.85f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red61->AddComponent<BoxCollider>(true, XMFLOAT3(-13.5f, 0.5f, -8.85f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.4f));
	RegistGameObject(red61);

	GameObject* red62 = new GameObject(true, Tag::Default, "red62");
	//red62->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red62->AddComponent<Transform>(XMFLOAT3(-19.8f, 0.5f, -4.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(6.2f, 0.6f, 1.8f), XMFLOAT3(0, 0, 0));
	red62->AddComponent<BoxCollider>(true, XMFLOAT3(-19.8f, 0.5f, -4.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(3.1f, 0.3f, 0.9f));
	RegistGameObject(red62);

	GameObject* red63 = new GameObject(true, Tag::Default, "red63");
	//red63->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red63->AddComponent<Transform>(XMFLOAT3(-19.7f, 0.5f, -1.4f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(1.6f, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red63->AddComponent<BoxCollider>(true, XMFLOAT3(-19.7f, 0.5f, -1.4f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.3f, 0.6f));
	RegistGameObject(red63);

	GameObject* red64 = new GameObject(true, Tag::Default, "red64");
	//red64->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red64->AddComponent<Transform>(XMFLOAT3(-18.9f, 0.5f, -2.9f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(3.25f, 0.6f, 0.45f), XMFLOAT3(0, 0, 0));
	red64->AddComponent<BoxCollider>(true, XMFLOAT3(-18.9f, 0.5f, -2.9f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(1.625f, 0.3f, 0.225f));
	RegistGameObject(red64);

	GameObject* red65 = new GameObject(true, Tag::Default, "red65");
	//red65->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red65->AddComponent<Transform>(XMFLOAT3(-19.5f, 0.5f, 6), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(6.2f, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red65->AddComponent<BoxCollider>(true, XMFLOAT3(-19.5f, 0.5f, 6), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(3.1f, 0.3f, 0.6f));
	RegistGameObject(red65);

	GameObject* red66 = new GameObject(true, Tag::Default, "red66");
	//red66->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red66->AddComponent<Transform>(XMFLOAT3(-20.1f, 0.5f, 5.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(5.6f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red66->AddComponent<BoxCollider>(true, XMFLOAT3(-20.1f, 0.5f, 5.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(2.8f, 0.3f, 0.4f));
	RegistGameObject(red66);

	GameObject* red67 = new GameObject(true, Tag::Default, "red67");
	//red67->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red67->AddComponent<Transform>(XMFLOAT3(-18.7f, 0.5f, 2.5f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 1.3f), XMFLOAT3(0, 0, 0));
	red67->AddComponent<BoxCollider>(true, XMFLOAT3(-18.7f, 0.5f, 2.5f), XMFLOAT3(0, 30 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.65f));
	RegistGameObject(red67);

	GameObject* red68 = new GameObject(true, Tag::Default, "red68");
	//red68->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red68->AddComponent<Transform>(XMFLOAT3(-17.0f, 0.5f, 1.7f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red68->AddComponent<BoxCollider>(true, XMFLOAT3(-17.0f, 0.5f, 1.7f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.3f, 0.6f));
	RegistGameObject(red68);

	GameObject* red69 = new GameObject(true, Tag::Default, "red69");
	//red69->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red69->AddComponent<Transform>(XMFLOAT3(-19.98f, 0.5f, 14.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red69->AddComponent<BoxCollider>(true, XMFLOAT3(-19.98f, 0.5f, 14.6f), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(2.5f, 0.3f, 0.7f));
	RegistGameObject(red69);

	GameObject* red70 = new GameObject(true, Tag::Default, "red70");
	//red70->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red70->AddComponent<Transform>(XMFLOAT3(-18.6f, 0.5f, 16.8f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(2.6f, 0.6f, 2.8f), XMFLOAT3(0, 0, 0));
	red70->AddComponent<BoxCollider>(true, XMFLOAT3(-18.6f, 0.5f, 16.8f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.3f, 1.4f));
	RegistGameObject(red70);

	GameObject* red71 = new GameObject(true, Tag::Default, "red71");
	//red71->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red71->AddComponent<Transform>(XMFLOAT3(-18.14f, 0.5f, 15.2f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.6f, 1.3f), XMFLOAT3(0, 0, 0));
	red71->AddComponent<BoxCollider>(true, XMFLOAT3(-18.14f, 0.5f, 15.2f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.3f, 0.65f));
	RegistGameObject(red71);

	GameObject* red73 = new GameObject(true, Tag::Default, "red73");
	//red73->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red73->AddComponent<Transform>(XMFLOAT3(-16, 0.5f, 14.6f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.9f), XMFLOAT3(0, 0, 0));
	red73->AddComponent<BoxCollider>(true, XMFLOAT3(-16, 0.5f, 14.6f), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.45f));
	RegistGameObject(red73);

	GameObject* red74 = new GameObject(true, Tag::Default, "red74");
	//red74->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red74->AddComponent<Transform>(XMFLOAT3(-17.1f, 0.5f, 15.2f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(3.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red74->AddComponent<BoxCollider>(true, XMFLOAT3(-17.1f, 0.5f, 15.2f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(1.7f, 0.3f, 0.4f));
	RegistGameObject(red74);

	GameObject* red75 = new GameObject(true, Tag::Default, "red75");
	//red75->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red75->AddComponent<Transform>(XMFLOAT3(-14.87f, 0.5f, 12.8f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(2.7f, 0.6f, 0.75f), XMFLOAT3(0, 0, 0));
	red75->AddComponent<BoxCollider>(true, XMFLOAT3(-14.87f, 0.5f, 12.8f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(1.35f, 0.3f, 0.375f));
	RegistGameObject(red75);

	GameObject* red76 = new GameObject(true, Tag::Default, "red76");
	//red76->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red76->AddComponent<Transform>(XMFLOAT3(-15.7f, 0.5f, 7.8f), XMFLOAT3(0, 70 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red76->AddComponent<BoxCollider>(true, XMFLOAT3(-15.7f, 0.5f, 7.8f), XMFLOAT3(0, 70 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.3f, 0.6f));
	RegistGameObject(red76);

	GameObject* red77 = new GameObject(true, Tag::Default, "red77");
	//red77->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red77->AddComponent<Transform>(XMFLOAT3(-15.56f, 0.5f, 6.6f), XMFLOAT3(0, 80 * XM_PI / 180.0f, 0), XMFLOAT3(2.9f, 0.6f, 1), XMFLOAT3(0, 0, 0));
	red77->AddComponent<BoxCollider>(true, XMFLOAT3(-15.56f, 0.5f, 6.6f), XMFLOAT3(0, 80 * XM_PI / 180.0f, 0), XMFLOAT3(1.45f, 0.3f, 0.5f));
	RegistGameObject(red77);

	GameObject* red78 = new GameObject(true, Tag::Default, "red78");
	//red78->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red78->AddComponent<Transform>(XMFLOAT3(-10.2f, 0.5f, 4.8f), XMFLOAT3(0, 67 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red78->AddComponent<BoxCollider>(true, XMFLOAT3(-10.2f, 0.5f, 4.8f), XMFLOAT3(0, 67 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.3f, 0.4f));
	RegistGameObject(red78);

	GameObject* red79 = new GameObject(true, Tag::Default, "red79");
	//red79->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red79->AddComponent<Transform>(XMFLOAT3(-10.3f, 0.5f, 6.5f), XMFLOAT3(0, 38 * XM_PI / 180.0f, 0), XMFLOAT3(2.6f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red79->AddComponent<BoxCollider>(true, XMFLOAT3(-10.3f, 0.5f, 6.5f), XMFLOAT3(0, 38 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.3f, 0.4f));
	RegistGameObject(red79);

	GameObject* red80 = new GameObject(true, Tag::Default, "red80");
	//red80->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red80->AddComponent<Transform>(XMFLOAT3(-9.3f, 0.5f, 4.2f), XMFLOAT3(0, 92 * XM_PI / 180.0f, 0), XMFLOAT3(2.9f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red80->AddComponent<BoxCollider>(true, XMFLOAT3(-9.3f, 0.5f, 4.2f), XMFLOAT3(0, 92 * XM_PI / 180.0f, 0), XMFLOAT3(1.45f, 0.3f, 0.4f));
	RegistGameObject(red80);

	GameObject* red81 = new GameObject(true, Tag::Default, "red81");
	//red81->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red81->AddComponent<Transform>(XMFLOAT3(-9.5f, 0.5f, 5.55f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.6f, 1.25f), XMFLOAT3(0, 0, 0));
	red81->AddComponent<BoxCollider>(true, XMFLOAT3(-9.5f, 0.5f, 5.55f), XMFLOAT3(0, 65 * XM_PI / 180.0f, 0), XMFLOAT3(0.2f, 0.3f, 0.625f));
	RegistGameObject(red81);

	GameObject* red82 = new GameObject(true, Tag::Default, "red82");
	//red82->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red82->AddComponent<Transform>(XMFLOAT3(-11.3f, 0.5f, 0.07f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(3.8f, 0.6f, 1), XMFLOAT3(0, 0, 0));
	red82->AddComponent<BoxCollider>(true, XMFLOAT3(-11.3f, 0.5f, 0.07f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.9f, 0.3f, 0.5f));
	RegistGameObject(red82);

	GameObject* red83 = new GameObject(true, Tag::Default, "red83");
	//red83->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red83->AddComponent<Transform>(XMFLOAT3(-12.7f, 0.5f, 0.47f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 1, 0.6f), XMFLOAT3(0, 0, 0));
	red83->AddComponent<BoxCollider>(true, XMFLOAT3(-12.7f, 0.5f, 0.47f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(0.3f, 0.5f, 0.3f));
	RegistGameObject(red83);

	GameObject* red84 = new GameObject(true, Tag::Default, "red84");
	//red84->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red84->AddComponent<Transform>(XMFLOAT3(-9.7f, 0.5f, 1.22f), XMFLOAT3(0, 112 * XM_PI / 180.0f, 0), XMFLOAT3(2.6f, 0.6f, 1.2f), XMFLOAT3(0, 0, 0));
	red84->AddComponent<BoxCollider>(true, XMFLOAT3(-9.7f, 0.5f, 1.22f), XMFLOAT3(0, 112 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.3f, 0.6f));
	RegistGameObject(red84);

	GameObject* red85 = new GameObject(true, Tag::Default, "red85");
	//red85->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red85->AddComponent<Transform>(XMFLOAT3(-9.35f, 0.5f, 0), XMFLOAT3(0, 148 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red85->AddComponent<BoxCollider>(true, XMFLOAT3(-9.35f, 0.5f, 0), XMFLOAT3(0, 148 * XM_PI / 180.0f, 0), XMFLOAT3(0.25f, 0.3f, 0.35f));
	RegistGameObject(red85);

	GameObject* red86 = new GameObject(true, Tag::Default, "red86");
	//red86->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red86->AddComponent<Transform>(XMFLOAT3(-9.1f, 0.5f, 0.3f), XMFLOAT3(0, 115 * XM_PI / 180.0f, 0), XMFLOAT3(0.7f, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red86->AddComponent<BoxCollider>(true, XMFLOAT3(-9.1f, 0.5f, 0.3f), XMFLOAT3(0, 115 * XM_PI / 180.0f, 0), XMFLOAT3(0.35f, 0.3f, 0.35f));
	RegistGameObject(red86);

	GameObject* red87 = new GameObject(true, Tag::Default, "red87");
	//red87->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red87->AddComponent<Transform>(XMFLOAT3(-8.89f, 0.5f, 1.14f), XMFLOAT3(0, 100 * XM_PI / 180.0f, 0), XMFLOAT3(1.28f, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red87->AddComponent<BoxCollider>(true, XMFLOAT3(-8.89f, 0.5f, 1.14f), XMFLOAT3(0, 100 * XM_PI / 180.0f, 0), XMFLOAT3(0.64f, 0.35f, 0.35f));
	RegistGameObject(red87);

	GameObject* red88 = new GameObject(true, Tag::Default, "red88");
	//red88->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red88->AddComponent<Transform>(XMFLOAT3(-14.2f, 0.5f, -3.4f), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.6f, 0.7f), XMFLOAT3(0, 0, 0));
	red88->AddComponent<BoxCollider>(true, XMFLOAT3(-14.2f, 0.5f, -3.4f), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(2, 0.3f, 0.35f));
	RegistGameObject(red88);

	GameObject* red89 = new GameObject(true, Tag::Default, "red89");
	//red89->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red89->AddComponent<Transform>(XMFLOAT3(-14.8f, 0.5f, -3.3f), XMFLOAT3(0, -28 * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red89->AddComponent<BoxCollider>(true, XMFLOAT3(-14.8f, 0.5f, -3.3f), XMFLOAT3(0, -28 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.3f, 0.4f));
	RegistGameObject(red89);

	GameObject* red90 = new GameObject(true, Tag::Default, "red90");
	//red90->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red90->AddComponent<Transform>(XMFLOAT3(-13.2f, 0.5f, -2.7f), XMFLOAT3(0, -7 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red90->AddComponent<BoxCollider>(true, XMFLOAT3(-13.2f, 0.5f, -2.7f), XMFLOAT3(0, -7 * XM_PI / 180.0f, 0), XMFLOAT3(0.7f, 0.3f, 0.4f));
	RegistGameObject(red90);

	GameObject* red91 = new GameObject(true, Tag::Default, "red91");
	//red91->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red91->AddComponent<Transform>(XMFLOAT3(-12.25f, 0.5f, -3.1f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.66f, 1.3f), XMFLOAT3(0, 0, 0));
	red91->AddComponent<BoxCollider>(true, XMFLOAT3(-12.25f, 0.5f, -3.1f), XMFLOAT3(0, 25 * XM_PI / 180.0f, 0), XMFLOAT3(0.65f, 0.33f, 0.65f));
	RegistGameObject(red91);

	GameObject* red92 = new GameObject(true, Tag::Default, "red92");
	//red92->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red92->AddComponent<Transform>(XMFLOAT3(-12.7f, 0.5f, -3.9f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(2.4f, 0.6f, 1.3f), XMFLOAT3(0, 0, 0));
	red92->AddComponent<BoxCollider>(true, XMFLOAT3(-12.7f, 0.5f, -3.9f), XMFLOAT3(0, 45 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.3f, 0.65f));
	RegistGameObject(red92);

	GameObject* red93 = new GameObject(true, Tag::Default, "red93");
	//red93->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red93->AddComponent<Transform>(XMFLOAT3(-11.75f, 0.5f, -3.6f), XMFLOAT3(0, 62 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.6f, 1.4f), XMFLOAT3(0, 0, 0));
	red93->AddComponent<BoxCollider>(true, XMFLOAT3(-11.75f, 0.5f, -3.6f), XMFLOAT3(0, 62 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.3f, 0.7f));
	RegistGameObject(red93);

	GameObject* red94 = new GameObject(true, Tag::Default, "red94");
	//red94->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red94->AddComponent<Transform>(XMFLOAT3(-12.7f, 0.5f, -5.4f), XMFLOAT3(0, 120 * XM_PI / 180.0f, 0), XMFLOAT3(2.1f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red94->AddComponent<BoxCollider>(true, XMFLOAT3(-12.7f, 0.5f, -5.4f), XMFLOAT3(0, 120 * XM_PI / 180.0f, 0), XMFLOAT3(1.05f, 0.3f, 0.4f));
	RegistGameObject(red94);

	GameObject* red95 = new GameObject(true, Tag::Default, "red95");
	//red95->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red95->AddComponent<Transform>(XMFLOAT3(-11.57f, 0.5f, -4.5f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.6f, 0.95f), XMFLOAT3(0, 0, 0));
	red95->AddComponent<BoxCollider>(true, XMFLOAT3(-11.57f, 0.5f, -4.5f), XMFLOAT3(0, 110 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.3f, 0.475f));
	RegistGameObject(red95);

	GameObject* red96 = new GameObject(true, Tag::Default, "red96");
	//red96->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red96->AddComponent<Transform>(XMFLOAT3(-12.43f, 0.5f, -5.7f), XMFLOAT3(0, 145 * XM_PI / 180.0f, 0), XMFLOAT3(1.8f, 0.6f, 0.8f), XMFLOAT3(0, 0, 0));
	red96->AddComponent<BoxCollider>(true, XMFLOAT3(-12.43f, 0.5f, -5.7f), XMFLOAT3(0, 145 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.3f, 0.4f));
	RegistGameObject(red96);

	GameObject* red97 = new GameObject(true, Tag::Default, "red97");
	//red97->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red97->AddComponent<Transform>(XMFLOAT3(-13.25f, 0.5f, -6.3f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.6f, 0.5f), XMFLOAT3(0, 0, 0));
	red97->AddComponent<BoxCollider>(true, XMFLOAT3(-13.25f, 0.5f, -6.3f), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(0.3f, 0.3f, 0.25f));
	RegistGameObject(red97);


	GameObject* fence1 = new GameObject(true, Tag::Default, "fence1");
	//fence1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence1->AddComponent<Transform>(XMFLOAT3(15.8f, 0.5f, 21.78f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence1->AddComponent<BoxCollider>(true, XMFLOAT3(15.8f, 0.5f, 21.78f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence1);

	GameObject* fence2 = new GameObject(true, Tag::Default, "fence2");
	//fence2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence2->AddComponent<Transform>(XMFLOAT3(23.33f, 0.5f, 14.17f), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence2->AddComponent<BoxCollider>(true, XMFLOAT3(23.33f, 0.5f, 14.17f), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence2);

	GameObject* fence3 = new GameObject(true, Tag::Default, "fence3");
	//fence3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence3->AddComponent<Transform>(XMFLOAT3(-0.2f, 0.5f, 30), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(56, 0.4f, 1), XMFLOAT3(0, 0, 0));
	fence3->AddComponent<BoxCollider>(true, XMFLOAT3(-0.2f, 0.5f, 30), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(28, 0.2f, 0.5f));
	RegistGameObject(fence3);

	GameObject* fence4 = new GameObject(true, Tag::Default, "fence4");
	//fence4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence4->AddComponent<Transform>(XMFLOAT3(-26.7f, 0.5f, 2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(52, 0.4f, 1), XMFLOAT3(0, 0, 0));
	fence4->AddComponent<BoxCollider>(true, XMFLOAT3(-26.7f, 0.5f, 2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(26, 0.2f, 0.5f));
	RegistGameObject(fence4);

	GameObject* fence5 = new GameObject(true, Tag::Default, "fence5");
	//fence5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence5->AddComponent<Transform>(XMFLOAT3(31.88f, 0.5f, -2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(56, 0.4f, 1), XMFLOAT3(0, 0, 0));
	fence5->AddComponent<BoxCollider>(true, XMFLOAT3(31.88f, 0.5f, -2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(28, 0.2f, 0.5f));
	RegistGameObject(fence5);

	GameObject* fence6 = new GameObject(true, Tag::Default, "fence6");
	//fence6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence6->AddComponent<Transform>(XMFLOAT3(5, 0.5f, -28.37f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(55, 0.4f, 1), XMFLOAT3(0, 0, 0));
	fence6->AddComponent<BoxCollider>(true, XMFLOAT3(5, 0.5f, -28.37f), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(27.5f, 0.2f, 0.5f));
	RegistGameObject(fence6);

	GameObject* fence7 = new GameObject(true, Tag::Default, "fence7");
	//fence7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence7->AddComponent<Transform>(XMFLOAT3(-10.8f, 0.5f, -19.97f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence7->AddComponent<BoxCollider>(true, XMFLOAT3(-10.8f, 0.5f, -19.97f), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence7);

	GameObject* fence8 = new GameObject(true, Tag::Default, "fence8");
	//fence8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence8->AddComponent<Transform>(XMFLOAT3(-18.5f, 0.5f, -12.18f), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence8->AddComponent<BoxCollider>(true, XMFLOAT3(-18.5f, 0.5f, -12.18f), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence8);

	GameObject* fence9 = new GameObject(true, Tag::Default, "fence9");
	//fence9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence9->AddComponent<Transform>(XMFLOAT3(-23.29f, 0.5f, 26.65f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(14, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence9->AddComponent<BoxCollider>(true, XMFLOAT3(-23.29f, 0.5f, 26.65f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.2f, 0.4f));
	RegistGameObject(fence9);

	GameObject* fence10 = new GameObject(true, Tag::Default, "fence10");
	//fence10->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence10->AddComponent<Transform>(XMFLOAT3(28.21f, 0.5f, -24.83f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(14, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence10->AddComponent<BoxCollider>(true, XMFLOAT3(28.21f, 0.5f, -24.83f), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.2f, 0.4f));
	RegistGameObject(fence10);

	GameObject* fence11 = new GameObject(true, Tag::Default, "fence11");
	//fence11->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence11->AddComponent<Transform>(XMFLOAT3(29.0f, 0.5f, 32.04f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence11->AddComponent<BoxCollider>(true, XMFLOAT3(29.0f, 0.5f, 32.04f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(2.5f, 0.2f, 0.4f));
	RegistGameObject(fence11);

	GameObject* fence12 = new GameObject(true, Tag::Default, "fence12");
	//fence12->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence12->AddComponent<Transform>(XMFLOAT3(33.5f, 0.5f, 27.81f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence12->AddComponent<BoxCollider>(true, XMFLOAT3(33.5f, 0.5f, 27.81f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(2.5f, 0.2f, 0.4f));
	RegistGameObject(fence12);

	GameObject* fence13 = new GameObject(true, Tag::Default, "fence13");
	//fence13->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence13->AddComponent<Transform>(XMFLOAT3(32.9f, 0.5f, 31.5f), XMFLOAT3(0, -140 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence13->AddComponent<BoxCollider>(true, XMFLOAT3(32.9f, 0.5f, 31.5f), XMFLOAT3(0, -140 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence13);

	GameObject* fence14 = new GameObject(true, Tag::Default, "fence14");
	//fence14->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence14->AddComponent<Transform>(XMFLOAT3(-24.67f, 0.5f, -30.08f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(6, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence14->AddComponent<BoxCollider>(true, XMFLOAT3(-24.67f, 0.5f, -30.08f), XMFLOAT3(0, -40 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.2f, 0.4f));
	RegistGameObject(fence14);

	GameObject* fence15 = new GameObject(true, Tag::Default, "fence15");
	//fence15->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence15->AddComponent<Transform>(XMFLOAT3(-28.09f, 0.5f, -25.87f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(6, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence15->AddComponent<BoxCollider>(true, XMFLOAT3(-28.09f, 0.5f, -25.87f), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(3, 0.2f, 0.4f));
	RegistGameObject(fence15);

	GameObject* fence16 = new GameObject(true, Tag::Default, "fence16");
	//fence16->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence16->AddComponent<Transform>(XMFLOAT3(-28.08f, 0.5f, -29.6f), XMFLOAT3(0, -135 * XM_PI / 180.0f, 0), XMFLOAT3(8, 0.4f, 0.8f), XMFLOAT3(0, 0, 0));
	fence16->AddComponent<BoxCollider>(true, XMFLOAT3(-28.08f, 0.5f, -29.6f), XMFLOAT3(0, -135 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.2f, 0.4f));
	RegistGameObject(fence16);

	GameObject* player = new GameObject(true, Tag::Player, "Player");
	player->AddComponent<Renderer>(L"./data/KogMaw.obj", L"./data/KogMaw.dds", 0);
	player->AddComponent<Transform>
		(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
	player->AddComponent<SphereCollider>(0.3f, true);
	player->AddComponent<Player>();
	player->AddComponent<SceneChangerController>();
	player->AddComponent<BulletManager>();
	RegistGameObject(player);

	GameObject* CameraManagerObject = new GameObject(true, Tag::Camera, "CameraManager");
	CameraManagerObject->AddComponent<Transform>(XMFLOAT3(0.0f, 10.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(0, 180 * 0.0174533f, 0));
	CameraManagerObject->AddComponent<CameraManager>();
	CameraManagerObject->AddComponent<ThirdPersonCamera>();
	CameraManagerObject->AddComponent<FirstPersonCamera>();
	CameraManagerObject->AddComponent<ScopeCamera>();
	CameraManagerObject->AddComponent<ArtilleryCamera>();
	RegistGameObject(CameraManagerObject);

	//GameObject* test = new GameObject(true, Tag::Default, "test");
	//test->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	//test->AddComponent<Transform>(XMFLOAT3(1, 2, 1), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	//test->AddComponent<BoxCollider>(true, XMFLOAT3(1, 2, 1), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(0.60f, 0.6f, 0.6f));
	//RegistGameObject(test);

	GameObject* monster = new GameObject(true, Tag::Default, "monster");
	monster->AddComponent<Renderer>(L"./data/golem.obj", L"./data/golem.dds", 0);
	monster->AddComponent<Transform>(XMFLOAT3(0.1f, 0.25f, 0.1f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 0.5f, 0.5f), XMFLOAT3(0, 0, 0));
	//monster->AddComponent<BoxCollider>(true, XMFLOAT3(5, 0.5, 5), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(0.60f, 0.6f, 0.6f));
	RegistGameObject(monster);

	GameObject* nBullet1 = new GameObject(false, Tag::NormalBullet, "normalBullet1");
	nBullet1->AddComponent<Bullet>();
	nBullet1->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f), XMFLOAT3(0, 0, 0));
	nBullet1->AddComponent<RayCollider>(true);
	nBullet1->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(nBullet1);

	GameObject* nBullet2 = new GameObject(false, Tag::NormalBullet, "normalBullet2");
	nBullet2->AddComponent<Bullet>();
	nBullet2->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f), XMFLOAT3(0, 0, 0));
	nBullet2->AddComponent<RayCollider>(true);
	nBullet2->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(nBullet2);

	GameObject* nBullet3 = new GameObject(false, Tag::NormalBullet, "normalBullet3");
	nBullet3->AddComponent<Bullet>();
	nBullet3->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f), XMFLOAT3(0, 0, 0));
	nBullet3->AddComponent<RayCollider>(true);
	nBullet3->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(nBullet3);

	GameObject* nBullet4 = new GameObject(false, Tag::NormalBullet, "normalBullet4");
	nBullet4->AddComponent<Bullet>();
	nBullet4->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f), XMFLOAT3(0, 0, 0));
	nBullet4->AddComponent<RayCollider>(true);
	nBullet4->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(nBullet4);

	GameObject* nBullet5 = new GameObject(false, Tag::NormalBullet, "normalBullet5");
	nBullet5->AddComponent<Bullet>();
	nBullet5->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f), XMFLOAT3(0, 0, 0));
	nBullet5->AddComponent<RayCollider>(true);
	nBullet5->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(nBullet5);


	GameObject* sBullet1 = new GameObject(false, Tag::ScopeBullet, "scopeBullet1");
	sBullet1->AddComponent<ScopeBullet>();
	sBullet1->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10.0f, 10.0f, 10.0f), XMFLOAT3(0, 0, 0));
	sBullet1->AddComponent<RayCollider>(true);
	sBullet1->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(sBullet1);

	GameObject* sBullet2 = new GameObject(false, Tag::ScopeBullet, "scopeBullet2");
	sBullet2->AddComponent<ScopeBullet>();
	sBullet2->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10.0f, 10.0f, 10.0f), XMFLOAT3(0, 0, 0));
	sBullet2->AddComponent<RayCollider>(true);
	sBullet2->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(sBullet2);

	GameObject* sBullet3 = new GameObject(false, Tag::ScopeBullet, "scopeBullet3");
	sBullet3->AddComponent<ScopeBullet>();
	sBullet3->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10.0f, 10.0f, 10.0f), XMFLOAT3(0, 0, 0));
	sBullet3->AddComponent<RayCollider>(true);
	sBullet3->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(sBullet3);

	GameObject* sBullet4 = new GameObject(false, Tag::ScopeBullet, "scopeBullet4");
	sBullet4->AddComponent<ScopeBullet>();
	sBullet4->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10.0f, 10.0f, 10.0f), XMFLOAT3(0, 0, 0));
	sBullet4->AddComponent<RayCollider>(true);
	sBullet4->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(sBullet4);

	GameObject* sBullet5 = new GameObject(false, Tag::ScopeBullet, "scopeBullet5");
	sBullet5->AddComponent<ScopeBullet>();
	sBullet5->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10.0f, 10.0f, 10.0f), XMFLOAT3(0, 0, 0));
	sBullet5->AddComponent<RayCollider>(true);
	sBullet5->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(sBullet5);

	GameObject* aBullet1 = new GameObject(false, Tag::ArtilleryBullet, "ArtilleryBullet1");
	aBullet1->AddComponent<ArtilleryBullet>();
	aBullet1->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(60.0f, 60.0f, 60.0f), XMFLOAT3(0, 0, 0));
	aBullet1->AddComponent<SphereCollider>(0.5f, true);
	aBullet1->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(aBullet1);

	GameObject* aBullet2 = new GameObject(false, Tag::ArtilleryBullet, "ArtilleryBullet2");
	aBullet2->AddComponent<ArtilleryBullet>();
	aBullet2->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(60.0f, 60.0f, 60.0f), XMFLOAT3(0, 0, 0));
	aBullet2->AddComponent<SphereCollider>(0.5f, true);
	aBullet2->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(aBullet2);

	GameObject* aBullet3 = new GameObject(false, Tag::ArtilleryBullet, "ArtilleryBullet3");
	aBullet3->AddComponent<ArtilleryBullet>();
	aBullet3->AddComponent<Transform>(XMFLOAT3(0, 3, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(60.0f, 60.0f, 60.0f), XMFLOAT3(0, 0, 0));
	aBullet3->AddComponent<SphereCollider>(0.5f, true);
	aBullet3->AddComponent<Renderer>(L"./data/bullet.obj", L"./data/1911.dds", 0);
	RegistGameObject(aBullet3);

	GameObject* GUITEST = new GameObject(true, Tag::GUI, "GUITEST");
	GUITEST->AddComponent<Transform>(XMFLOAT3(5, 3, 5), XMFLOAT3(0, 0, 0), XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(0, 0, 0));
	GUITEST->AddComponent<RectTransform>(XMFLOAT4(1,-1,-1,1), XMFLOAT2(0,0), XMFLOAT3(0,0,0), XMFLOAT3(0,0,0));
	GUITEST->AddComponent<WorldSpaceUIRenderer>(L"./data/arrowT1.dds", 1);
	RegistGameObject(GUITEST);

	GameObject* Canvas1 = new GameObject(true, Tag::Canvas, "Canvas");
	Canvas1->AddComponent<Canvas>();
	RegistGameObject(Canvas1);

	GameObject* Light1 = new GameObject(true, Tag::Light, "Light1");
	Light1->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(001.0f, 0.0f, 0.0f, 01.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(1.0f, 00.250f, 1.0f, 1.0f),
		128.0f);
	RegistGameObject(Light1);

	GameObject* Light2 = new GameObject(true, Tag::Light, "Light2");
	Light2->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(001.0f, 0.0f, 0.0f, 01.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(3.0f, 0.50f, 3.0f, 1.0f),
		128.0f);
	RegistGameObject(Light2);

	GameObject* Light3 = new GameObject(true, Tag::Light, "Light3");
	Light3->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(001.0f, 0.0f, 0.0f, 01.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(5.0f, 01.0f, 5.0f, 1.0f),
		128.0f);
	RegistGameObject(Light3);
	
	GameObject* Light4 = new GameObject(true, Tag::Light, "Light4");
	Light4->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(001.0f, 0.0f, 0.0f, 01.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(7.00f, 1.50f, 7.0f, 1.0f),
		128.0f);
	RegistGameObject(Light4);

	GameObject* Light5 = new GameObject(true, Tag::Light, "Light5");
	Light5->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.50f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(001.0f, 0.0f, 0.0f, 01.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(9.0f, 2.0f, 9.0f, 1.0f),
		128.0f);
	RegistGameObject(Light5);

	GameObject* Light6 = new GameObject(true, Tag::Light, "Light6");
	Light6->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(01.0f, 01.0f, 0.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(-2.0f, 01.0f, -2.0f, 1.0f),
		128.0f);
	RegistGameObject(Light6);

	GameObject* Light7 = new GameObject(true, Tag::Light, "Light7");
	Light7->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(0.0f, 01.0f, 0.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(-4.0f, 01.0f, -4.0f, 1.0f),
		128.0f);
	RegistGameObject(Light7);

	GameObject* Light8 = new GameObject(true, Tag::Light, "Light8");
	Light8->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(-6.0f, 01.0f, -6.0f, 1.0f),
		128.0f);
	RegistGameObject(Light8);

	GameObject* Light9 = new GameObject(true, Tag::Light, "Light9");
	Light9->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(0.0f, 01.0f, 01.0f, 1.0f),
		XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f),
		XMFLOAT4(-8.0f, 01.50f, -8.0f, 1.0f),
		128.0f);
	RegistGameObject(Light9);

	GameObject* Light10 = new GameObject(true, Tag::Light, "Light10");
	Light10->AddComponent<LightClass>(
		XMFLOAT3(1.0f, 0.0f, 1.0f),
		XMFLOAT4(0.35f, 0.35f, 0.35f, 1.0f),
		XMFLOAT4(01.0f, 01.0f, 01.0f, 1.0f),
		XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f),
		XMFLOAT4(-10.0f, 01.50f, -10.0f, 1.0f),
		128.0f);
	RegistGameObject(Light10);
}

