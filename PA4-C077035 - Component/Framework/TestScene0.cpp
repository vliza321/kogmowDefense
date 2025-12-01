#include "TestScene0.h"

void TestScene0::CreateGameObject()
{
	GameObject* Canvas1 = new GameObject(true, Tag::Canvas, "Canvas");
	Canvas1->AddComponent<CanvasRenderer>(L"./data/Title.dds", XMFLOAT4(800, 450, -800, -450));
	Canvas1->AddComponent<SceneChangerController>();
	RegistGameObject(Canvas1);
}
