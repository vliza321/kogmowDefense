#ifndef _TESTSCENE1_H
#define _TESTSCENE1_H

#pragma once
#include "GameScene.h"
#include "CameraObject.h"
#include "lightclass.h"
#include "Player.h"
#include "SceneChangerController.h"
#include "TestLoop.h"

class TestScene1 :
    public GameScene
{
public:
    TestScene1();
    ~TestScene1();
public:
    virtual void CreateGameObject() override;
};

#endif
