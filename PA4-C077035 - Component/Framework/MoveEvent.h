#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#pragma once
#include "Transform.h"

struct MoveEvent
{
	Transform* transform;
	XMFLOAT3 MoveVector;
};

#endif