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
	LightClass(XMFLOAT3,XMFLOAT4,XMFLOAT4,XMFLOAT4,XMFLOAT4,float);
	LightClass(const LightClass&);
	~LightClass();

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