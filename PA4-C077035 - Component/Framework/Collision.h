#ifndef COLLISION_H
#define COLLISION_H

#include <memory>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include "SphereCollider.h"
#include "RayCollider.h"
#include "BoxCollider.h"
#include "ColliderType.h"
#include "MoveEvent.h"

using namespace std;

class Collision
{
public:
	Collision();
	~Collision();
public:
	void AddCollider(Collider*);
	bool RemoveCollider(Collider*);
	void AddEvent(MoveEvent*);
	void ProcessCollision();
	void Shutdown();
private:
	vector<SphereCollider*> m_sphereCollider;
	vector<RayCollider*> m_rayCollider;
	vector<BoxCollider*> m_boxCollider;

private:
	queue<MoveEvent*> m_eventQueue;
	set<Collider*> m_trackingCollider;

	Collider* CheckCollision(SphereCollider*, MoveEvent*);
	Collider* CheckCollision(RayCollider*, MoveEvent*);
};

#endif