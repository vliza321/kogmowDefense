#ifndef TRANSFORM_H
#define TRANSFORM_H

#pragma once
#include <d3d11.h>
#include <directxmath.h>
#include "Component.h"

using namespace DirectX;

class alignas(16) Transform : public Component
{
public:
	Transform();
	Transform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 scale, XMFLOAT3 eulerRot);
	~Transform();
public:
	XMFLOAT3 position;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
	XMFLOAT3 eulerRotation;
	XMFLOAT3 moveVector;
public:
	XMVECTOR DefaultForward;
	XMVECTOR DefaultRight;
	XMVECTOR DefaultUp;
public:
	void Translate(XMFLOAT3);
	void ApplyTranslate(XMFLOAT3);
};

#endif