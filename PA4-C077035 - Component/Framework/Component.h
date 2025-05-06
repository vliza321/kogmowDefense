#ifndef COMPONENT_H
#define COMPONENT_H

#pragma once
#include "timerclass.h"
#include "inputclass.h"
#include "GameObject.h"

class Collider;

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
	float GetDeltaTime() const {
		return TimerClass::GetInstance().DeltaTime;
	}

	const InputClass& GetInput() const
	{
		return InputClass::GetInstance();
	}
};
#endif