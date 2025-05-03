#pragma once
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <d3d11.h>
#include <directxmath.h>
#include "CanvasObject.h"
#include "ImageUI.h"
#include "textureshaderclass.h"
#include "d3dclass.h"
#include "ShootType.h"

using namespace std;

class Canvas
{
public:
	
	Canvas();
	~Canvas();

	bool Initialize(HWND, ID3D11Device*);
	bool UIRender(TextureShaderClass*, D3DClass*, ID3D11DeviceContext*, XMFLOAT3, XMMATRIX, XMMATRIX, XMMATRIX, XMMATRIX, int, ShootType);
	void Shutdown();
	void SetScene(int);

	void Execute(XMFLOAT3, int);
	void LateExecute();
private:
	vector<CanvasObject*> m_UI;
	ImageUI* m_Title;
	ImageUI* m_NormalSightUI;
	ImageUI* m_ScopeSightUI;
	ImageUI* m_ArtillerySightUI;

	map<ShootType, unique_ptr<ImageUI*>>m_ShootUISet;
};

