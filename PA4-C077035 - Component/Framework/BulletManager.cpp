#include "BulletManager.h"
#include "ObjectClass.h"
#include "GameObject.h"

BulletManager::BulletManager()
{
	m_allActivatedBullets.clear();
	m_reloadTimer1 = 0;
	m_doReload1 = false;
	m_reloadTimer2 = 0;
	m_doReload2 = false;
	m_reloadTimer3 = 0;
	m_doReload3 = false;
}

BulletManager::~BulletManager()
{

}


bool BulletManager::InitializeSet()
{
	bool result = true;
	m_BulletMapSet[ShootType::FPC] = make_shared<vector<BaseBullet*>>();
	m_BulletMapSet[ShootType::Scope] = make_shared<vector<BaseBullet*>>();
	m_BulletMapSet[ShootType::Artillery] = make_shared<vector<BaseBullet*>>();

	//ReleasePool
	m_ReleaseBullet[ShootType::FPC] = make_shared<vector<BaseBullet*>>();
	m_ReleaseBullet[ShootType::Scope] = make_shared<vector<BaseBullet*>>();
	m_ReleaseBullet[ShootType::Artillery] = make_shared<vector<BaseBullet*>>();
	return result;
}

bool BulletManager::Initialize()
{
	bool result = true;
	m_allActivatedBullets.clear();
	m_reloadTimer1 = 0;
	m_doReload1 = false;
	m_reloadTimer2 = 0;
	m_doReload2 = false;
	m_reloadTimer3 = 0;
	m_doReload3 = false;
	return result;
}

bool BulletManager::InitializeRef()
{
	m_BulletMapSet[ShootType::TPC] = m_BulletMapSet[ShootType::FPC];
	m_ReleaseBullet[ShootType::TPC] = m_ReleaseBullet[ShootType::FPC];

	bool result = true;
	m_CurrentShootType = (this->gameObject->GetComponent<Player>()->GetShootType());
	auto bullets = FindObjectsWithTag(Tag::NormalBullet);
	for (auto& b : bullets)
	{
		auto bb = b->GetComponentIncludingBase<BaseBullet>().get();
		if (bb != nullptr)
		{
			bb->gameObject->active = false;
			m_BulletMapSet[bb->GetBulletType()]->push_back(bb);
			continue;
		}
	}
	auto sBullets = FindObjectsWithTag(Tag::ScopeBullet);
	for (auto& sb : sBullets)
	{
		auto sbb = sb->GetComponentIncludingBase<BaseBullet>().get();
		if (sbb != nullptr)
		{
			sbb->gameObject->active = false;
			m_BulletMapSet[sbb->GetBulletType()]->push_back(sbb);
			continue;
		}
	}
	auto aBullets = FindObjectsWithTag(Tag::ArtilleryBullet);
	for (auto& ab : aBullets)
	{
		auto abb = ab->GetComponentIncludingBase<BaseBullet>().get();
		if (abb != nullptr)
		{
			abb->gameObject->active = false;
			m_BulletMapSet[abb->GetBulletType()]->push_back(abb);
			continue;
		}
	}
	return true;
}

bool BulletManager::InitializeSynchronization()
{
	return true;
}

bool BulletManager::PostInitialize()
{
	return true;
}

void BulletManager::FixedExecute()
{
}

void BulletManager::Execute()
{
	
	if (m_doReload1)
	{
		m_reloadTimer1 -= TimerClass::GetInstance().DeltaTime;
		if (m_reloadTimer1 < 0)
		{
			ReloadBullet(ShootType::FPC);
			m_doReload1 = false;
			m_reloadTimer1 = 0;
		}
	}
	if (m_doReload2)
	{
		m_reloadTimer2 -= TimerClass::GetInstance().DeltaTime;
		if (m_reloadTimer2 < 0)
		{
			ReloadBullet(ShootType::Scope);
			m_doReload2 = false;
			m_reloadTimer2 = 0;
		}
	}
	if (m_doReload3)
	{
		m_reloadTimer3 -= TimerClass::GetInstance().DeltaTime;
		if (m_reloadTimer3 < 0)
		{
			ReloadBullet(ShootType::Artillery);
			m_doReload3 = false;
			m_reloadTimer3 = 0;
		}
	}

}

