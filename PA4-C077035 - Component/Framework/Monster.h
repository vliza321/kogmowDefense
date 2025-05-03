#pragma once
#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "modelclass.h"
#include "GameObject.h"

using namespace std;
using namespace DirectX;

class Monster : public Component
{
public:
	Monster();
	Monster(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	//GameObject(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, ModelClass* model);
	~Monster();

	bool Initialize() override;
	void Execute() override;
	bool Shutdown() override;
};


