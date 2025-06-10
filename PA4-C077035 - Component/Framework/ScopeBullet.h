#pragma once
#include "BaseBullet.h"

class ScopeBullet : public BaseBullet
{
public:
	ScopeBullet();
	~ScopeBullet();

	virtual bool InitializeSet() override;
	virtual bool Initialize() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual bool PostInitialize() override;

	virtual void FixedExecute() override;
	virtual void Execute() override;
	virtual void LateExecute() override;
	virtual void PostExecute() override;

	virtual void OnCollisionEnter(Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;
	virtual void OnCollisionExit(Collider* other) override;
public:
	virtual void BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation) override;
	virtual bool Shutdown() override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
private:
};

