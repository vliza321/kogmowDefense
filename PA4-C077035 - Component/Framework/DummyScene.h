#pragma once
#include "Scene.h"
class DummyScene : public Scene
{
public:
	DummyScene() : Scene("Dummy")
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

