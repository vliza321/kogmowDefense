#include "Transform.h"
#include "Collision.h"
#include "MoveEvent.h"

#define epsilon 0.0001f

Transform::Transform()
{
	position = XMFLOAT3(0,0,0);
	rotation = XMFLOAT3(0, 0, 0);
	scale = XMFLOAT3(1, 1, 1);
	eulerRotation = XMFLOAT3(0, 0, 0);

	prevRotation = XMFLOAT3(0, 0, 0);
	prevScale = XMFLOAT3(1, 1, 1);
	prevEulerRotation = XMFLOAT3(0, 0, 0);

	WorldMatrix = XMMatrixIdentity();

	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);
}

Transform::Transform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 scale, XMFLOAT3 eulerRot)
	:position(pos), rotation(rot), scale(scale), eulerRotation(eulerRot), prevRotation(rot), prevEulerRotation(eulerRot), prevScale(scale)
{
	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

	SetWorldMatrix();
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

	SetWorldMatrix();

	moveVector = XMFLOAT3(0, 0, 0);
}

void Transform::SetWorldMatrix()
{
	WorldMatrix = XMMatrixScaling(scale.x, scale.y, scale.z)
		* XMMatrixRotationX(rotation.x)
		* XMMatrixRotationY(rotation.y)
		* XMMatrixRotationZ(rotation.z)
		* XMMatrixRotationRollPitchYaw(eulerRotation.x, eulerRotation.y, eulerRotation.z)
		* XMMatrixTranslation(position.x, position.y, position.z);
}

void Transform::PostExecute()
{
	
	bool rotationChanged =
		fabs(rotation.x - prevRotation.x) > epsilon ||
		fabs(rotation.y - prevRotation.y) > epsilon ||
		fabs(rotation.z - prevRotation.z) > epsilon;

	bool scaleChanged =
		fabs(scale.x - prevScale.x) > epsilon ||
		fabs(scale.y - prevScale.y) > epsilon ||
		fabs(scale.z - prevScale.z) > epsilon;

	bool eulerChanged = 
		fabs(eulerRotation.x - prevEulerRotation.x) > epsilon ||
		fabs(eulerRotation.y - prevEulerRotation.y) > epsilon ||
		fabs(eulerRotation.z - prevEulerRotation.z) > epsilon;

	if (rotationChanged || scaleChanged || eulerChanged) {
		SetWorldMatrix();
		prevRotation = rotation;
		prevScale = scale;
		prevEulerRotation = eulerRotation;
	}
}
