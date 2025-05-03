#include "Component.h"

Component::Component()
{
	gameObject = 0;
	active = true;
}

Component::~Component()
{

}

bool Component::InitializeSet()
{
	return true;
}

bool Component::Initialize()
{
	return true;
}

bool Component::InitializeRef()
{
	return true;
}

bool Component::InitializeSynchronization()
{
	return true;
}

bool Component::PostInitialize()
{
	return true;
}

void Component::OnCollisionEnter(Collider* other)
{
}

void Component::OnCollisionStay(Collider* other)
{
}

void Component::OnCollisionExit(Collider* other)
{
}

void Component::OnTriggerEnter(Collider* other)
{
}

void Component::OnTriggerStay(Collider* other)
{
}

void Component::OnTriggerExit(Collider* other)
{
}

void Component::FixedExecute()
{
}

void Component::Execute()
{
}

void Component::LateExecute()
{
}

void Component::PostExecute()
{
}

bool Component::Shutdown()
{
	if (!gameObject)
	{
		gameObject = 0;
	}
	return true;
}

void Component::OnEnable()
{

}

void Component::OnDisable()
{

}