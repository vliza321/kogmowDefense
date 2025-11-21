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
	virtual void CreateBaseObject() override
	{

	}
	virtual void CreateGameObject() override
	{

	}
};

