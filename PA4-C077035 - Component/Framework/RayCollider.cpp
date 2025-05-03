#include "RayCollider.h"

RayCollider::RayCollider()
	: Collider(true, ColliderType::Ray)
{
}

RayCollider::RayCollider(bool isCollision)
	: Collider(isCollision, ColliderType::Ray)
{
}

RayCollider::~RayCollider()
{
}
