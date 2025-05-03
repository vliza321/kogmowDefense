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

class ObjectClass;
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
	ObjectClass* root;

private:
	unordered_map<type_index, deque<shared_ptr<Component>>>components;

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


public:
	bool CompareTag(Tag Tag) const
	{
		if (tag == Tag)
		{
			return true;
		}
		return false;
	}
	void Destroy();
	void Destory(shared_ptr<Component>);
	void SetActive(bool active);
	void SetRoot(ObjectClass*);
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



#endif
