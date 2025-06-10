#include "Collision.h"
#include "GameObject.h"
#include "Transform.h"
#include <DirectXMath.h>

Collision::Collision()
{
	m_sphereCollider.clear();
	m_rayCollider.clear();
	m_boxCollider.clear();
}

Collision::~Collision()
{
	m_sphereCollider.clear();
	m_rayCollider.clear();
	m_boxCollider.clear();
}

Collider* Collision::CheckCollision(SphereCollider* moveEventCollider, MoveEvent* moveEvent)
{
	auto MoveEventTransform = moveEvent->transform;
	if (!MoveEventTransform) return nullptr;
	float dist;
	float dist2;
	for (auto& other : m_sphereCollider)
	{
		if (other == moveEventCollider) continue;

		auto targetTransform = other->gameObject->GetComponent<Transform>().get();
		if (!targetTransform) continue;

		XMVECTOR posA = XMLoadFloat3(&MoveEventTransform->position);
		XMVECTOR posB = XMLoadFloat3(&targetTransform->position);

		// 방향 벡터
		XMVECTOR dir = posB - posA;

		// 실제 거리
		dist = XMVectorGetX(posA - posB) * XMVectorGetX(posA - posB) + XMVectorGetY(posA - posB) * XMVectorGetY(posA - posB) + XMVectorGetZ(posA - posB) * XMVectorGetZ(posA - posB);
		dist2 = moveEventCollider->radius + other->radius;
		dist2 = dist2 * dist2;
		if (dist < dist2)
		{
			XMVECTOR v = XMLoadFloat3(&moveEvent->MoveVector);
			float A = XMVectorGetX(XMVector3LengthSq(v));
			float B = XMVectorGetX(XMVector3Dot(v, dir));
			float C = dist * dist - other->radius * other->radius;

			float D = B * B - 4 * A * C;
			if (D < 0) return other;

			float sqrtD = sqrtf(D);

			float t1 = (-B - sqrtD) / (2 * A);
			float t2 = (-B + sqrtD) / (2 * A);

			float t = (t1 >= 0 && t2 >= 0) ? min(t1, t2) : max(t1, t2);

			// 최종 이동 벡터
			XMVECTOR moveVec = v * t;
			XMStoreFloat3(&moveEvent->MoveVector, moveVec);
			return other;
		}
	}
	for (auto& other : m_boxCollider)
	{
		auto targetTransform = other->gameObject->GetComponentIncludingBase<Transform>().get();
		if (!targetTransform) continue;

		//이벤트가 발생한 오브젝트의 transform 중 position 정보 받아오기
		XMVECTOR sphereCenter = XMLoadFloat3(&MoveEventTransform->position) + XMLoadFloat3(&moveEvent->MoveVector);
		//박스 콜라이더의 transform 중 position 정보 받아오기
		XMVECTOR boxCenter = XMLoadFloat3(&other->Box.pos);
		//두 중점을 잇는 벡터
		XMVECTOR d = XMVectorSubtract(sphereCenter, boxCenter);

		float dist = 0.0f;
		XMVECTOR closest = boxCenter;

		//박스 콜라이더의 수직벡터 가져오기
		XMVECTOR axis[3] = {
			XMLoadFloat3(&other->Box.axisX),
			XMLoadFloat3(&other->Box.axisY),
			XMLoadFloat3(&other->Box.axisZ)
		};

		//박스 콜라이더의 수직벡터의 길이 가져오기
		float halfLength[3] = {
			other->Box.halfLength.x,
			other->Box.halfLength.y,
			other->Box.halfLength.z
		};

		for (int i = 0; i < 3; i++)
		{
			//두 중점의 벡터와 수직 벡터 내적
			float distance = XMVectorGetX(XMVector3Dot(d, axis[i]));

			//내적한 값이 해당 반길이 보다 크면 반길이를 선택
			if (distance > halfLength[i]) distance = halfLength[i];
			if (distance < -halfLength[i]) distance = -halfLength[i];

			//가장 가까운 점 찾기
			closest = XMVectorAdd(closest, XMVectorScale(axis[i], distance));
		}
		//가장 가까운 점과 구의 중점 과의 벡터
		XMVECTOR v = XMVectorSubtract(sphereCenter, closest);
		//위의 벡터의 크기의 제곱 값
		dist = XMVectorGetX(XMVector3Length(v));

		if (dist <= (moveEventCollider->radius))
		{
			XMVECTOR vNor = XMVector3Normalize(v);
			XMStoreFloat3(&moveEvent->MoveVector, vNor * (moveEventCollider->radius - dist));
			return other;
		}
	}
	return nullptr;
}

