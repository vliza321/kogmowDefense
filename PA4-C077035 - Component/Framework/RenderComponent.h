#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <d3d11.h>
#include <directxmath.h>
#include "Component.h"

#pragma once
class RenderComponent {
public:
	virtual bool InitializeRender(ID3D11Device*) = 0;
};

#endif // !RENDER_COMPONENT_H

