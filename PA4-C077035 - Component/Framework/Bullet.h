#pragma once
#include "BaseBullet.h"


class Bullet : public BaseBullet
{
public:
	Bullet();
	Bullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	~Bullet();

	virtual bool Initialize(ID3D11Device*);
	virtual void Execute(XMFLOAT3);
	virtual bool Shutdown();

	virtual void BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation);
private:
};