Collider* Collision::CheckCollision(RayCollider* moveEventCollider, MoveEvent* moveEvent)
{
	auto MoveEventTransform = moveEvent->transform;
	if (!MoveEventTransform) return nullptr;

	for (auto& other : m_sphereCollider)
	{
		auto targetTransform = other->gameObject->GetComponentIncludingBase<Transform>().get();
		if (!targetTransform) continue;

		// DirectXMath 벡터 변환
		XMVECTOR origin = XMLoadFloat3(&MoveEventTransform->position);// Ray 시작점
		XMVECTOR dir = XMVector3Normalize(XMLoadFloat3(&MoveEventTransform->moveVector));// Ray 방향 (정규화)
		XMVECTOR sphereCenter = XMLoadFloat3(&targetTransform->position);// Sphere 중심

		// Ray 시작점에서 Sphere 중심까지의 벡터
		XMVECTOR length = XMVectorSubtract(sphereCenter, origin);

		// Ray 방향 벡터 D에 대한 L의 투영 (t_ca)
		float t_ca = XMVectorGetX(XMVector3Dot(length, dir));

		// Ray가 반대 방향을 가리키면 충돌 없음
		if (t_ca < 0) continue;

		// 중심에서 Ray까지의 거리 d^2 = |L|^2 - t_ca^2
		float d2 = XMVectorGetX(XMVector3Dot(length, length)) - (t_ca * t_ca);
		// Sphere의 반지금 제곱
		float r2 = other->radius * other->radius;

		// 최근접 거리가 반지름보다 크면 충돌 없음
		if (d2 > r2) continue;

		float thc = sqrtf(r2 - d2);      // 접점까지의 거리
		float t = t_ca - thc;            // 충돌 지점까지 거리

		XMVECTOR moveVec = dir * t;
		XMStoreFloat3(&moveEvent->MoveVector, moveVec);

		return other;
	}
	for (auto& other : m_boxCollider)
	{
		bool hit = true;
		auto targetTransform = other->gameObject->GetComponentIncludingBase<Transform>().get();
		if (!targetTransform) continue;

		constexpr float EPSILON = 1e-6f;

		//ray의 시작점
		XMVECTOR origin = XMLoadFloat3(&MoveEventTransform->position);
		//ray의 방향벡터
		XMVECTOR dir = XMVector3Normalize(XMLoadFloat3(&MoveEventTransform->moveVector));
		//ray의 방향벡터의 크기
		float length = XMVectorGetX(XMVector3Length(XMLoadFloat3(&MoveEventTransform->moveVector)));
		//box 콜라이더의 중점
		XMVECTOR boxCenter = XMLoadFloat3(&other->Box.pos);

		//박스 콜라이더의 수직벡터 가져오기
		XMVECTOR axis[3] = {
			XMLoadFloat3(&other->Box.axisX),
			XMLoadFloat3(&other->Box.axisY),
			XMLoadFloat3(&other->Box.axisZ)
		};

		//박스 콜라이더의 수직벡터의 길이 가져오기
		float halfLength[3] = {
			other->Box.halfLength.x,
			other->Box.halfLength.y,
			other->Box.halfLength.z
		};

		float tMax = FLT_MAX;
		float tMin = -FLT_MAX;

		//박스 중심에서 레이 시작점을 뺀 벡터
		XMVECTOR d = XMVectorSubtract(boxCenter, origin);

		for (int i = 0; i < 3; ++i)
		{
			if (!hit) break;
			//레이 시작점과 박스축 방향과의 투영 거리
			float e = XMVectorGetX(XMVector3Dot(axis[i], d));
			//레이 방향이 박스 축의 내적
			float f = XMVectorGetX(XMVector3Dot(axis[i], dir));

			//레이 방향과 박스 축의 내적의 절대값이 0보다 크면
			if (fabsf(f) > EPSILON)
			{
				//레이의 짐입시 t와 탈출시 t를 계산
				float t1 = (e + halfLength[i]) / f;
				float t2 = (e - halfLength[i]) / f;

				//둘 중 작은 값을 진입시 t로 
				if (t1 > t2) std::swap(t1, t2);

				//tMin과 tMax 최신화
				tMin = max(tMin, t1);
				tMax = min(tMax, t2);

				if (tMin > tMax)
				{
					hit = false;
					continue;
				}
				if (tMax < 0.0f)
				{
					hit = false;
					continue;
				}
				if (tMin > length)
				{
					hit = false;
					continue;
				}
				hit = true;
			}
			else
			{
				// f == 0, 방향이 축과 평행한 경우
				if (-e - halfLength[i] > 0.0f || -e + halfLength[i] < 0.0f)
				{
					// 평행인데 범위 밖이면 충돌 없음
					hit = false;
					break;
				}
			}
		}

		if (!hit) continue;

		XMStoreFloat3(&moveEvent->MoveVector, dir * tMin);

		return other;
	}
	return nullptr;
}

