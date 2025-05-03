#include "RectTransform.h"

RectTransform::RectTransform()
{
	panelRect = XMFLOAT4(0, 0, 0, 0);
	position = XMFLOAT2(0, 0);
	rotation = XMFLOAT3(0, 0, 0);
	scale = XMFLOAT3(0, 0, 0);
}

RectTransform::RectTransform(XMFLOAT4 rect, XMFLOAT2 pos, XMFLOAT3 rot, XMFLOAT3 scale)
	: panelRect(rect), position(pos), rotation(rot), scale(scale)
{

}

RectTransform::~RectTransform()
{
}


void RectTransform::Translate(XMFLOAT2 t)
{

}
