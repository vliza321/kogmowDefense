#pragma once
#include "BaseBullet.h"

class ScopeBullet : public BaseBullet
{
public:
	ScopeBullet();
	ScopeBullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	~ScopeBullet();

	virtual bool Initialize(ID3D11Device*);
	virtual void Execute(XMFLOAT3);
	virtual bool Shutdown();

	virtual void BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation);
private:
};

