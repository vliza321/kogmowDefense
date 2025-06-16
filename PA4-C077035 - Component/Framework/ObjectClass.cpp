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
	m_cameraManager = CameraManagerObject->GetComponentIncludingBase<CameraManager>().get();
	RegistGameObject(CameraManagerObject);

	GameObject* LightSet = new GameObject(true, Tag::Default, "LightManager");
	LightSet->AddComponent<LightManager>();
	m_lightManager = LightSet->GetComponentIncludingBase<LightManager>().get();
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



	GameObject* blue1 = new GameObject(true, Tag::Default, "bluetower1");
	blue1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue1->AddComponent<Transform>(XMFLOAT3(9.2, 0, 6.2), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue1->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue1);

	GameObject* blue2 = new GameObject(true, Tag::Default, "bluetower2");
	blue2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue2->AddComponent<Transform>(XMFLOAT3(29.54, 0, -12.05), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue2->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue2);

	GameObject* blue3 = new GameObject(true, Tag::Default, "bluetower3");
	blue3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue3->AddComponent<Transform>(XMFLOAT3(29.6, 0, 5.08), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue3->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue3);

	GameObject* blue4 = new GameObject(true, Tag::Default, "bluetower4");
	blue4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue4->AddComponent<Transform>(XMFLOAT3(28.9, 0, 14.87), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue4->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue4);

	GameObject* blue5 = new GameObject(true, Tag::Default, "bluetower5");
	blue5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue5->AddComponent<Transform>(XMFLOAT3(20.4, 0, 18.9), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue5->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue5);

	GameObject* blue6 = new GameObject(true, Tag::Default, "bluetower6");
	blue6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue6->AddComponent<Transform>(XMFLOAT3(13.78, 0, 13.75), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue6->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue6);

	GameObject* blue7 = new GameObject(true, Tag::Default, "bluetower7");
	blue7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue7->AddComponent<Transform>(XMFLOAT3(16.5, 0, 27.37), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue7->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue7);

	GameObject* blue8 = new GameObject(true, Tag::Default, "bluetower8");
	blue8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue8->AddComponent<Transform>(XMFLOAT3(6.62, 0, 27.9), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue8->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue8);

	GameObject* blue9 = new GameObject(true, Tag::Default, "bluetower9");
	blue9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	blue9->AddComponent<Transform>(XMFLOAT3(-10, 0, 28), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	blue9->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(blue9);

	GameObject* red1 = new GameObject(true, Tag::Default, "redtower1");
	red1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red1->AddComponent<Transform>(XMFLOAT3(-4.1, 0, -4.0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red1->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red1);
	
	GameObject* red2 = new GameObject(true, Tag::Default, "redtower2");
	red2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red2->AddComponent<Transform>(XMFLOAT3(-8.7, 0, -11.75), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red2->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red2);

	GameObject* red3 = new GameObject(true, Tag::Default, "redtower3");
	red3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red3->AddComponent<Transform>(XMFLOAT3(-15.11, 0, -16.56), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red3->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red3);

	GameObject* red4 = new GameObject(true, Tag::Default, "redtower4");
	red4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red4->AddComponent<Transform>(XMFLOAT3(-23.83, 0, -13.0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red4->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red4);

	GameObject* red5 = new GameObject(true, Tag::Default, "redtower5");
	red5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red5->AddComponent<Transform>(XMFLOAT3(-24.5, 0, -3.180), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red5->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red5);

	GameObject* red6 = new GameObject(true, Tag::Default, "redtower6");
	red6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red6->AddComponent<Transform>(XMFLOAT3(-24.5, 0, 13.6), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red6->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red6);

	GameObject* red7 = new GameObject(true, Tag::Default, "redtower7");
	red7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red7->AddComponent<Transform>(XMFLOAT3(-11.25, 0, -25.3), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red7->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red7);

	GameObject* red8 = new GameObject(true, Tag::Default, "redtower8");
	red8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red8->AddComponent<Transform>(XMFLOAT3(-1.63, 0, -26.02), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red8->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red8);

	GameObject* red9 = new GameObject(true, Tag::Default, "redtower9");
	red9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	red9->AddComponent<Transform>(XMFLOAT3(15.25, 0, -26.11), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	red9->AddComponent<SphereCollider>(0.85f, true);
	RegistGameObject(red9);

	GameObject* bluenexus = new GameObject(true, Tag::Default, "bluenexus");
	bluenexus->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	bluenexus->AddComponent<Transform>(XMFLOAT3(25.88, 0, 24.13), XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2), XMFLOAT3(0, 0, 0));
	bluenexus->AddComponent<SphereCollider>(2.6f, true);
	RegistGameObject(bluenexus);

	GameObject* rednexus = new GameObject(true, Tag::Default, "rednexus");
	rednexus->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	rednexus->AddComponent<Transform>(XMFLOAT3(-20.5, 0, -22.23), XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2), XMFLOAT3(0, 0, 0));
	rednexus->AddComponent<SphereCollider>(2.6f, true);
	RegistGameObject(rednexus);
}

void ObjectClass::CreateGameObject()
{
	GameObject* player = new GameObject(true, Tag::Player, "Player");
	player->AddComponent<Renderer>(L"./data/KogMaw.obj", L"./data/KogMaw.dds", 0);
	player->AddComponent<Transform>
		(XMFLOAT3(3, 0, 3), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
	player->AddComponent<SphereCollider>(0.3f, true);
	player->AddComponent<Player>();
	player->AddComponent<BulletManager>();
	RegistGameObject(player);

	GameObject* test = new GameObject(true, Tag::Default, "test");
	test->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test->AddComponent<Transform>(XMFLOAT3(1, 3, 1), XMFLOAT3(0,0, 0), XMFLOAT3(1, 1, 1), XMFLOAT3(0, 0, 0));
	test->AddComponent<SphereCollider>(0.5f, true);
	RegistGameObject(test);

	GameObject* test1 = new GameObject(true, Tag::Default, "test1");
	test1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test1->AddComponent<Transform>(XMFLOAT3(8.2, 0.5, 0), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.4, 1), XMFLOAT3(0, 0, 0));
	test1->AddComponent<BoxCollider>(true, XMFLOAT3(8.2, 0.5, 0), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(02.0f, 0.2f, 0.5f));
	RegistGameObject(test1);

	GameObject* test2 = new GameObject(true, Tag::Default, "test2");
	test2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test2->AddComponent<Transform>(XMFLOAT3(3.6, 0.5, -4.5), XMFLOAT3(0, 47 * XM_PI / 180.0f, 0), XMFLOAT3(4, 0.4, 1), XMFLOAT3(0, 0, 0));
	test2->AddComponent<BoxCollider>(true, XMFLOAT3(3.6, 0.5, -4.5), XMFLOAT3(0, 47 * XM_PI / 180.0f, 0), XMFLOAT3(02.0f, 0.2f, 0.5f));
	RegistGameObject(test2);

	GameObject* test3 = new GameObject(true, Tag::Default, "test3");
	test3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test3->AddComponent<Transform>(XMFLOAT3(1.25, 0.5, 6.7), XMFLOAT3(0, 48 * XM_PI / 180.0f, 0), XMFLOAT3(4.4, 0.4, 1), XMFLOAT3(0, 0, 0));
	test3->AddComponent<BoxCollider>(true, XMFLOAT3(1.25, 0.5, 6.7), XMFLOAT3(0, 48 * XM_PI / 180.0f, 0), XMFLOAT3(02.2f, 0.2f, 0.5f));
	RegistGameObject(test3);
	
	GameObject* test4 = new GameObject(true, Tag::Default, "test4");
	test4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test4->AddComponent<Transform>(XMFLOAT3(-3.4, 0.5, 2.1), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(4.4, 0.4, 1), XMFLOAT3(0, 0, 0));
	test4->AddComponent<BoxCollider>(true, XMFLOAT3(-3.4, 0.5, 2.1), XMFLOAT3(0, 40 * XM_PI / 180.0f, 0), XMFLOAT3(02.2f, 0.2f, 0.5f));
	RegistGameObject(test4);

	GameObject* test5 = new GameObject(true, Tag::Default, "test5");
	test5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test5->AddComponent<Transform>(XMFLOAT3(-6.11, 0.5, -2.9), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(4.6, 0.4, 1), XMFLOAT3(0, 0, 0));
	test5->AddComponent<BoxCollider>(true, XMFLOAT3(-6.11, 0.5, -2.9), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test5);

	GameObject* test6 = new GameObject(true, Tag::Default, "test6");
	test6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test6->AddComponent<Transform>(XMFLOAT3(-6.00, 0.5, -1.80), XMFLOAT3(0, -70 * XM_PI / 180.0f, 0), XMFLOAT3(2.5, 0.4, 1.60), XMFLOAT3(0, 0, 0));
	test6->AddComponent<BoxCollider>(true, XMFLOAT3(-6.00, 0.5, -1.8), XMFLOAT3(0, -70 * XM_PI / 180.0f, 0), XMFLOAT3(01.25f, 0.2f,0.80f));
	RegistGameObject(test6);

	GameObject* test7 = new GameObject(true, Tag::Default, "test7");
	test7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test7->AddComponent<Transform>(XMFLOAT3(-7.2, 0.5, -2.60), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(3.20, 0.4, 0.70), XMFLOAT3(0, 0, 0));
	test7->AddComponent<BoxCollider>(true, XMFLOAT3(-7.2, 0.5, -2.60), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(01.6f, 0.2f, 0.35f));
	RegistGameObject(test7);

	GameObject* test8 = new GameObject(true, Tag::Default, "test8");
	test8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test8->AddComponent<Transform>(XMFLOAT3(11.3, 0.5, 4.9), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(4.6, 0.4, 1), XMFLOAT3(0, 0, 0));
	test8->AddComponent<BoxCollider>(true, XMFLOAT3(11.3, 0.5, 4.9), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test8);

	GameObject* test9 = new GameObject(true, Tag::Default, "test9");
	test9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test9->AddComponent<Transform>(XMFLOAT3(11.2, 0.5, 3.9), XMFLOAT3(0, -63 * XM_PI / 180.0f, 0), XMFLOAT3(2.6, 0.4, 1.60), XMFLOAT3(0, 0, 0));
	test9->AddComponent<BoxCollider>(true, XMFLOAT3(11.2, 0.5, 3.9), XMFLOAT3(0, -63 * XM_PI / 180.0f, 0), XMFLOAT3(01.3f, 0.2f, 0.80f));
	RegistGameObject(test9);

	GameObject* test10 = new GameObject(true, Tag::Default, "test10");
	test10->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test10->AddComponent<Transform>(XMFLOAT3(12.17, 0.5, 4.57), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(3.20, 0.4, 0.70), XMFLOAT3(0, 0, 0));
	test10->AddComponent<BoxCollider>(true, XMFLOAT3(12.17, 0.5, 4.57), XMFLOAT3(0, -80 * XM_PI / 180.0f, 0), XMFLOAT3(01.6f, 0.2f, 0.35f));
	RegistGameObject(test10);

	GameObject* test11 = new GameObject(true, Tag::Default, "test11");
	test11->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test11->AddComponent<Transform>(XMFLOAT3(7.3, 0.5, 10.6), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(4.6, 0.4, 0.7), XMFLOAT3(0, 0, 0));
	test11->AddComponent<BoxCollider>(true, XMFLOAT3(7.3, 0.5, 10.6), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(02.3f, 0.2f, 0.5f));
	RegistGameObject(test11);

	GameObject* test12 = new GameObject(true, Tag::Default, "test12");
	test12->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test12->AddComponent<Transform>(XMFLOAT3(6.17, 0.5, 12.64), XMFLOAT3(0, -75 * XM_PI / 180.0f, 0), XMFLOAT3(4.80, 0.4, 0.90), XMFLOAT3(0, 0, 0));
	test12->AddComponent<BoxCollider>(true, XMFLOAT3(6.17, 0.5, 12.64), XMFLOAT3(0, -75 * XM_PI / 180.0f, 0), XMFLOAT3(02.4f, 0.2f, 0.45f));
	RegistGameObject(test12);

	GameObject* test13 = new GameObject(true, Tag::Default, "test13");
	test13->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test13->AddComponent<Transform>(XMFLOAT3(7.05, 0.5, 11.9), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(3.00, 0.4, 0.80), XMFLOAT3(0, 0, 0));
	test13->AddComponent<BoxCollider>(true, XMFLOAT3(7.05, 0.5, 11.9), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.4f));
	RegistGameObject(test13);

	GameObject* test14 = new GameObject(true, Tag::Default, "test14");
	test14->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test14->AddComponent<Transform>(XMFLOAT3(8.5, 0.5, 11.4), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(1.80, 0.4, 0.7), XMFLOAT3(0, 0, 0));
	test14->AddComponent<BoxCollider>(true, XMFLOAT3(8.5, 0.5, 11.4), XMFLOAT3(0, 125 * XM_PI / 180.0f, 0), XMFLOAT3(00.9f, 0.2f, 0.35f));
	RegistGameObject(test14);

	GameObject* test15 = new GameObject(true, Tag::Default, "test15");
	test15->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test15->AddComponent<Transform>(XMFLOAT3(4.83, 0.5, 9.4), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.00, 0.4, 1.2), XMFLOAT3(0, 0, 0));
	test15->AddComponent<BoxCollider>(true, XMFLOAT3(4.83, 0.5, 9.4), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(01.0f, 0.2f, 0.6f));
	RegistGameObject(test15);

	GameObject* test16 = new GameObject(true, Tag::Default, "test16");
	test16->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test16->AddComponent<Transform>(XMFLOAT3(3.0, 0.5, 10.7), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(3.0, 0.4, 1.20), XMFLOAT3(0, 0, 0));
	test16->AddComponent<BoxCollider>(true, XMFLOAT3(3.0, 0.5, 10.7), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.6f));
	RegistGameObject(test16);

	GameObject* test17 = new GameObject(true, Tag::Default, "test17");
	test17->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test17->AddComponent<Transform>(XMFLOAT3(11.1, 0.5, 17.2), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(4.8, 0.4, 3.8), XMFLOAT3(0, 0, 0));
	test17->AddComponent<BoxCollider>(true, XMFLOAT3(11.1, 0.5, 17.2), XMFLOAT3(0, -130 * XM_PI / 180.0f, 0), XMFLOAT3(02.4f, 0.2f, 01.9f));
	RegistGameObject(test17);

	GameObject* test18 = new GameObject(true, Tag::Default, "test18");
	test18->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test18->AddComponent<Transform>(XMFLOAT3(10.23, 0.5, 19.28), XMFLOAT3(0, -120 * XM_PI / 180.0f, 0), XMFLOAT3(1.2, 0.4, 3.00), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(10.23, 0.5, 19.28), XMFLOAT3(0, -120 * XM_PI / 180.0f, 0), XMFLOAT3(00.6f, 0.2f, 01.5f));
	RegistGameObject(test18);

	GameObject* test19 = new GameObject(true, Tag::Default, "test19");
	test19->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test19->AddComponent<Transform>(XMFLOAT3(6.6, 0.5, 23.47), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.0, 0.4, 8.5), XMFLOAT3(0, 0, 0));
	test19->AddComponent<BoxCollider>(true, XMFLOAT3(6.6, 0.5, 23.47), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 04.25f));
	RegistGameObject(test19);

	GameObject* test20 = new GameObject(true, Tag::Default, "test20");
	test20->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test20->AddComponent<Transform>(XMFLOAT3(7.58, 0.5, 22.8), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.8, 0.4, 5.0), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(7.58, 0.5, 22.8), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 02.5f));
	RegistGameObject(test20);

	GameObject* test21 = new GameObject(true, Tag::Default, "test21");
	test21->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test21->AddComponent<Transform>(XMFLOAT3(7.8, 0.5, 22.2), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.6, 0.4, 3.3), XMFLOAT3(0, 0, 0));
	test18->AddComponent<BoxCollider>(true, XMFLOAT3(7.8, 0.5, 22.2), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.3f, 0.2f, 01.65f));
	RegistGameObject(test21);

	GameObject* test22 = new GameObject(true, Tag::Default, "test22");
	test22->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test22->AddComponent<Transform>(XMFLOAT3(-6.1, 0.5, 23.44), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.20, 0.4, 9.2), XMFLOAT3(0, 0, 0));
	test22->AddComponent<BoxCollider>(true, XMFLOAT3(-6.1, 0.5, 23.44), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 04.6f));
	RegistGameObject(test22);

	GameObject* test23 = new GameObject(true, Tag::Default, "test23");
	test23->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test23->AddComponent<Transform>(XMFLOAT3(-6.4, 0.5, 22.6), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.8, 0.4, 6.8), XMFLOAT3(0, 0, 0));
	test23->AddComponent<BoxCollider>(true, XMFLOAT3(-6.4, 0.5, 22.6), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 03.4f));
	RegistGameObject(test23);

	GameObject* test24 = new GameObject(true, Tag::Default, "test24");
	test24->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test24->AddComponent<Transform>(XMFLOAT3(-3.74, 0.5, 22.6), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.6, 0.4, 1.4), XMFLOAT3(0, 0, 0));
	test24->AddComponent<BoxCollider>(true, XMFLOAT3(-3.74, 0.5, 22.6), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 0.7f));
	RegistGameObject(test24);

	GameObject* test25 = new GameObject(true, Tag::Default, "test25");
	test25->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test25->AddComponent<Transform>(XMFLOAT3(-7.74, 0.5, 22.2), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.8, 0.4, 3.4), XMFLOAT3(0, 0, 0));
	test25->AddComponent<BoxCollider>(true, XMFLOAT3(-7.74, 0.5, 22.2), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.2f, 1.7f));
	RegistGameObject(test25);

	GameObject* test26 = new GameObject(true, Tag::Default, "test26");
	test26->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test26->AddComponent<Transform>(XMFLOAT3(-6.90, 0.5, 20.8), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(1.1, 0.4, 1.6), XMFLOAT3(0, 0, 0));
	test26->AddComponent<BoxCollider>(true, XMFLOAT3(-6.90, 0.5, 20.8), XMFLOAT3(0, -25 * XM_PI / 180.0f, 0), XMFLOAT3(0.55f, 0.2f, 0.8f));
	RegistGameObject(test26);

	GameObject* test27 = new GameObject(true, Tag::Default, "test27");
	test27->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test27->AddComponent<Transform>(XMFLOAT3(-0.4, 0.5, 19.2), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(3.00, 0.4, 1.0), XMFLOAT3(0, 0, 0));
	test27->AddComponent<BoxCollider>(true, XMFLOAT3(-0.4, 0.5, 19.2), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(01.7f, 0.2f, 0.5f));
	RegistGameObject(test27);

	GameObject* test28 = new GameObject(true, Tag::Default, "test28");
	test28->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test28->AddComponent<Transform>(XMFLOAT3(-1.1, 0.5, 17.4), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(1.40, 0.4, 1.8), XMFLOAT3(0, 0, 0));
	test28->AddComponent<BoxCollider>(true, XMFLOAT3(-1.1, 0.5, 17.4), XMFLOAT3(0, 5 * XM_PI / 180.0f, 0), XMFLOAT3(0.7f, 0.2f, 00.9f));
	RegistGameObject(test28);

	GameObject* test29 = new GameObject(true, Tag::Default, "test29");
	test29->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test29->AddComponent<Transform>(XMFLOAT3(3.12, 0.5, 16.6), XMFLOAT3(0, -35 * XM_PI / 180.0f, 0), XMFLOAT3(3.40, 0.4, 0.80), XMFLOAT3(0, 0, 0));
	test29->AddComponent<BoxCollider>(true, XMFLOAT3(3.12, 0.5, 16.6), XMFLOAT3(0, -35 * XM_PI / 180.0f, 0), XMFLOAT3(01.7f, 0.2f, 0.4f));
	RegistGameObject(test29);

	GameObject* test30 = new GameObject(true, Tag::Default, "test30");
	test30->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test30->AddComponent<Transform>(XMFLOAT3(0.88, 0.5, 16.18), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.8, 0.4, 2.0), XMFLOAT3(0, 0, 0));
	test30->AddComponent<BoxCollider>(true, XMFLOAT3(0.88, 0.5, 16.18), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.9f, 0.2f, 01.0f));
	RegistGameObject(test30);

	GameObject* test31 = new GameObject(true, Tag::Default, "test31");
	test31->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test31->AddComponent<Transform>(XMFLOAT3(2.48, 0.5, 16.6), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(3.0, 0.4, 0.80), XMFLOAT3(0, 0, 0));
	test31->AddComponent<BoxCollider>(true, XMFLOAT3(2.48, 0.5, 16.6), XMFLOAT3(0, -20 * XM_PI / 180.0f, 0), XMFLOAT3(01.5f, 0.2f, 0.4f));
	RegistGameObject(test31);

	GameObject* test32 = new GameObject(true, Tag::Default, "test32");
	test32->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test32->AddComponent<Transform>(XMFLOAT3(-0.7, 0.5, 16.3), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(1.0, 0.4, 2.10), XMFLOAT3(0, 0, 0));
	test32->AddComponent<BoxCollider>(true, XMFLOAT3(-0.7, 0.5, 16.3), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 01.05f));
	RegistGameObject(test32);

	GameObject* test33 = new GameObject(true, Tag::Default, "test33");
	test33->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test33->AddComponent<Transform>(XMFLOAT3(-0.21, 0.5, 16.57), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(1.6, 0.4, 2.10), XMFLOAT3(0, 0, 0));
	test33->AddComponent<BoxCollider>(true, XMFLOAT3(-0.21, 0.5, 16.57), XMFLOAT3(0, -55 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.05f));
	RegistGameObject(test33);

	GameObject* test34 = new GameObject(true, Tag::Default, "test34");
	test34->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test34->AddComponent<Transform>(XMFLOAT3(-13, 0.5, 21.4), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1.6, 0.4, 1.4), XMFLOAT3(0, 0, 0));
	test34->AddComponent<BoxCollider>(true, XMFLOAT3(-13, 0.5, 21.4), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 0.7f));
	RegistGameObject(test34);
	
	GameObject* test35 = new GameObject(true, Tag::Default, "test35");
	test35->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test35->AddComponent<Transform>(XMFLOAT3(-12.1, 0.5, 20.28), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(1.0, 0.4, 1.4), XMFLOAT3(0, 0, 0));
	test35->AddComponent<BoxCollider>(true, XMFLOAT3(-12.1, 0.5, 20.28), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.5f, 0.2f, 0.7f));
	RegistGameObject(test35);

	GameObject* test36 = new GameObject(true, Tag::Default, "test36");
	test36->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test36->AddComponent<Transform>(XMFLOAT3(-13.7, 0.5, 22.63), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.8, 0.4, 1.2), XMFLOAT3(0, 0, 0));
	test36->AddComponent<BoxCollider>(true, XMFLOAT3(-13.7, 0.5, 22.63), XMFLOAT3(0, -50 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 0.6f));
	RegistGameObject(test36);

	GameObject* test37 = new GameObject(true, Tag::Default, "test37");
	test37->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test37->AddComponent<Transform>(XMFLOAT3(-13.8, 0.5, 22.06), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(0.8, 0.4, 1.6), XMFLOAT3(0, 0, 0));
	test36->AddComponent<BoxCollider>(true, XMFLOAT3(-13.8, 0.5, 22.06), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(0.4f, 0.2f, 0.8f));
	RegistGameObject(test37);

	GameObject* test38 = new GameObject(true, Tag::Default, "test38");
	test38->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test38->AddComponent<Transform>(XMFLOAT3(-7.1, 0.5, 15.8), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.20, 0.4, 4.2), XMFLOAT3(0, 0, 0));
	test38->AddComponent<BoxCollider>(true, XMFLOAT3(-7.1, 0.5, 15.8), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 02.1f));
	RegistGameObject(test38);

	GameObject* test39 = new GameObject(true, Tag::Default, "test39");
	test39->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test39->AddComponent<Transform>(XMFLOAT3(-8.4, 0.5, 16.7), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.2, 0.4, 3.4), XMFLOAT3(0, 0, 0));
	test39->AddComponent<BoxCollider>(true, XMFLOAT3(-8.4, 0.5, 16.7), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.6f, 0.2f, 01.7f));
	RegistGameObject(test39);

	GameObject* test40 = new GameObject(true, Tag::Default, "test40");
	test40->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test40->AddComponent<Transform>(XMFLOAT3(-9.6, 0.5, 16.5), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(1.6, 0.4, 2.8), XMFLOAT3(0, 0, 0));
	test40->AddComponent<BoxCollider>(true, XMFLOAT3(-9.6, 0.5, 16.5), XMFLOAT3(0, -60 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.4f));
	RegistGameObject(test40);

	GameObject* test41 = new GameObject(true, Tag::Default, "test41");
	test41->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test41->AddComponent<Transform>(XMFLOAT3(-10.0, 0.5, 15.8), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(1.6, 0.4, 2.8), XMFLOAT3(0, 0, 0));
	test41->AddComponent<BoxCollider>(true, XMFLOAT3(-10.0, 0.5, 15.8), XMFLOAT3(0, -45 * XM_PI / 180.0f, 0), XMFLOAT3(0.8f, 0.2f, 01.4f));
	RegistGameObject(test41);

	GameObject* test42 = new GameObject(true, Tag::Default, "test42");
	test42->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test42->AddComponent<Transform>(XMFLOAT3(-10.1, 0.5, 14.3), XMFLOAT3(0, -105 * XM_PI / 180.0f, 0), XMFLOAT3(2.6, 0.4, 0.6), XMFLOAT3(0, 0, 0));
	test42->AddComponent<BoxCollider>(true, XMFLOAT3(-10.1, 0.5, 14.3), XMFLOAT3(0, -105 * XM_PI / 180.0f, 0), XMFLOAT3(1.3f, 0.2f, 00.3f));
	RegistGameObject(test42);

	GameObject* test43 = new GameObject(true, Tag::Default, "test43");
	test43->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test43->AddComponent<Transform>(XMFLOAT3(-9.6, 0.5, 14.0), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(2.4, 0.4, 0.6), XMFLOAT3(0, 0, 0));
	test43->AddComponent<BoxCollider>(true, XMFLOAT3(-9.6, 0.5, 14.0), XMFLOAT3(0, -90 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.2f, 0.3f));
	RegistGameObject(test43);

	GameObject* test44 = new GameObject(true, Tag::Default, "test44");
	test44->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test44->AddComponent<Transform>(XMFLOAT3(-4.11, 0.5, 13.5), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(2.8, 0.8, 1.2), XMFLOAT3(0, 0, 0));
	test44->AddComponent<BoxCollider>(true, XMFLOAT3(-4.11, 0.5, 13.5), XMFLOAT3(0, -110 * XM_PI / 180.0f, 0), XMFLOAT3(1.4f, 0.2f, 0.6f));
	RegistGameObject(test44);
	
	GameObject* test45 = new GameObject(true, Tag::Default, "test45");
	test45->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test45->AddComponent<Transform>(XMFLOAT3(-4.89, 0.5, 15.0), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(2.4, 0.4, 1.4), XMFLOAT3(0, 0, 0));
	test45->AddComponent<BoxCollider>(true, XMFLOAT3(-4.89, 0.5, 15.0), XMFLOAT3(0, 55 * XM_PI / 180.0f, 0), XMFLOAT3(1.2f, 0.2f, 0.7f));
	RegistGameObject(test45);

	GameObject* test46 = new GameObject(true, Tag::Default, "test46");
	test46->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test46->AddComponent<Transform>(XMFLOAT3(-4.35, 0.5, 11.88), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(3.3, 0.4, 1.7), XMFLOAT3(0, 0, 0));
	test46->AddComponent<BoxCollider>(true, XMFLOAT3(-4.35, 0.5, 11.88), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(01.65f, 0.2f, 0.85f));
	RegistGameObject(test46);

	GameObject* test47 = new GameObject(true, Tag::Default, "test47");
	test47->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test47->AddComponent<Transform>(XMFLOAT3(-4.85, 0.5, 11.3), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(5, 0.4, 0.6), XMFLOAT3(0, 0, 0));
	test47->AddComponent<BoxCollider>(true, XMFLOAT3(-4.85, 0.5, 11.3), XMFLOAT3(0, -15 * XM_PI / 180.0f, 0), XMFLOAT3(02.5f, 0.2f, 0.3f));
	RegistGameObject(test47);

	GameObject* test48 = new GameObject(true, Tag::Default, "test48");
	test48->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test48->AddComponent<Transform>(XMFLOAT3(-6.0, 0.5, 10.6), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(2.3, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	test48->AddComponent<BoxCollider>(true, XMFLOAT3(-6.0, 0.5, 10.6), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(1.15f, 0.2f, 00.4f));
	RegistGameObject(test48);

	GameObject* test49 = new GameObject(true, Tag::Default, "test49");
	test49->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test49->AddComponent<Transform>(XMFLOAT3(-3.6, 0.5, 11.2), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(3.3, 0.4, 1), XMFLOAT3(0, 0, 0));
	test49->AddComponent<BoxCollider>(true, XMFLOAT3(-3.6, 0.5, 11.2), XMFLOAT3(0, -5 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.2f, 0.5f));
	RegistGameObject(test49);

	GameObject* test50 = new GameObject(true, Tag::Default, "test50");
	test50->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	test50->AddComponent<Transform>(XMFLOAT3(-3.1, 0.5, 12.8), XMFLOAT3(0, 59 * XM_PI / 180.0f, 0), XMFLOAT3(3.3, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	test50->AddComponent<BoxCollider>(true, XMFLOAT3(-3.1, 0.5, 12.8), XMFLOAT3(0, 59 * XM_PI / 180.0f, 0), XMFLOAT3(1.65f, 0.2f, 0.4f));
	RegistGameObject(test50);






	GameObject* fence1 = new GameObject(true, Tag::Default, "fence1");
	fence1->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence1->AddComponent<Transform>(XMFLOAT3(15.8, 0.5, 21.78), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence1->AddComponent<BoxCollider>(true, XMFLOAT3(15.8, 0.5, 21.78), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence1);

	GameObject* fence2 = new GameObject(true, Tag::Default, "fence2");
	fence2->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence2->AddComponent<Transform>(XMFLOAT3(23.33, 0.5, 14.17), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence2->AddComponent<BoxCollider>(true, XMFLOAT3(23.33, 0.5, 14.17), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(3.5f, 0.2f, 0.4f));
	RegistGameObject(fence2);

	GameObject* fence3 = new GameObject(true, Tag::Default, "fence3");
	fence3->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence3->AddComponent<Transform>(XMFLOAT3(-0.2, 0.5, 30), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(56, 0.4, 1), XMFLOAT3(0, 0, 0));
	fence3->AddComponent<BoxCollider>(true, XMFLOAT3(-0.2, 0.5, 30), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(28, 0.2f, 0.5f));
	RegistGameObject(fence3);

	GameObject* fence4 = new GameObject(true, Tag::Default, "fence4");
	fence4->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence4->AddComponent<Transform>(XMFLOAT3(-26.7, 0.5, 2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(52, 0.4, 1), XMFLOAT3(0, 0, 0));
	fence4->AddComponent<BoxCollider>(true, XMFLOAT3(-26.7, 0.5, 2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(26, 0.2, 0.5));
	RegistGameObject(fence4);

	GameObject* fence5 = new GameObject(true, Tag::Default, "fence5");
	fence5->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence5->AddComponent<Transform>(XMFLOAT3(31.88, 0.5, -2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(56, 0.4, 1), XMFLOAT3(0, 0, 0));
	fence5->AddComponent<BoxCollider>(true, XMFLOAT3(31.88, 0.5, -2), XMFLOAT3(0, 90 * XM_PI / 180.0f, 0), XMFLOAT3(28, 0.2, 0.5));
	RegistGameObject(fence5);

	GameObject* fence6 = new GameObject(true, Tag::Default, "fence6");
	fence6->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence6->AddComponent<Transform>(XMFLOAT3(5, 0.5, -28.37), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(54, 0.4, 1), XMFLOAT3(0, 0, 0));
	fence6->AddComponent<BoxCollider>(true, XMFLOAT3(5, 0.5, -28.37), XMFLOAT3(0, 0 * XM_PI / 180.0f, 0), XMFLOAT3(27, 0.2, 0.5));
	RegistGameObject(fence6);

	GameObject* fence7 = new GameObject(true, Tag::Default, "fence7");
	fence7->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence7->AddComponent<Transform>(XMFLOAT3(-10.8, 0.5, -19.97), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence7->AddComponent<BoxCollider>(true, XMFLOAT3(-10.8, 0.5, -19.97), XMFLOAT3(0, 63 * XM_PI / 180.0f, 0), XMFLOAT3(3.5, 0.2, 0.4));
	RegistGameObject(fence7);

	GameObject* fence8 = new GameObject(true, Tag::Default, "fence8");
	fence8->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence8->AddComponent<Transform>(XMFLOAT3(-18.5, 0.5, -12.18), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence8->AddComponent<BoxCollider>(true, XMFLOAT3(-18.5, 0.5, -12.18), XMFLOAT3(0, 27 * XM_PI / 180.0f, 0), XMFLOAT3(3.5, 0.2, 0.4));
	RegistGameObject(fence8);

	GameObject* fence9 = new GameObject(true, Tag::Default, "fence9");
	fence9->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence9->AddComponent<Transform>(XMFLOAT3(-23.29, 0.5, 26.65), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(14, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence9->AddComponent<BoxCollider>(true, XMFLOAT3(-23.29, 0.5, 26.65), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.2, 0.4));
	RegistGameObject(fence9);

	GameObject* fence10 = new GameObject(true, Tag::Default, "fence10");
	fence10->AddComponent<Renderer>(L"./data/cube.obj", L"./data/KogMaw.dds", 0);
	fence10->AddComponent<Transform>(XMFLOAT3(28.21, 0.5, -24.83), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(14, 0.4, 0.8), XMFLOAT3(0, 0, 0));
	fence10->AddComponent<BoxCollider>(true, XMFLOAT3(28.21, 0.5, -24.83), XMFLOAT3(0, 135 * XM_PI / 180.0f, 0), XMFLOAT3(7, 0.2, 0.4));
	RegistGameObject(fence10);




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

	GameObject* Canvas1 = new GameObject(true, Tag::Canvas, "Canvas");
	Canvas1->AddComponent<Canvas>();
	RegistGameObject(Canvas1);
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
	if (!(CanvasRenderManager::GetInstance().InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Canvas InitializeRender GameObjects.", L"Error", MB_OK);
		return false;
	}
	if (!(RenderManager::GetInstance().InitializeRender(device)))
	{
		MessageBox(hwnd, L"Could not Render InitializeRender GameObjects.", L"Error", MB_OK);
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
				MessageBox(hwnd, L"Could not InitializeSynchronization GameObjects.", L"Error", MB_OK);
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
				MessageBox(hwnd, L"Could not PostInitialize GameObjects.", L"Error", MB_OK);
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

bool ObjectClass::Render(TextureShaderClass* textureShader, D3DClass* d3d, int)
{
	XMFLOAT4 diffuseColor[8];
	XMFLOAT4 lightPosition[8];

	for (int i = 0; i < 8; ++i) {
		diffuseColor[i] = GetLights(i).diffuseColor;
		lightPosition[i] = GetLights(i).position;
	}

	return RenderManager::GetInstance().RenderAll(textureShader, d3d, m_cameraManager->GetViewMatrix());
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

