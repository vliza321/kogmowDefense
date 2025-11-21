#ifndef _GAMESCENE_H
#define _GAMESCENE_H

#pragma once

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene(std::string sceneName);
	~GameScene();
	
	virtual void CreateBaseObject() = 0;
	virtual void CreateGameObject() = 0;

public:
	GameObject* Find(const std::string&);
	GameObject* FindObjectWithTag(Tag);
	vector<GameObject*> FindObjectsWithTag(Tag);
	void RegistGameObject(GameObject*, GameObject*);
	void RegistGameObject(GameObject*);
};

#endif