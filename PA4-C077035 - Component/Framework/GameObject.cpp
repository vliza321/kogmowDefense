#include "GameObject.h"
#include "Component.h"
#include "Collider.h"

GameObject::GameObject()
{
	active = true;
	tag = Tag::Default;
	name = "GameObject";
	isDestroy = false;
	root = nullptr;
}

GameObject::GameObject(bool Active, Tag Tag, string Name)
{
	active = Active;
	tag = Tag;
	name = Name;
	isDestroy = false;
	root = nullptr;
}

GameObject::~GameObject()
{
	name.clear();
}

bool GameObject::InitializeSet()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (!v->InitializeSet()) return false;
		}
	}
	return true;
}

bool GameObject::Initialize()
{
	for (auto& c : components)
	{
		for (auto& v : c.second) 
		{
			if (!v->Initialize()) return false;
		}
	}
	return true;
}

bool GameObject::InitializeRef()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (!v->InitializeRef()) return false;
		}
	}
	return true;
}

bool GameObject::InitializeSynchronization()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (!v->InitializeSynchronization()) return false;
		}
	}
	return true;
}

bool GameObject::PostInitialize()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (!v->PostInitialize()) return false;
		}
	}
	return true;
}


void GameObject::OnCollisionEnter(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnCollisionEnter(other);
		}
	}
}

void GameObject::OnCollisionStay(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnCollisionStay(other);
		}
	}
}

void GameObject::OnCollisionExit(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnCollisionExit(other);
		}
	}
}

void GameObject::OnTriggerEnter(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnTriggerEnter(other);
		}
	}
}

void GameObject::OnTriggerStay(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnTriggerStay(other);
		}
	}
}

void GameObject::OnTriggerExit(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnTriggerExit(other);
		}
	}
}

void GameObject::FixedExecute()
{
	for (auto& c : components) 
	{
		for (auto& v : c.second) 
		{
			v->FixedExecute(); 
		}
	}
}

void GameObject::Execute()
{
	for (auto& c : components) 
	{
		for (auto& v : c.second) 
		{
			v->Execute();
		}
	}
}

void GameObject::LateExecute()
{
	for (auto& c : components)
	{
		for (auto& v : c.second) 
		{
			v->LateExecute();
		}
	}
}

void GameObject::PostExecute()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->PostExecute();
		}
	}
}

void GameObject::OnEnable()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnEnable();
		}
	}
	active = true;
}

void GameObject::OnDisable()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			v->OnDisable();
		}
	}
	active = false;
}

bool GameObject::Shutdown()
{
	Destroy();
	return true;
}

void GameObject::ApplyDestroy()
{
	for (auto& c : components) 
	{
		auto& vec = c.second;

		for (int i = vec.size() - 1; i >= 0; --i)
		{
			vec[i].reset();  
		}

		vec.clear();
	}
	components.clear();
}

void GameObject::Destroy()
{
	isDestroy = true;
}

void GameObject::Destory(shared_ptr<Component> target)
{
	auto it = components.find(typeid(*target));
	if (it == components.end()) return;  
	
	auto& vec = it->second;

	auto vecIt = std::find(vec.begin(), vec.end(), target);
	if (vecIt != vec.end()) {
		(*vecIt)->Shutdown();
		vecIt->reset(); 
		vec.erase(vecIt);

		if (vec.empty()) {
			components.erase(it);
		}

		return;  // 한 개만 삭제하면 종료
	}
}

void GameObject::SetActive(bool active)
{
	if (active == true)	OnEnable();
	else OnDisable();
}

#include "ObjectClass.h"

void GameObject::SetRoot(ObjectClass* objectClass)
{
	root = objectClass;
}
