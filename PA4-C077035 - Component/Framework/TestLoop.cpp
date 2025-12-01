#include "TestLoop.h"

TestLoop::TestLoop()
{
}

TestLoop::~TestLoop()
{
}

bool TestLoop::InitializeRef()
{
	transform = this->gameObject->GetComponent<Transform>();
	auto tf = transform.lock();
	if (tf == nullptr)
	{
		auto newTransform = std::make_shared<Transform>(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.04f, 0.04f, 0.04f), XMFLOAT3(0, 0, 0));
		this->gameObject->AddComponent(newTransform);
		transform = newTransform;
	}
	return true;
}

void TestLoop::Execute()
{
	auto tf = transform.lock();
	tf->eulerRotation.y += DeltaTime() * 0.001f;
}
