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

	virtual bool InitializeSet() override;
	virtual bool Initialize() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual bool PostInitialize() override;

	virtual void FixedExecute() override;
	virtual void Execute() override;
	virtual void LateExecute() override;

	virtual bool Shutdown() override;

public:
	bool ShootBullet(XMVECTOR, XMFLOAT3, XMFLOAT3, XMFLOAT3 );

private:
	ShootType* m_CurrentShootType;
private:
	map<ShootType, shared_ptr<vector<BaseBullet*>>>m_BulletMapSet;
	map<ShootType, shared_ptr<vector<BaseBullet*>>>m_ReleaseBullet;

	vector<BaseBullet*> m_AllActivatedBullets;

	void ReloadBullet();
	void ReleaseBullet(BaseBullet*);
	
	vector<BaseBullet*>& GetAllActivatedBullets();
	void SetShootType(ShootType);
	void StartReload();

private:
	bool m_DoReload;
	float m_ReloadTimer;
};


