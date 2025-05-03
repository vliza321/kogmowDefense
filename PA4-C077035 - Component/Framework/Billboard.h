#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "modelclass.h"
#include "GameObject.h"

using namespace std;
using namespace DirectX;

class Billboard : public GameObject
{
public:
	Billboard();
	Billboard(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	~Billboard();

	virtual bool Initialize(ID3D11Device*);
	virtual void Execute(XMFLOAT3);
	virtual bool Shutdown();
};



