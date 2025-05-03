#include "SphereCollider.h"

SphereCollider::SphereCollider()
	: Collider(true, ColliderType::Sphere)
{
	radius = 1;
}

SphereCollider::SphereCollider(float r, bool isCollision)
	: Collider(isCollision, ColliderType::Sphere)
{
	radius = r;
}

SphereCollider::~SphereCollider()
{
}
