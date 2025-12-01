#include "SceneChangerController.h"
#include "SceneManager.h"

SceneChangerController::SceneChangerController()
{
	PoVTimer = POVMAXTIMER;
	canChangePov = true;
}

SceneChangerController::~SceneChangerController()
{
}

void SceneChangerController::Execute()
{
	if (!canChangePov) PoVTimer -= DeltaTime();
	(PoVTimer < 0) ? canChangePov = true : canChangePov = false;

	if (canChangePov)
	{
		auto& input = Input();
		if (input.IsKey(DIK_1))
		{
			SCENEMANAGER.StartScene(1);
		}
		if (input.IsKey(DIK_2))
		{
			SCENEMANAGER.StartScene(2);
		}
		if (input.IsKey(DIK_3))
		{
			SCENEMANAGER.StartScene(3);
		}
		if (input.IsKey(DIK_4))
		{
			SCENEMANAGER.StartScene(4);
		}
		canChangePov = false;	
	}
}
