#ifndef _ASYNC_D3DCLASS_H_
#define _ASYNC_D3DCLASS_H_

/////////////
// LINKING //
/////////////
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

//////////////
// INCLUDES //
//////////////
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <directxmath.h>

#include "AlignedAllocationPolicy.h"

using namespace DirectX;

#pragma once
class AsyncD3DClass
{
public:
	AsyncD3DClass();
	AsyncD3DClass(const AsyncD3DClass&);
	~AsyncD3DClass();

	bool Initialize(int, int, bool, HWND, bool, float, float);
	void Shutdown();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
private:
	bool m_vsync_enabled;
	int m_videoCardMemory;
	char m_videoCardDescription[128];

	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;

	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
};

#endif