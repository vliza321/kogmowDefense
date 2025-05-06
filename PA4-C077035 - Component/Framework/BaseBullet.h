#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "GameObject.h"
#include "Component.h"
#include "ShootType.h"

class BaseBullet : public Component
{
public:
	BaseBullet();
	BaseBullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale, const WCHAR*, const WCHAR*, int);
	~BaseBullet();

	virtual bool Initialize() = 0;
	virtual void Execute();
	virtual bool Shutdown() = 0;

	virtual void BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation) = 0;

	ShootType GetBulletType();
protected:
	ShootType m_BulletType;
};
