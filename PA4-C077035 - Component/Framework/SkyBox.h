#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "modelclass.h"
#include "GameObject.h"

using namespace std;
using namespace DirectX;

class SkyBox : public Component
{
public:
	SkyBox();
	SkyBox(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	~SkyBox();

	virtual bool Initialize(ID3D11Device*);
	virtual void Execute(XMFLOAT3);
	virtual bool Shutdown();
};

