#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

#include "Scene.h"

#include "CameraObject.h"

#include "LightManager.h"
#include "lightclass.h"

#include "ColliderType.h"

#include "CameraManager.h"
#include "Player.h"

#include "BulletManager.h"

class ObjectClass : public Scene
{
public:
	ObjectClass();
	~ObjectClass();
public:
	virtual void CreateBaseObject() override;
	virtual void CreateGameObject() override;
};

#endif