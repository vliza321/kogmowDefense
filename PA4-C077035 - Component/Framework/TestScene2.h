#ifndef _TESTSCENE2_H
#define _TESTSCENE2_H
#pragma once

#include "GameScene.h"
#include "lightclass.h"
#include "SceneChangerController.h"
#include "TestLoop.h"

class TestScene2 :
    public GameScene
{
public:
    TestScene2();
    ~TestScene2();
public:
    virtual void CreateGameObject() override;
};

#endif