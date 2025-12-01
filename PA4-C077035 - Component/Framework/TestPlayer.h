#pragma once

#include <vector>
#include <d3d11.h>
#include <directxmath.h>

#include "Component.h"
#include "inputclass.h"
#include "Transform.h"

class TestPlayer : public Component
{
public:
	TestPlayer();
	~TestPlayer();

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
};

