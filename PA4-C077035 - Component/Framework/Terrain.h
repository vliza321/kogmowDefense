#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "modelclass.h"
#include "GameObject.h"

using namespace std;
using namespace DirectX;

class Terrain : public Component
{
public:
	Terrain();
	Terrain(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	//GameObject(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, ModelClass* model);
	~Terrain();

	virtual bool Initialize(ID3D11Device*);
	virtual bool Shutdown();
};

