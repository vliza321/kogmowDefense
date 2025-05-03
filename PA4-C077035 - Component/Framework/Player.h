#pragma once
#include <vector>
#include <d3d11.h>
#include <directxmath.h>

#include "Component.h"
#include "inputclass.h"
#include "Transform.h"
#include "CameraManager.h"

using namespace std;
using namespace DirectX;

class Player : public Component
{
public:
	Player();
	~Player();

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

private:
	std::weak_ptr<Transform> transform;
	int m_moveLeftRight;
	int m_moveBackForward;
	float speed;
	std::weak_ptr<CameraManager> cameraManager;
	/*
	virtual void SetRollPitchYaw(float, float, float);
	
	void SetArtilleryMod();
	void ResetArtilleryMod();
	void Shoot();
	
	bool SetCurrentShootType(ShootType);
	ShootType GetCurrentShootType();

	bool GetCanFire();
	*/
private:
	/*
	void ReboundCul();
	void ChangePovCul();
	void AutomaticFeeding();*/
private:
	/*
	ShootType m_CurrentShootType;
	float ArtilleryTemt;

	float PoVTimer;
	bool canChangePov;

	float ReboundTimer;
	bool isRebound;
	int ReBoundConst;

	float FeedingTimer;
	bool canFire;*/
};



