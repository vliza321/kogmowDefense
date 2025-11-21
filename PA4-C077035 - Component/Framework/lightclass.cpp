////////////////////////////////////////////////////////////////////////////////
// Filename: lightclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "lightclass.h"
#include "LightManager.h"
#include "ObjectClass.h"

LightClass::LightClass()
{
	isSpecularPower = true;
	isDiffuseColor = true;
	isAmbientColor = true;
	distance = 0;
}
LightClass::LightClass(XMFLOAT3 Direction, XMFLOAT4 AmbientColor, XMFLOAT4 DiffuseColor, XMFLOAT4 SpecularColor, XMFLOAT4 Position, float SpecularPower)
{
	direction = Direction;
	ambientColor = AmbientColor;
	diffuseColor = DiffuseColor;
	specularColor = SpecularColor;
	position = Position;
	specularPower = SpecularPower;
	distance = 0;


	isSpecularPower = true;
	isDiffuseColor = true;
	isAmbientColor = true;

	baseDiffuseColor = DiffuseColor;
	baseAmbientColor = AmbientColor;
	baseSpecularColor = SpecularColor;
	baseSpecularPower = SpecularPower;
}

LightClass::LightClass(const LightClass& other)
{
}


LightClass::~LightClass()
{
}

bool LightClass::InitializeRef()
{
	if (this->gameObject->tag == Tag::DirectionalLight)
	{
		Find("LightManager")->GetComponent<LightManager>()->SetDirectionalLight(this);
	}
	else
	{
		Find("LightManager")->GetComponent<LightManager>()->AddLight(this);
	}
	return true;
}

void LightClass::TurnOnOffAmbientColor()
{
	if (isAmbientColor == true)
	{
		isAmbientColor = false;
		ambientColor = XMFLOAT4(0, 0, 0, 1);
	}
	else
	{
		isAmbientColor = true;
		ambientColor = baseAmbientColor;
	}
	return;
}

void LightClass::TurnOnOffDiffuseColor()
{
	if (isDiffuseColor == true)
	{
		isDiffuseColor = false;
		diffuseColor = XMFLOAT4(0, 0, 0, 1);
	}
	else
	{
		isDiffuseColor = true;
		diffuseColor = baseDiffuseColor;
	}
	return;
}

void LightClass::TurnOnOffSpecularPower()
{
	if (isSpecularPower == true)
	{
		isSpecularPower = false;
		specularPower = 0.00f;
		specularColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 0);
	}
	else
	{
		isSpecularPower = true;
		specularPower = baseSpecularPower;
		specularColor = baseSpecularColor;
	}
	return;
}