bool BulletManager::ShootBullet(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation  )
{
	// 마지막 총알이면 재장전 시작
	if (m_BulletMapSet[*m_CurrentShootType].get()->size() < 1)
	{
		StartReload();
		return false;
	}
	m_BulletMapSet[*m_CurrentShootType].get()->back()->BulletAwake(CameraLookAt, CameraPosition, PlayerPosition, PlayerEulerRotation);
	m_allActivatedBullets.push_back((m_BulletMapSet[*m_CurrentShootType].get()->back()));
	m_BulletMapSet[*m_CurrentShootType].get()->pop_back();
	// 마지막 총알이면 재장전 시작
	if (m_BulletMapSet[*m_CurrentShootType].get()->size() < 1)
	{
		StartReload();
	}
	return true;
}

void BulletManager::ReloadBullet(ShootType shoottype)
{
	for (auto bullet = m_ReleaseBullet[shoottype].get()->begin(); bullet != m_ReleaseBullet[shoottype].get()->end(); bullet++)
	{
		m_BulletMapSet[shoottype].get()->push_back((*bullet));
	}
	m_ReleaseBullet[shoottype].get()->clear();
}

vector<BaseBullet*>& BulletManager::GetAllActivatedBullets()
{
	return m_allActivatedBullets;
}

void BulletManager::ReleaseBullet(BaseBullet* Bullet)
{
	m_ReleaseBullet[Bullet->GetBulletType()].get()->push_back(Bullet);
}

void BulletManager::LateExecute()
{
	if (m_allActivatedBullets.empty()) return;

	auto boundary = std::stable_partition(
		m_allActivatedBullets.begin(),
		m_allActivatedBullets.end(),
		[](BaseBullet* bullet)
		{
			return bullet->gameObject->active;
		}
	);

	for (auto it = boundary; it != m_allActivatedBullets.end(); ++it)
	{
		BaseBullet* bullet = *it;
		ReleaseBullet(bullet);
	}

	m_allActivatedBullets.erase(boundary, m_allActivatedBullets.end());
}

void BulletManager::SetShootType(ShootType ShootType)
{
	if (*m_CurrentShootType == ShootType || (*m_CurrentShootType == ShootType::FPC && ShootType == ShootType::TPC) || (*m_CurrentShootType == ShootType::TPC && ShootType == ShootType::FPC)) return;
	*m_CurrentShootType = ShootType;
	m_reloadTimer1 = 0;
	m_doReload1 = false;
}

void BulletManager::StartReload()
{
	switch (*m_CurrentShootType)
	{
	case ShootType::Title:
		break;
	case ShootType::FPC:
		m_doReload1 = true;
		m_reloadTimer1 = 1500.0f;
		break;
	case ShootType::TPC:
		m_doReload1 = true;
		m_reloadTimer1 = 1500.0f;
		break;
	case ShootType::Scope:
		m_doReload2 = true;
		m_reloadTimer2 = 3000.0f;
		break;
	case ShootType::Artillery:
		m_doReload3 = true;
		m_reloadTimer3 = 4000.0f;
		break;
	case ShootType::Num:
		break;
	}
}

bool BulletManager::Shutdown()
{
	bool result = true;
	for (auto& nb : *(m_BulletMapSet[ShootType::FPC].get()))
	{
		nb->Shutdown();
	}
	for (auto& sb : *(m_BulletMapSet[ShootType::Scope].get()))
	{
		sb->Shutdown();
	}
	for (auto& ab : *(m_BulletMapSet[ShootType::Artillery].get()))
	{
		ab->Shutdown();
	}
	for (auto& b : m_allActivatedBullets)
	{
		b->Shutdown();
	}

	m_BulletMapSet[ShootType::FPC].get()->clear();
	m_BulletMapSet[ShootType::Scope].get()->clear();
	m_BulletMapSet[ShootType::Artillery].get()->clear();
	return result;
}