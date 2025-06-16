#include "BulletManager.h"
#include "ObjectClass.h"
#include "GameObject.h"

BulletManager::BulletManager()
{
	m_AllActivatedBullets.clear();
	m_ReloadTimer = 0;
	m_DoReload = false;
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

	m_BulletMapSet[ShootType::TPC] = m_BulletMapSet[ShootType::FPC];

	//ReleasePool
	m_ReleaseBullet[ShootType::FPC] = make_shared<vector<BaseBullet*>>();
	m_ReleaseBullet[ShootType::Scope] = make_shared<vector<BaseBullet*>>();
	m_ReleaseBullet[ShootType::Artillery] = make_shared<vector<BaseBullet*>>();

	m_ReleaseBullet[ShootType::TPC] = m_ReleaseBullet[ShootType::FPC];
	return result;
}

bool BulletManager::Initialize()
{
	bool result = true;
	m_AllActivatedBullets.clear();
	m_ReloadTimer = 0;
	m_DoReload = false;

	return result;
}

bool BulletManager::InitializeRef()
{
	bool result = true;
	m_CurrentShootType = (this->gameObject->GetComponent<Player>()->GetShootType());
	auto bullets = this->gameObject->Root().FindObjectsWithTag(Tag::NormalBullet);
	for (auto& b : bullets)
	{
		auto bb = b->GetComponentIncludingBase<BaseBullet>().get();
		if (bb != nullptr)
		{
			m_BulletMapSet[bb->GetBulletType()]->push_back(bb);
			continue;
		}
	}
	auto sBullets = this->gameObject->Root().FindObjectsWithTag(Tag::ScopeBullet);
	for (auto& sb : sBullets)
	{
		auto sbb = sb->GetComponentIncludingBase<BaseBullet>().get();
		if (sbb != nullptr)
		{
			m_BulletMapSet[sbb->GetBulletType()]->push_back(sbb);
			continue;
		}
	}
	auto aBullets = this->gameObject->Root().FindObjectsWithTag(Tag::ArtilleryBullet);
	for (auto& ab : aBullets)
	{
		auto abb = ab->GetComponentIncludingBase<BaseBullet>().get();
		if (abb != nullptr)
		{
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
	
	if (m_DoReload)
	{
		m_ReloadTimer -= TimerClass::GetInstance().DeltaTime;
		if (m_ReloadTimer < 0)
		{
			ReloadBullet();
			m_DoReload = false;
			m_ReloadTimer = 0;
		}
	}
}

bool BulletManager::ShootBullet(XMVECTOR CameraLookAt, XMFLOAT3 CameraPosition, XMFLOAT3 PlayerPosition, XMFLOAT3 PlayerEulerRotation  )
{
	// ������ �Ѿ��̸� ������ ����
	if (m_BulletMapSet[*m_CurrentShootType].get()->size() < 1)
	{
		StartReload();
		return false;
	}
	m_BulletMapSet[*m_CurrentShootType].get()->back()->BulletAwake(CameraLookAt, CameraPosition, PlayerPosition, PlayerEulerRotation);
	m_AllActivatedBullets.push_back((m_BulletMapSet[*m_CurrentShootType].get()->back()));
	m_BulletMapSet[*m_CurrentShootType].get()->pop_back();
	// ������ �Ѿ��̸� ������ ����
	if (m_BulletMapSet[*m_CurrentShootType].get()->size() < 1)
	{
		StartReload();
	}
	return true;
}

void BulletManager::ReloadBullet( )
{
	for (auto bullet = m_ReleaseBullet[*m_CurrentShootType].get()->begin(); bullet != m_ReleaseBullet[*m_CurrentShootType].get()->end(); bullet++)
	{
		m_BulletMapSet[*m_CurrentShootType].get()->push_back((*bullet));
	}
	m_ReleaseBullet[*m_CurrentShootType].get()->clear();
}

vector<BaseBullet*>& BulletManager::GetAllActivatedBullets()
{
	return m_AllActivatedBullets;
}

void BulletManager::ReleaseBullet(BaseBullet* Bullet)
{
	m_ReleaseBullet[Bullet->GetBulletType()].get()->push_back(Bullet);
}

void BulletManager::LateExecute()
{
	if (m_AllActivatedBullets.empty()) return;

	// ��Ȱ��ȭ�� �Ѿ��� �����ϱ� ���� remove_if ���
	auto newEnd = std::remove_if(m_AllActivatedBullets.begin(), m_AllActivatedBullets.end(),
		[this](BaseBullet* bullet)
		{
			if (!bullet->gameObject->active)
			{
				this->ReleaseBullet(bullet);  // releaseVector�� �߰�
				return true;  // ������ ��ҷ� ǥ��
			}
			return false;
		});

	// ���ŵ� ��Ҹ� ������ �����̳ʿ��� ����
	m_AllActivatedBullets.erase(newEnd, m_AllActivatedBullets.end());
}

void BulletManager::SetShootType(ShootType ShootType)
{
	if (*m_CurrentShootType == ShootType || (*m_CurrentShootType == ShootType::FPC && ShootType == ShootType::TPC) || (*m_CurrentShootType == ShootType::TPC && ShootType == ShootType::FPC)) return;
	*m_CurrentShootType = ShootType;
	m_ReloadTimer = 0;
	m_DoReload = false;
}

void BulletManager::StartReload()
{
	if (m_ReleaseBullet[*m_CurrentShootType].get()->size() > 0)
	{
		if (m_DoReload) return;
		m_DoReload = true;

		switch (*m_CurrentShootType)
		{
		case ShootType::Title:
			break;
		case ShootType::FPC:
			m_ReloadTimer = 500.0f;
			break;
		case ShootType::TPC:
			m_ReloadTimer = 500.0f;
			break;
		case ShootType::Scope:
			m_ReloadTimer = 2000.0f;
			break;
		case ShootType::Artillery:
			ReloadBullet();
			break;
		case ShootType::Num:
			break;
		}
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
	for (auto& b : m_AllActivatedBullets)
	{
		b->Shutdown();
	}

	m_BulletMapSet[ShootType::FPC].get()->clear();
	m_BulletMapSet[ShootType::Scope].get()->clear();
	m_BulletMapSet[ShootType::Artillery].get()->clear();
	return result;
}