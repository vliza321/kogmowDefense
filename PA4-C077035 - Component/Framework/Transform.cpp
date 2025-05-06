#include "Transform.h"
#include "Collision.h"
#include "MoveEvent.h"

Transform::Transform()
{
	position = XMFLOAT3(0,0,0);
	rotation = XMFLOAT3(0, 0, 0);
	scale = XMFLOAT3(1, 1, 1);
	eulerRotation = XMFLOAT3(0, 0, 0);

	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
}

Transform::Transform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 scale, XMFLOAT3 eulerRot)
	:position(pos), rotation(rot), scale(scale), eulerRotation(eulerRot)
{
	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
}

Transform::~Transform()
{
}

void Transform::Translate(XMFLOAT3 t)
{
	moveVector = t;
	MoveEvent* moveEvent = new MoveEvent;
	moveEvent->transform = this;
	moveEvent->MoveVector = t;
	Collision::GetInstance().AddEvent(moveEvent);
}

void Transform::ApplyTranslate(XMFLOAT3 t)
{
	position.x += t.x;
	position.y += t.y;
	position.z += t.z;

	moveVector = XMFLOAT3(0, 0, 0);
}
