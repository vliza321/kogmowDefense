#include "Canvas.h"
#include "CanvasRenderer.h"


Canvas::Canvas()
{
	m_shootUIMap.clear();

	m_title = 0;
}

Canvas::~Canvas()
{

}

bool Canvas::InitializeSet()
{
	m_title = new CanvasRenderer(L"./data/title.dds", XMFLOAT4(800, -450, -800, 450));

	m_baseScope = new CanvasRenderer(L"./data/TempNormalLineOfSight.dds", XMFLOAT4(800, -450, -800, 450));

	m_shootUIMap[ShootType::Debug] = nullptr;

	m_shootUIMap[ShootType::TPC] = nullptr;
	m_shootUIMap[ShootType::FPC] = nullptr;
	m_shootUIMap[ShootType::Scope] = new CanvasRenderer(L"./data/TempScopeLineOfSight.dds", XMFLOAT4(800, -450, -800, 450));
	m_shootUIMap[ShootType::Artillery] = new CanvasRenderer(L"./data/TempArtilleryLineOfSight.dds", XMFLOAT4(800, -450, -800, 450));

	m_title->active = false;
	m_baseScope->active = true;

	m_title->gameObject = this->gameObject;
	m_baseScope->gameObject = this->gameObject;

	m_title->InitializeSet();
	m_baseScope->InitializeSet();

	for (auto& ui : m_shootUIMap)
	{
		if (ui.second != nullptr)
		{
			ui.second->active = false;
			ui.second->gameObject = this->gameObject;
			ui.second->InitializeSet();
		}
	}

	return true;
}

bool Canvas::InitializeRef()
{
	for (auto& ui : m_shootUIMap)
	{
		if (ui.second != nullptr) ui.second->InitializeRef();
	}

	m_title->InitializeRef();
	m_baseScope->InitializeRef();
	return true;
}

bool Canvas::Shutdown()
{
	if (m_title)
	{
		delete m_title;
		m_title = 0;
	}
	if (m_baseScope)
	{
		delete m_baseScope;
		m_baseScope = 0;
	}
	m_shootUIMap.clear();
	return true;
}

void Canvas::FixedExecute()
{
}

void Canvas::Execute()
{
}

void Canvas::LateExecute()
{
}

void Canvas::PostExecute()
{
}

void Canvas::SetType(ShootType ChangeType)
{
	if (m_shootUIMap[m_currentUIType] != nullptr)
	{
		m_shootUIMap[m_currentUIType]->active = false;
	}
	m_currentUIType = ChangeType;
	if (m_shootUIMap[m_currentUIType] != nullptr)
	{
		m_shootUIMap[m_currentUIType]->active = true;
	}
}
