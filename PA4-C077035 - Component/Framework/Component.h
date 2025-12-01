#ifndef COMPONENT_H
#define COMPONENT_H

#include "timerclass.h"
#include "inputclass.h"
#include "GameObject.h"

class Collider;
class SceneManager;

#define SCENEMANAGER  SceneManager::GetInstance()

class Component
{
public:
	Component();
	virtual ~Component();
	
public:
	virtual bool InitializeSet();
	virtual bool Initialize();
	virtual bool InitializeRef();
	virtual bool InitializeSynchronization();
	virtual bool PostInitialize();
	
	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);
	virtual void OnTriggerEnter(Collider* other);
	virtual void OnTriggerStay(Collider* other);
	virtual void OnTriggerExit(Collider* other);
	
	virtual void FixedExecute();
	virtual void Execute();
	virtual void LateExecute();
	virtual void PostExecute();
public:
	virtual bool Shutdown();
	virtual void OnEnable();
	virtual void OnDisable();
public:
	GameObject* gameObject;
	bool active;
protected:
	float DeltaTime() const {
		return TimerClass::GetInstance().DeltaTime;
	}

	InputClass& Input() const	{
		return InputClass::GetInstance();
	}

	GameObject* Find(const string& name);
	GameObject* FindObjectWithTag(Tag tag);
	vector<GameObject*> FindObjectsWithTag(Tag tag);

	template<typename T>
	shared_ptr<T> GetComponent();

	template<typename T>
	shared_ptr<T> GetComponentIncludingBase();

	template<typename T>
	shared_ptr<T> GetComponentInChild(bool includeSelf);

	template<typename T>
	shared_ptr<T> GetComponentInParent(bool includeSelf);

	template<typename T>
	vector<shared_ptr<T>> GetComponentsInChild(bool includeSelf);

	template<typename T>
	vector<shared_ptr<T>> GetComponents();

	//template<typename T>
	//vector<shared_ptr<T>> GetAllComponents();
};
/*
template<typename T>
vector<shared_ptr<T>> Component::GetAllComponents()
{
	return gameObject->GetAllComponents<T>();
}*/

template<typename T>
shared_ptr<T> Component::GetComponent()
{
	return gameObject->GetComponent<T>();
}

template<typename T>
shared_ptr<T> Component::GetComponentIncludingBase()
{
	return gameObject->GetComponentIncludingBase<T>();
}

template<typename T>
shared_ptr<T> Component::GetComponentInChild(bool includeSelf)
{
	return gameObject->GetComponentInChild<T>(includeSelf);
}

template<typename T>
shared_ptr<T> Component::GetComponentInParent(bool includeSelf)
{
	return gameObject->GetComponentInParent<T>(includeSelf);
}

template<typename T>
vector<shared_ptr<T>> Component::GetComponentsInChild(bool includeSelf)
{
	return gameObject->GetComponentsInChild<T>(includeSelf);
}

template<typename T>
vector<shared_ptr<T>> Component::GetComponents()
{
	return gameObject->GetComponents<T>();
}
#endif