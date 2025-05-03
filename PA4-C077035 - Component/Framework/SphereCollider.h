#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
public:
	SphereCollider();
	SphereCollider(float r, bool isCollision);
	~SphereCollider();
public:
	float radius;
};

