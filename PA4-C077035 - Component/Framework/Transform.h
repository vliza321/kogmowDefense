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
public:	XMFLOAT3 position;
private:float pad1;          
public: XMFLOAT3 rotation;
private:float pad2;
public: XMFLOAT3 scale;
private:float pad3;
public:	XMFLOAT3 eulerRotation;
private:float pad4;
public:	XMFLOAT3 moveVector;
private:float pad5;
public:	XMMATRIX LocalMatrix;
public:	XMMATRIX WorldMatrix;
private:
	XMFLOAT3 prevPosition;
	float pad9;
	XMFLOAT3 prevRotation;
	float pad6;
	XMFLOAT3 prevEulerRotation;
	float pad7;
	XMFLOAT3 prevScale;
	float pad8;
public:
	XMVECTOR DefaultForward;
	XMVECTOR DefaultRight;
	XMVECTOR DefaultUp;
public:
	void Translate(XMFLOAT3);
	void ApplyTranslate(XMFLOAT3);
private:
	void SetLocalMatrix();
	void SetWorldMatrix(XMMATRIX parentWorldMatrix);
public:
	virtual void PostExecute() override;
	virtual bool PostInitialize() override;
};

#endif