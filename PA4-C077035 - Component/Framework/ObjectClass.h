#ifndef _OBJECTCLASS_H
#define _OBJECTCLASS_H

#include "GameScene.h"

#include "CameraObject.h"

#include "LightManager.h"
#include "lightclass.h"

#include "ColliderType.h"

#include "CameraManager.h"
#include "Player.h"

#include "DestroyBox.h"

#include "BulletManager.h"
#include "SceneChangerController.h"
#include "CanvasRenderer.h"
#include "GameManager.h"

class ObjectClass : public GameScene
{
public:
	ObjectClass();
	~ObjectClass();
public:
	virtual void CreateGameObject() override;
};

#endif