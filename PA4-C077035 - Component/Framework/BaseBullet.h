#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>
#include "GameObject.h"
#include "Component.h"
#include "ShootType.h"
#include "Transform.h"

class BaseBullet : public Component
{
public:
	BaseBullet(ShootType);
	~BaseBullet();

	virtual bool InitializeSet() override;
	virtual bool Initialize() override;
	virtual bool InitializeRef() override;
	virtual bool InitializeSynchronization() override;
	virtual bool PostInitialize() override;
	virtual void FixedExecute() override;
	virtual void Execute() override;
	virtual void LateExecute() override;
	virtual void PostExecute() override;
	virtual bool Shutdown() override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnCollisionEnter(Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;
	virtual void OnCollisionExit(Collider* other) override;
public:
	ShootType GetBulletType();
	virtual void BulletAwake(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation);
	std::weak_ptr<Transform> transform;
	std::weak_ptr<Transform> targetTransform;
public:
	float timer;
	float speed;
protected:
	ShootType m_bulletType;
	XMVECTOR m_moveVector;
	XMMATRIX m_rotationMatrix;
	XMFLOAT3 temt;
};
