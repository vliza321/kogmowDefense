#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "timerclass.h"
#include "PanelModelClass.h"
#include "RectTransform.h"

using namespace std;
using namespace DirectX;

class CanvasObject
{
public:
	RectTransform transform;

	struct alignas(16) InstanceType
	{
		XMFLOAT3 position;
		float padding;
	};

	CanvasObject();
	CanvasObject(XMFLOAT4 panelRect, XMFLOAT2 position, XMFLOAT3 rotation , const WCHAR*, const WCHAR*, int);
	~CanvasObject();

	virtual bool Initialize(ID3D11Device*) = 0;
	virtual void Execute(XMFLOAT3);
	virtual void LateExecute(XMFLOAT3);
	virtual bool Shutdown() = 0;

	void SetActive(bool);
	bool GetActive();

	void Render(ID3D11DeviceContext*);

	void Translate(XMFLOAT3);

	ID3D11ShaderResourceView* GetModelTexture();

	PanelModelClass* GetModelData();
	int GetModelIndexCount();
	int GetModelVertexCount();
	int GetModelInstanceCount();

protected:
	bool isActive;

	PanelModelClass* m_panelModel;

	const WCHAR* m_modelFileName;
	const WCHAR* m_TextureFileName;
	int m_InstanceCounter;

	float timer;
	XMFLOAT3 temt;

	float GetDeltaTime() const {
		return TimerClass::GetInstance().DeltaTime;
	}
};