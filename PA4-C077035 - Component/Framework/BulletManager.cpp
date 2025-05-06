#include "BulletManager.h"
#include "ObjectClass.h"
#include "GameObject.h"

BulletManager::BulletManager()
{
	m_AllActivatedBullets.clear();
	m_ReloadTimer = 0;
	m_DoReload = false;
	*m_CurrentShootType = ShootType::FPC;
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

	/*
	//normal Bullet 생성
	m_BulletMapSet[ShootType::FPC].get()->push_back(
		new Bullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::FPC].get()->push_back(
		new Bullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::FPC].get()->push_back(
		new Bullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::FPC].get()->push_back(
		new Bullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::FPC].get()->push_back(
		new Bullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(07.0f, 07.0f, 7.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);


	//scope Bullet 생성
	m_BulletMapSet[ShootType::Scope].get()->push_back(
		new ScopeBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(08.0f, 08.0f, 8.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Scope].get()->push_back(
		new ScopeBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(08.0f, 08.0f, 8.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Scope].get()->push_back(
		new ScopeBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(08.0f, 08.0f, 8.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Scope].get()->push_back(
		new ScopeBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(08.0f, 08.0f, 8.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Scope].get()->push_back(
		new ScopeBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(08.0f, 08.0f, 8.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);

	//Artillery Bullet 생성
	m_BulletMapSet[ShootType::Artillery].get()->push_back(
		new ArtilleryBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(40.0f, 40.0f, 40.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Artillery].get()->push_back(
		new ArtilleryBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(40.0f, 40.0f, 40.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);
	m_BulletMapSet[ShootType::Artillery].get()->push_back(
		new ArtilleryBullet(
			XMFLOAT3(0, 0, -5), XMFLOAT3(0, 0, 0), XMFLOAT3(40.0f, 40.0f, 40.0f),
			L"./data/Bullet.obj", L"./data/1911.dds", 0)
	);

	for (auto& nb : *(m_BulletMapSet[ShootType::FPC].get()))
	{
		nb->Initialize();
	}
	for (auto& sb : *(m_BulletMapSet[ShootType::Scope].get()))
	{
		sb->Initialize();
	}
	for (auto& ab : *(m_BulletMapSet[ShootType::Artillery].get()))
	{
		ab->Initialize();
	}*/

	return result;
}

bool BulletManager::InitializeRef()
{
	bool result = true;
	m_CurrentShootType = &(this->gameObject->GetComponent<Player>()->GetShootType());
	return true;
}

bool BulletManager::InitializeSynchronization()
{
	return false;
}

bool BulletManager::PostInitialize()
{
	return false;
}

void BulletManager::FixedExecute()
{
	for (auto& nb : m_AllActivatedBullets)
	{
		nb->FixedExecute();
	}
}

void BulletManager::Execute()
{
	for (auto& nb : m_AllActivatedBullets)
	{
		nb->Execute();
	}
	
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
	// 마지막 총알이면 재장전 시작
	if (m_BulletMapSet[*m_CurrentShootType].get()->size() < 1)
	{
		StartReload();
		return false;
	}
	m_BulletMapSet[*m_CurrentShootType].get()->back()->BulletAwake(CameraLookAt, CameraPosition, PlayerPosition, PlayerEulerRotation);
	m_AllActivatedBullets.push_back((m_BulletMapSet[*m_CurrentShootType].get()->back()));
	m_BulletMapSet[*m_CurrentShootType].get()->pop_back();
	// 마지막 총알이면 재장전 시작
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

	// 비활성화된 총알을 제거하기 위해 remove_if 사용
	auto newEnd = std::remove_if(m_AllActivatedBullets.begin(), m_AllActivatedBullets.end(),
		[this](BaseBullet* bullet)
		{
			if (!bullet->active)
			{
				this->ReleaseBullet(bullet);  // releaseVector에 추가
				return true;  // 제거할 요소로 표시
			}
			return false;
		});

	// 제거된 요소를 실제로 컨테이너에서 삭제
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
			m_ReloadTimer = 2000.0f;
			break;
		case ShootType::TPC:
			m_ReloadTimer = 2000.0f;
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