void Collision::AddCollider(Collider* colliderObject)
{
	switch (colliderObject->type)
	{
	case ColliderType::Box:
	{
		auto* boxCollider = dynamic_cast<BoxCollider*>(colliderObject);
		m_boxCollider.push_back(boxCollider);
	}break;
	case ColliderType::Sphere:
	{
		auto* sphereCollider = dynamic_cast<SphereCollider*>(colliderObject);
		m_sphereCollider.push_back(sphereCollider);
	}break;
	case ColliderType::Ray:
	{
		auto* rayCollider = dynamic_cast<RayCollider*>(colliderObject);
		m_rayCollider.push_back(rayCollider);
	}break;
	}
}

bool Collision::RemoveCollider(Collider* colliderObject)
{
	switch (colliderObject->type)
	{
	case ColliderType::Box:
	{
		auto boxCollider = dynamic_cast<BoxCollider*>(colliderObject);
		m_boxCollider.erase(std::remove(m_boxCollider.begin(), m_boxCollider.end(), boxCollider), m_boxCollider.end());
	}break;
	case ColliderType::Sphere:
	{
		auto sphereCollider = dynamic_cast<SphereCollider*>(colliderObject);
		m_sphereCollider.erase(std::remove(m_sphereCollider.begin(), m_sphereCollider.end(), sphereCollider), m_sphereCollider.end());
	}break;
	case ColliderType::Ray:
	{
		auto rayCollider = dynamic_cast<RayCollider*>(colliderObject);
		m_rayCollider.erase(std::remove(m_rayCollider.begin(), m_rayCollider.end(), rayCollider), m_rayCollider.end());
	}break;
	}
	return true;
}

void Collision::AddEvent(MoveEvent* event)
{
	m_eventQueue.push(event);
}

