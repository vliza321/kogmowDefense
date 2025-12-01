#pragma once
#include "GameScene.h"

class DummyScene : public GameScene
{
public:
	DummyScene() : GameScene("Dummy")
	{
		
	}
	~DummyScene()
	{

	}
public:
	virtual void CreateGameObject() override
	{

	}
};

