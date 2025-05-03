#include "Collider.h"
#include "Collision.h"

Collider::Collider()
	:Component()
{
	this->isCollision = true;
	this->type = ColliderType::Sphere;
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

}

bool Collider::Shutdown()
{
	bool result = false;
	result = Collision::GetInstance().RemoveCollider(this);
	return result;
}

bool Collider::InitializeRef()
{
	Collision::GetInstance().AddCollider(this);
	return true;
}
