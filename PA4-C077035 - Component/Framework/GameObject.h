#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#pragma once
#include <iostream>
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <deque>

#include "algorithm"
#include "Tag.h"

using namespace std;
using namespace DirectX;

class GameScene;
class Component;
class Collider;

class GameObject
{
public:
	GameObject();
	GameObject(bool, Tag, string);
	~GameObject();
public:
	bool InitializeSet();
	bool Initialize();
	bool InitializeRef();
	bool InitializeSynchronization();
	bool PostInitialize();
	
	void OnCollisionEnter(Collider* other);
	void OnCollisionStay(Collider* other);
	void OnCollisionExit(Collider* other);
	void OnTriggerEnter(Collider* other);
	void OnTriggerStay(Collider* other);
	void OnTriggerExit(Collider* other);
	
	void FixedExecute();
	void Execute();
	void LateExecute();
	void PostExecute();

public:
	void OnEnable();
	void OnDisable();
	bool Shutdown();
	void ApplyDestroy();

public:
	bool active;
	Tag tag;
	string name;
	bool isDestroy;
	GameScene* root;

private:
	unsigned int id;

private:
	unordered_map<type_index, deque<shared_ptr<Component>>>components;

public:
	vector<GameObject*> child;
	GameObject* parent;
public:
	template<typename T>
	void AddComponent(std::shared_ptr<T> component);

	template<typename T>
	void AddComponent(T* component);

	template<typename T, typename... Args>
	void AddComponent(Args&&... args);

	template<typename T>
	std::shared_ptr<T> GetComponent();

	template<typename T>
	std::vector<std::shared_ptr<T>> GetComponents();

	template<typename T>
	std::shared_ptr<T> GetComponentIncludingBase();

	template<typename T>
	std::shared_ptr<T> GetComponentInChild(bool);

	template<typename T>
	std::shared_ptr<T> GetComponentInParent(bool);

	template<typename T>
	std::vector<shared_ptr<T>> GetComponentsInChild(bool includeSelf);

	template<typename T>
	std::vector<std::shared_ptr<T>> GetComponentsIncludingBase();

	template<typename T>
	std::vector<shared_ptr<T>> GetComponentsInChildIncludingBase(bool includeSelf);


public:
	bool CompareTag(Tag Tag) const
	{
		if (tag == Tag)
		{
			return true;
		}
		return false;
	}

	GameScene& Root() const
	{
		return *root;
	}

	void SetObjectID(unsigned int objid)
	{
		this->id = objid;
	}

	int GetObjectID()
	{
		return id;
	}

	void Destroy();
	void Destory(shared_ptr<Component>);
	void SetActive(bool active);
	void SetRoot(GameScene*);
	void SetParent(GameObject*);

	GameObject* Find(const string& name)
	{
		if (this->name == name)
		{
			return this;
		}
		for (auto& c : child)
		{
			auto n = c->Find(name);
			if (n != nullptr) return n;
		}
		return nullptr;
	}

	GameObject* Find(const Tag& tag)
	{
		if (CompareTag(tag))
		{
			return this;
		}
		for (auto& c : child)
		{
			auto n = c->Find(tag);
			if (n != nullptr) return n;
		}
		return nullptr;
	}

	void Find(const Tag& tag, vector<GameObject*>& out)
	{
		if (CompareTag(tag))
		{
			out.push_back(this);
		}
		for (auto& c : child)
		{
			c->Find(tag,out);
		}
	}

public:
	int ChildCount() const
	{
		return child.size();
	}
};

#include "Component.h"
#include "RenderComponent.h"

template<typename T>
void GameObject::AddComponent(std::shared_ptr<T> component)
{
	if (component->gameObject != 0) return;
	if (!std::is_base_of<Component, T>::value) {
		std::cerr << "Error: T must inherit from Component" << std::endl;
		return;
	}
	component->gameObject = this;

	components[typeid(T)].push_back(component);
}


template<typename T>
void GameObject::AddComponent(T* component)
{
	if (component->gameObject != 0) return;
	if (!std::is_base_of<Component, T>::value) {
		std::cerr << "Error: T must inherit from Component" << std::endl;
		return;
	}
	component->gameObject = this;

	std::shared_ptr<T> ptr(component);

	components[typeid(T)].push_back(ptr);
}

template<typename T, typename ...Args>
void GameObject::AddComponent(Args && ...args)
{
	if (!std::is_base_of<Component, T>::value)
	{
		std::cerr << "Error: T must inherit from Component" << std::endl;
		return;
	}

	std::shared_ptr<T> ptr = std::make_shared<T>(std::forward<Args>(args)...);

	if (ptr->gameObject)
	{
		return;
	}
	components[typeid(T)].push_back(ptr);
	ptr->gameObject = this;

}

