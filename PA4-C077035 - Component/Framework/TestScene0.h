#pragma once
#include "GameScene.h"
#include "CanvasRenderer.h"
#include "SceneChangerController.h"
class TestScene0 :
    public GameScene
{
public:
    TestScene0() : GameScene(string("TestScene0"))
    {

    }
    ~TestScene0()
    {

    }
    virtual void CreateGameObject() override;
};

