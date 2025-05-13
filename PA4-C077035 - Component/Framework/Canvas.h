#ifndef Canvas_H
#define Canvas_H

#include <unordered_map>
#include <memory>
#include <algorithm>
#include <d3d11.h>
#include <directxmath.h>

#include "Component.h"

#include "d3dclass.h"
#include "ShootType.h"

class CanvasRenderer;

using namespace std;

class Canvas : public Component
{
public:
	
	Canvas();
	~Canvas();

	virtual bool InitializeSet() override;
	virtual bool InitializeRef() override;
	virtual bool Shutdown() override;

	virtual void FixedExecute() override;
	virtual void Execute() override;
	virtual void LateExecute() override;
	virtual void PostExecute() override;
public:
	void SetType(ShootType);
private:
	CanvasRenderer* m_title;
	CanvasRenderer* m_baseScope;
	ShootType m_currentUIType;

	unordered_map<ShootType, CanvasRenderer*>m_shootUIMap;
};

#endif