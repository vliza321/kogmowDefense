#include "BaseBullet.h"

BaseBullet::BaseBullet()
	:Component()
{

}

BaseBullet::BaseBullet(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale,
	const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: Component()
{

}

BaseBullet::~BaseBullet()
{

}

void BaseBullet::Execute()
{

}


ShootType BaseBullet::GetBulletType()
{
	return m_BulletType;
}

