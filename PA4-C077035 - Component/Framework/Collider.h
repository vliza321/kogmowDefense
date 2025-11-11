#ifndef COLLIDER_H
#define COLLIDER_H

#include <DirectXMath.h>
#include <d3d11.h>
#include "Component.h"
#include "ColliderType.h"

using namespace std;
using namespace DirectX;

class Collider : public Component
{
public:
	Collider();
	Collider(bool isCollision, ColliderType type);
	virtual ~Collider();

public:
	virtual bool Shutdown() override;
	virtual bool InitializeRef() override;
private:
	ColliderType type;
	Collider* trackingCollider;
public:
	ColliderType GetColliderType()
	{
		return type;
	}

	Collider* GetTrackingCollider()
	{
		return trackingCollider;
	}

	void SetTrackingCollider(Collider* other)
	{
		trackingCollider = other;
	}
public:
	bool isCollision;
};

#endif 