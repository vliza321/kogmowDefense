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
	parent = nullptr;
}

GameObject::GameObject(bool Active, Tag Tag, string Name)
{
	active = Active;
	tag = Tag;
	name = Name;
	isDestroy = false;
	root = nullptr;
	parent = nullptr;
}

GameObject::~GameObject()
{
	ApplyDestroy();
	name.clear();
	root = nullptr;
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
	for (auto& c : child)
	{
		if(!c->InitializeSet()) return false;
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
	for (auto& c : child)
	{
		if (!c->Initialize()) return false;
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
	for (auto& c : child)
	{
		if (!c->InitializeRef()) return false;
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
	for (auto& c : child)
	{
		if (!c->InitializeSynchronization()) return false;
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
	for (auto& c : child)
	{
		if (!c->PostInitialize()) return false;
	}
	return true;
}


void GameObject::OnCollisionEnter(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnCollisionEnter(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnCollisionEnter(other);
	}
}

void GameObject::OnCollisionStay(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnCollisionStay(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnCollisionStay(other);
	}
}

void GameObject::OnCollisionExit(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnCollisionExit(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnCollisionExit(other);
	}
}

void GameObject::OnTriggerEnter(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnTriggerEnter(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnTriggerEnter(other);
	}
}

void GameObject::OnTriggerStay(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnTriggerStay(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnTriggerStay(other);
	}
}

void GameObject::OnTriggerExit(Collider* other)
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->OnTriggerExit(other);
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnTriggerExit(other);
	}
}

void GameObject::FixedExecute()
{
	for (auto& c : components) 
	{
		for (auto& v : c.second) 
		{
			if (v->active) v->FixedExecute();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->FixedExecute();
	}
}

void GameObject::Execute()
{
	for (auto& c : components) 
	{
		for (auto& v : c.second) 
		{
			if (v->active) v->Execute();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->Execute();
	}
}

void GameObject::LateExecute()
{
	for (auto& c : components)
	{
		for (auto& v : c.second) 
		{
			if (v->active) v->LateExecute();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->LateExecute();
	}
}

void GameObject::PostExecute()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if (v->active) v->PostExecute();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->PostExecute();
	}
}

void GameObject::OnEnable()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if(v->active) v->OnEnable();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnEnable();
	}
	active = true;
}

void GameObject::OnDisable()
{
	for (auto& c : components)
	{
		for (auto& v : c.second)
		{
			if(v->active) v->OnDisable();
		}
	}
	for (auto& c : child)
	{
		if (c->active) c->OnDisable();
	}
	active = false;
}

bool GameObject::Shutdown()
{
	ApplyDestroy();
	return true;
}

void GameObject::ApplyDestroy()
{
	for (auto& c : components) 
	{
		auto& vec = c.second;

		for (int i = vec.size() - 1; i >= 0; --i)
		{
			vec[i]->OnDisable();
			vec[i].reset();  
		}

		vec.clear();
	}
	components.clear();
	parent = nullptr;
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

#include "GameScene.h"

void GameObject::SetRoot(GameScene* scene)
{
	root = scene;
}

void GameObject::SetParent(GameObject* parent)
{
	this->parent = parent;
	if(parent != nullptr) parent->child.push_back(this);
}
