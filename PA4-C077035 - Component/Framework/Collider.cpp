#include "Collider.h"
#include "Collision.h"

#include "Scene.h"

Collider::Collider()
	:Component()
{
	this->isCollision = true;
	this->type = ColliderType::None;
	trackingCollider = nullptr;
}

Collider::Collider(bool isCollision, ColliderType type)
	: Component()
{
	this->isCollision = isCollision;
	this->type = type;
	trackingCollider = nullptr;
}

Collider::~Collider()
{
	this->type = ColliderType::None;
	trackingCollider = nullptr;
}

bool Collider::Shutdown()
{
	bool result = false;
	result = gameObject->root->GetCollision()->RemoveCollider(this);
	return result;
}

bool Collider::InitializeRef()
{
	gameObject->root->GetCollision()->AddCollider(this);
	return true;
}
