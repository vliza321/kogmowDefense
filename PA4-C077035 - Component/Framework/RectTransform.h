#ifndef RECT_TRANSFORM_H
#define RECT_TRANSFORM_H

#pragma once
#include <d3d11.h>
#include <directxmath.h>
#include "Component.h"

using namespace DirectX;

class alignas(16) RectTransform : public Component
{
public:
	RectTransform();
	RectTransform(XMFLOAT4 Rect, XMFLOAT2 pos, XMFLOAT3 rot, XMFLOAT3 scale);
	~RectTransform();

public:
	XMFLOAT4 panelRect;
	XMFLOAT2 position;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
public:
	void Translate(XMFLOAT2);
};

#endif