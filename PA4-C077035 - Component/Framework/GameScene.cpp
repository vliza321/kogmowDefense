#include "GameScene.h"

GameScene::GameScene(std::string sceneName)
	:BaseScene(sceneName)
{

}

GameScene::~GameScene()
{

}


GameObject* GameScene::Find(const string& name)
{
	for (auto& go : m_vGameObjects)
	{
		auto find = go->Find(name);
		if (find != nullptr) return find;
	}
	return nullptr;
}

GameObject* GameScene::FindObjectWithTag(Tag tag)
{
	for (auto& go : m_vGameObjects)
	{
		auto find = go->Find(tag);
		if (find != nullptr) return find;
	}
	return nullptr;
}

vector<GameObject*> GameScene::FindObjectsWithTag(Tag tag)
{
	vector<GameObject*> Objects;
	for (auto& go : m_vGameObjects)
	{
		go->Find(tag, Objects);
	}
	return Objects;
}

void GameScene::RegistGameObject(GameObject* Entity, GameObject* parent)
{
	m_vGameObjects.push_back(Entity);
	Entity->SetRoot(this);
	Entity->SetParent(parent);
}

void GameScene::RegistGameObject(GameObject* Entity)
{
	m_vGameObjects.push_back(Entity);
	Entity->SetRoot(this);
	Entity->SetParent(nullptr);
}
