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

class Canvas;

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
private:
	std::weak_ptr<CameraManager> cameraManager;
	std::weak_ptr<Canvas> UICanvas;
	ShootType m_currentShootType;
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
	void ChangePovCul();
	void SetPov(ShootType);
	void SetArtilleryMod(Transform&);
	//void AutomaticFeeding();
private:
	float const POVMAXTIMER = 300.0f;
	float const ARTILLERYTIMER = 5000.0f;
private:
	float PoVTimer;
	bool canChangePov;

	float ArtilleryTemt;

	/*
	float ReboundTimer;
	bool isRebound;
	int ReBoundConst;

	float FeedingTimer;
	bool canFire;*/

public:
	ShootType& GetShootType();
};



