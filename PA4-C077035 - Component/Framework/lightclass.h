////////////////////////////////////////////////////////////////////////////////
// Filename: lightclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _LIGHTCLASS_H_
#define _LIGHTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <directxmath.h>
#include "Component.h"

using namespace DirectX;

////////////////////////////////////////////////////////////////////////////////
// Class name: LightClass
////////////////////////////////////////////////////////////////////////////////
class LightClass : public Component
{
public:
	LightClass();
	/// 순서대로
	/// 1. 방향
	/// 2. 앰비언트
	/// 3. 디퓨즈
	/// 4. 스페큘라
	/// 5. 포지션
	/// 6. 스페큘라 파워

	LightClass(XMFLOAT3,XMFLOAT4,XMFLOAT4,XMFLOAT4,XMFLOAT4,float);
	LightClass(const LightClass&);
	~LightClass();

	virtual bool InitializeRef() override;
public:
	bool isSpecularPower;
	bool isDiffuseColor;
	bool isAmbientColor;

	int baseSpecularPower;
	XMFLOAT4 baseDiffuseColor;
	XMFLOAT4 baseAmbientColor;
	XMFLOAT4 baseSpecularColor;

	void TurnOnOffSpecularPower();
	void TurnOnOffDiffuseColor();
	void TurnOnOffAmbientColor();

	float distance;
	
public:
	XMFLOAT3 direction;
	XMFLOAT4 ambientColor;
	XMFLOAT4 diffuseColor;
	XMFLOAT4 specularColor;
	XMFLOAT4 position;
	float specularPower;
};

#endif