template<typename T>
std::shared_ptr<T> GameObject::GetComponent()
{
	auto it = components.find(typeid(T));

	if (it != components.end() && !it->second.empty())
	{
		return static_pointer_cast<T>(it->second.front());
	}

	return nullptr;
}

template<typename T>
std::shared_ptr<T> GameObject::GetComponentIncludingBase()
{
	auto it = components.find(typeid(T));

	if (it != components.end() && !it->second.empty())
	{
		return static_pointer_cast<T>(it->second.front());
	}

	for (auto it = components.begin(); it != components.end(); ++it)
	{
		auto& componentDeque = it->second;

		for (const auto& component : componentDeque)
		{
			auto casted = std::dynamic_pointer_cast<T>(component);
			if (casted) return casted;
		}
	}
	return nullptr;
}

template<typename T>
std::vector<std::shared_ptr<T>> GameObject::GetComponents()
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

	std::vector<std::shared_ptr<T>> result;

	auto it = components.find(typeid(T));
	if (it != components.end())
	{
		for (const auto& compo : it->second)
		{
			result.push_back(std::static_pointer_cast<T>(compo));
		}
	}

	return result;
}

template<typename T>
std::shared_ptr<T> GameObject::GetComponentInChild(bool includeSelf)
{
	// 나 자신을 포함해 찾는다면 시작하는 게임 오브젝트도 서칭
	if (includeSelf)
	{
		auto component = GetComponent<T>();
		if (component) return component;
	}
	// 아무튼 리턴 못했으면 자식을 서칭(DFS) : 자식은 무조건 자신을 봐야하기에 true
	for (const auto& c : child)
	{
		auto component = c->GetComponentInChild<T>(true);
		if (component) return component;
	}
	// 자식도 리턴 못했으면 nullptr 리턴
	return nullptr;
}

template<typename T>
std::shared_ptr<T> GameObject::GetComponentInParent(bool includeSelf)
{
	// 나 자신을 포함해 찾는다면 시작하는 게임 오브젝트도 서칭
	if (includeSelf)
	{
		auto component = GetComponent<T>();
		if (component) return component;
	}

	// 아무튼 리턴 못했으면 부모를 서칭(Climbing) : 부모는 무조건 자신을 봐야하기에 true
	if (parent != nullptr)
	{
		auto component = parent->GetComponentInParent<T>(true);
		if (component) return component;
	}
	// 부모도 리턴 못했으면 nullptr 리턴
	return nullptr;
}

template<typename T>
vector<shared_ptr<T>> GameObject::GetComponentsInChild(bool includeSelf)
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

	std::vector<std::shared_ptr<T>> result;

	// 나 자신을 포함해 찾는다면 시작하는 게임 오브젝트도 서칭
	if (includeSelf)
	{
		auto comps = GetComponents<T>();
		result.insert(result.end(), comps.begin(), comps.end());
	}
	// 아무튼 리턴 못했으면 자식을 서칭(DFS) : 자식은 무조건 자신을 봐야하기에 true
	for (const auto& c : child)
	{
		auto comps = c->GetComponentsInChild<T>(true);
		result.insert(result.end(), comps.begin(), comps.end());
	}

	return result;
}

/*=====================================================================================*/

template<typename T>
std::vector<std::shared_ptr<T>> GameObject::GetComponentsIncludingBase()
{
	std::vector<std::shared_ptr<T>> result;

	for (auto it = components.begin(); it != components.end(); ++it)
	{
		auto& componentDeque = it->second;

		for (const auto& component : componentDeque)
		{
			auto casted = std::dynamic_pointer_cast<T>(component);
			if (casted) result.push_back(casted);
		}
	}
	return result;
}

template<typename T>
vector<shared_ptr<T>> GameObject::GetComponentsInChildIncludingBase(bool includeSelf)
{
	std::vector<std::shared_ptr<T>> result;

	// 나 자신을 포함해 찾는다면 시작하는 게임 오브젝트도 서칭
	if (includeSelf)
	{
		auto comps = GetComponentsIncludingBase<T>();
		result.insert(result.end(), comps.begin(), comps.end());
	}

	// 아무튼 리턴 못했으면 자식을 서칭(DFS) : 자식은 무조건 자신을 봐야하기에 true
	for (const auto& c : child)
	{
		auto comps = c->GetComponentsInChildIncludingBase<T>(true);
		if (!comps.empty())
		{
			result.insert(result.end(), comps.begin(), comps.end());
		}
	}

	return result;
}
#endif
