#pragma once
#include <directxmath.h>
#include <iostream>
#include <map>
#include <memory>
#include <algorithm>
#include "ShootType.h"
#include "BaseBullet.h"
#include "Bullet.h"
#include "ScopeBullet.h"
#include "ArtilleryBullet.h"

using namespace std;

class BulletManager : public Component
{
public:
	BulletManager();
	~BulletManager();

	bool Initialize(ID3D11Device*);
	void FixedExecute(XMFLOAT3);
	void Execute(XMFLOAT3);
	void LateExecute(XMFLOAT3);

	bool Shutdown();
	bool ShootBullet(XMVECTOR, XMFLOAT3, XMFLOAT3, XMFLOAT3 );

	vector<BaseBullet*>& GetAllActivatedBullets();
	void SetShootType(ShootType);
	void StartReload();
private:
	map<ShootType, shared_ptr<vector<BaseBullet*>>>m_BulletMapSet;
	map<ShootType, shared_ptr<vector<BaseBullet*>>>m_ReleaseBullet;

	vector<BaseBullet*> m_AllActivatedBullets;

	bool InitializeBulletMap();
	bool InitializeAllBullet(ID3D11Device*);
	void ReloadBullet();
	void ReleaseBullet(BaseBullet*);

	ShootType m_CurrentShootType;
	bool m_DoReload;
	float m_ReloadTimer;
};


