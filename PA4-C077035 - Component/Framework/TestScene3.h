#ifndef _TESTSCENE3_H
#define _TESTSCENE3_H

#pragma once
#include "GameScene.h"
#include "CameraObject.h"
#include "lightclass.h"
#include "TestPlayer.h"
#include "SceneChangerController.h"

class TestScene3 :
    public GameScene
{
public:
    TestScene3();
    ~TestScene3();
public:
    virtual void CreateGameObject() override;
};

#endif