void Collision::ProcessCollision()
{
	vector<pair<Collider*, Collider*>> CollidedPair;

	while (!m_eventQueue.empty())
	{
		//이벤트를 뽑아옴
		MoveEvent* event = m_eventQueue.front();
		m_eventQueue.pop();

		//이벤트가 꺼져있는 오브젝트라면 패스
		if (!event->transform->gameObject->active) continue;

		//이벤트가 발생한 대상의 콜라이더를 검사: RayCollider가 있는지 검사
		if (const auto& Ray = event->transform->gameObject->GetComponentIncludingBase<RayCollider>())
		{
			//RayCollider가 있다면
			if (Ray)
			{
				//RayCollision의 검사를 진행
				auto other = CheckCollision(Ray.get(), event);
				//충돌한 대상이 있다면
				if (other != nullptr)
				{
					Ray->trackingCollider = other;
					CollidedPair.emplace_back(&(*Ray), &(*other));
				}
				event->transform->ApplyTranslate(event->MoveVector);
				continue;
			}
		}
		//이벤트가 발생한 대상의 콜라이더를 검사: SphereCollider가 있는지 검사
		if (const auto& Sphere = event->transform->gameObject->GetComponentIncludingBase<SphereCollider>())
		{
			//SphereCollider가 있다면
			if (Sphere)
			{
				//SphereCollison의 검사를 진행
				auto other = CheckCollision(Sphere.get(), event);
				//충돌한 대상이 있다면
				if (other != nullptr)
				{
					//충돌한 대상과 충돌당한 대상을 CollidedCollider에 추가
					Sphere->trackingCollider = other;
					CollidedPair.emplace_back(&(*Sphere), &(*other));
				}
				event->transform->ApplyTranslate(event->MoveVector);
				continue;
			}
		}

		//콜라이더가 없는 이벤트는 이동 허용
		//event->transform->ApplyTranslate(event->MoveVector);
	}

	//콜라이더의 오브젝트의 이동 이벤트를 허용하는 과정
	/*
	1. 지금 충돌이 있는 대상이 tracking 당하고 있으면 stay 호출
	2. 아니면 enter 호출
	3. enter 나 stay를 호출했다면 전 프레임에 충돌이 있는 vector에서 제거
	4. 다 제거하면 남은 전 프레임에 충돌이 있는 vector의 exit 호출하고 clear 호출
	5. 현재 충돌한 collider vector를 모두 전 프레임에 충돌이 있는 대상에 추가하고 현재 vector는 clear
	*/

	//충돌 검사를 통해 충돌이 되었다고 판단된 콜라이더
	for (auto& cp : CollidedPair)
	{
		//충돌 검사한 대상과 충돌했던 대상이 있으면
		if (cp.second != nullptr)
		{
			//충돌 검사한 대상이 직전에 충돌 전적이 있으면
			if (cp.first->trackingCollider != nullptr)
			{
				if (cp.first->isCollision) cp.first->gameObject->OnCollisionStay(cp.second);
				else cp.first->gameObject->OnTriggerStay(cp.second);
			}
			else
			{
				if (cp.first->isCollision) cp.first->gameObject->OnCollisionEnter(cp.second);
				else cp.first->gameObject->OnTriggerEnter(cp.second);
			}
			//충돌 당한 대상이 직전에 충돌 전적이 있으면
			if (cp.second->trackingCollider != nullptr)
			{
				if (cp.second->isCollision) cp.second->gameObject->OnCollisionStay(cp.first);
				else cp.second->gameObject->OnTriggerStay(cp.first);
			}
			else
			{
				if (cp.second->isCollision) cp.second->gameObject->OnCollisionEnter(cp.first);
				else cp.second->gameObject->OnTriggerEnter(cp.first);
			}
			//충돌 하였기에 충돌하였다고 명시
			cp.first->trackingCollider = cp.second;
			cp.second->trackingCollider = cp.first;
		}

		//추적중인 콜라이더에서 제외
		m_trackingCollider.erase(cp.first);
		m_trackingCollider.erase(cp.second);
	}
	//추적 중이던 대상 중 충돌이 일어나지 않은 대상
	for (auto& tc : m_trackingCollider)
	{
		if (tc->isCollision)
		{
			tc->gameObject->OnCollisionExit(tc->trackingCollider);
			tc->trackingCollider = nullptr;
		}
	}
	m_trackingCollider.clear();
	//이번에 충돌이 있었던 대상을 추적 대상으로 다시 추가
	for (auto& cp : CollidedPair)
	{
		if (cp.second == nullptr) continue;
		m_trackingCollider.insert(cp.first);
		m_trackingCollider.insert(cp.second);
	}
}