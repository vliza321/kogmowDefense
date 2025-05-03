#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "modelclass.h"
#include "CanvasObject.h"

using namespace std;
using namespace DirectX;

class ImageUI : public CanvasObject
{
public:
	ImageUI();
	ImageUI(XMFLOAT4 panelRect, XMFLOAT2 position, XMFLOAT3 rotation, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter);
	~ImageUI();

	virtual bool Initialize(ID3D11Device*);
	virtual void Execute(XMFLOAT3);
	virtual bool Shutdown();

	bool result;
};

