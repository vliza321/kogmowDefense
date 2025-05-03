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
	~Collider();

public:
	virtual bool Shutdown() override;
	virtual bool InitializeRef() override;

public:
	bool isCollision;
	ColliderType type;
	Collider* trackingCollider;
};

#endif 