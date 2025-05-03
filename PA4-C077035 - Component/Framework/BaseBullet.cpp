#include "BaseBullet.h"

BaseBullet::BaseBullet()
	:GameObject()
{

}

BaseBullet::BaseBullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale,
	const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: GameObject(position, rotation, scale, modelFilename, textureFilename, instanceCounter)

{
}

BaseBullet::~BaseBullet()
{

}

void BaseBullet::Execute(XMFLOAT3 PlayerPos)
{

}


ShootType BaseBullet::GetBulletType()
{
	return m_BulletType;
}

