#ifndef _GAMESCENE_H
#define _GAMESCENE_H

#pragma once

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene(std::string sceneName);
	~GameScene();
	
	virtual void CreateGameObject() = 0;

public:
	GameObject* Find(const std::string&);
	GameObject* FindObjectWithTag(Tag);

	vector<GameObject*> FindObjectsWithTag(Tag);
	void RegistGameObject(GameObject*, GameObject*);
	void RegistGameObject(GameObject*);


	template<typename T>
	vector<shared_ptr<T>> GetAllComponents();
};

template<typename T>
vector<shared_ptr<T>> GameScene::GetAllComponents()
{
	vector<shared_ptr<T>> result;

	for (auto& go : m_gameObjects)
	{
		vector<shared_ptr<T>> temt = go->GetComponentsInChildIncludingBase<T>(true);
		for (auto c : temt)
		{
			result.push_back(c);
		}
	}
	return result;
}

#endif