#include "ImageUI.h"

ImageUI::ImageUI()
{
}

ImageUI::ImageUI(XMFLOAT4 panelRect, XMFLOAT2 position, XMFLOAT3 rotation, const WCHAR* modelFilename, const WCHAR* textureFilename, int instanceCounter)
	: CanvasObject(panelRect, position, rotation, modelFilename, textureFilename, instanceCounter)
{

}

ImageUI::~ImageUI()
{
}

bool ImageUI::Initialize(ID3D11Device* device)
{
	result = false;

	isActive = true;
	timer = 0;

	m_panelModel = new PanelModelClass();
	if (!m_panelModel)
	{
		result = false;
	}

	result = m_panelModel->InitializeRender(device,  m_TextureFileName, m_InstanceCounter, transform.panelRect);
	if (!result)
	{
		return false;
	}

	return result;
}

void ImageUI::Execute(XMFLOAT3 camPos)
{
	// 이미지 UI의 위치
	/*
	XMVECTOR cameraToObject = XMVectorSet(transform.position.x - camPos.x, transform.position.y - camPos.y, transform.position.z - camPos.z, 0);

	cameraToObject = XMVector3Normalize(cameraToObject);

	double angle = atan2(XMVectorGetX(cameraToObject), XMVectorGetZ(cameraToObject));

	transform.eulerRotation.y = (float)angle;

	float angleX = -asin(XMVectorGetY(cameraToObject)); // asin을 사용하면 반전 방지 가능

	transform.eulerRotation.x = angleX;*/
}

bool ImageUI::Shutdown()
{
	m_panelModel->Shutdown();
	return true;
}
