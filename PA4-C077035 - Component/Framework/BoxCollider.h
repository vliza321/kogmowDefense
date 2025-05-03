#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	struct OBB
	{
		XMFLOAT3 pos;
		XMFLOAT3 axisX;
		XMFLOAT3 axisY;
		XMFLOAT3 axisZ;
		XMFLOAT3 halfLength;
		float padding;
	} Box;
public:
	BoxCollider();
	BoxCollider(bool isCollision, XMFLOAT3 pos, XMFLOAT3 rotation, XMFLOAT3 halfLength);
	~BoxCollider();
};

