#include "BoxCollider.h"

BoxCollider::BoxCollider()
	:Collider(true,ColliderType::Box)
{
	Box.pos = XMFLOAT3(0, 0, 0);
	Box.axisX = XMFLOAT3(1, 0, 0);
	Box.axisY = XMFLOAT3(0, 1, 0);
	Box.axisZ = XMFLOAT3(0, 0, 1);
	Box.halfLength = XMFLOAT3(0.5f, 0.5f, 0.5f);
}

BoxCollider::BoxCollider(bool isCollision, XMFLOAT3 pos, XMFLOAT3 rotation, XMFLOAT3 halfLength)
	:Collider(true,ColliderType::Box)
{
	XMVECTOR aX, aY, aZ;
	Box.pos = pos;

	Box.axisX = XMFLOAT3(1, 0, 0);
	Box.axisY = XMFLOAT3(0, 1, 0);
	Box.axisZ = XMFLOAT3(0, 0, 1);

	aX = XMLoadFloat3(&Box.axisX);
	aY = XMLoadFloat3(&Box.axisY);
	aZ = XMLoadFloat3(&Box.axisZ);

	Box.halfLength.x = halfLength.x;
	Box.halfLength.y = halfLength.y;
	Box.halfLength.z = halfLength.z;

	XMMATRIX rMatrix;
	rMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);

	aX = XMVector3TransformNormal(aX, rMatrix);
	aY = XMVector3TransformNormal(aY, rMatrix);
	aZ = XMVector3TransformNormal(aZ, rMatrix);

	XMStoreFloat3(&Box.axisX, XMVector3Normalize(aX));
	XMStoreFloat3(&Box.axisY, XMVector3Normalize(aY));
	XMStoreFloat3(&Box.axisZ, XMVector3Normalize(aZ));
}

BoxCollider::~BoxCollider()
{
}
