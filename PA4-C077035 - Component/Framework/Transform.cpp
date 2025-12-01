#include "Transform.h"
#include "Collision.h"
#include "MoveEvent.h"

#include "GameScene.h"
#define epsilon 0.0001f

Transform::Transform()
{
	position = XMFLOAT3(0,0,0);
	rotation = XMFLOAT3(0, 0, 0);
	scale = XMFLOAT3(1, 1, 1);
	eulerRotation = XMFLOAT3(0, 0, 0);

	prevPosition = XMFLOAT3(0, 0, 0);
	prevRotation = XMFLOAT3(0, 0, 0);
	prevScale = XMFLOAT3(1, 1, 1);
	prevEulerRotation = XMFLOAT3(0, 0, 0);

	WorldMatrix = XMMatrixIdentity();
	LocalMatrix = XMMatrixIdentity();

	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

	pad1 = 0;
	pad2 = 0;
	pad3 = 0;
	pad4 = 0;
	pad5 = 0;
	pad6 = 0;
	pad7 = 0;
	pad8 = 0;
	pad9 = 0;
}

Transform::Transform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 scale, XMFLOAT3 eulerRot)
	:position(pos), rotation(rot), scale(scale), eulerRotation(eulerRot), prevRotation(rot), prevEulerRotation(eulerRot), prevScale(scale), prevPosition(pos)
{
	moveVector = XMFLOAT3(0, 0, 0);
	DefaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	DefaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DefaultUp = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

	WorldMatrix = XMMatrixIdentity();
	LocalMatrix = XMMatrixIdentity();

	pad1 = 0;
	pad2 = 0;
	pad3 = 0;
	pad4 = 0;
	pad5 = 0;
	pad6 = 0;
	pad7 = 0;
	pad8 = 0;
	pad9 = 0;
}

Transform::~Transform()
{
}

bool Transform::PostInitialize()
{
	SetLocalMatrix();
	return true;
}

void Transform::Translate(XMFLOAT3 t)
{
	MoveEvent* moveEvent = new MoveEvent;
	moveEvent->transform = this;
	moveEvent->MoveVector = t;
	gameObject->root->GetCollision()->AddEvent(moveEvent);
}

void Transform::ApplyTranslate(XMFLOAT3 t)
{
	position.x += t.x;
	position.y += t.y;
	position.z += t.z;

	SetLocalMatrix();
}

void Transform::SetLocalMatrix()
{
	LocalMatrix = XMMatrixScaling(scale.x, scale.y, scale.z)
		* XMMatrixRotationX(rotation.x)
		* XMMatrixRotationY(rotation.y)
		* XMMatrixRotationZ(rotation.z)
		* XMMatrixRotationRollPitchYaw(eulerRotation.x, eulerRotation.y, eulerRotation.z)
		* XMMatrixTranslation(position.x, position.y, position.z);

	prevPosition = position;
	prevRotation = rotation;
	prevScale = scale;
	prevEulerRotation = eulerRotation;

	auto parent = this->gameObject->parent;
	while (parent != nullptr)
	{
		auto pt = parent->GetComponent<Transform>();
		if (pt != nullptr)
		{
			SetWorldMatrix(pt->WorldMatrix);
			return;
		}
		parent = parent->parent;
	}
	SetWorldMatrix(XMMatrixIdentity());
}

void Transform::SetWorldMatrix(XMMATRIX parentWorldMatrix)
{
	WorldMatrix = LocalMatrix * parentWorldMatrix;
	vector<shared_ptr<Transform>> allTransform = this->gameObject->GetComponentsInChild<Transform>(false);
	for (auto& at : allTransform)
	{
		at->SetWorldMatrix(WorldMatrix);
	}
}

void Transform::PostExecute()
{
	bool positionChanged = 
		fabs(position.x - prevPosition.x) > epsilon ||
		fabs(position.y - prevPosition.y) > epsilon ||
		fabs(position.z - prevPosition.z) > epsilon;

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

	if (positionChanged || rotationChanged || scaleChanged || eulerChanged) {
		SetLocalMatrix();
		prevPosition = position;
		prevRotation = rotation;
		prevScale = scale;
		prevEulerRotation = eulerRotation;
	}
}
