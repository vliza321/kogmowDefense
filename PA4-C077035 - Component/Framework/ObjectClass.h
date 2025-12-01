#ifndef _OBJECTCLASS_H
#define _OBJECTCLASS_H

#include "GameScene.h"

#include "CameraObject.h"

#include "LightManager.h"
#include "lightclass.h"

#include "ColliderType.h"

#include "CameraManager.h"
#include "Player.h"

#include "BulletManager.h"
#include "SceneChangerController.h"

class ObjectClass : public GameScene
{
public:
	ObjectClass();
	~ObjectClass();
public:
	virtual void CreateGameObject() override;
};

#endif