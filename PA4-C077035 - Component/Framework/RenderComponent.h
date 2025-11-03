#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <d3d11.h>
#include <directxmath.h>

class RenderComponent
{
public:
	RenderComponent();
	~RenderComponent();

public:
	virtual bool InitializeRender(ID3D11Device*) = 0;
	virtual void Render(ID3D11DeviceContext*) = 0;
};

#endif // !RENDER_COMPONENT_H

