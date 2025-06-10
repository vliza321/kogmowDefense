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

		// ���� ����
		XMVECTOR dir = posB - posA;

		// ���� �Ÿ�
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

			// ���� �̵� ����
			XMVECTOR moveVec = v * t;
			XMStoreFloat3(&moveEvent->MoveVector, moveVec);
			return other;
		}
	}
	for (auto& other : m_boxCollider)
	{
		auto targetTransform = other->gameObject->GetComponentIncludingBase<Transform>().get();
		if (!targetTransform) continue;

		//�̺�Ʈ�� �߻��� ������Ʈ�� transform �� position ���� �޾ƿ���
		XMVECTOR sphereCenter = XMLoadFloat3(&MoveEventTransform->position) + XMLoadFloat3(&moveEvent->MoveVector);
		//�ڽ� �ݶ��̴��� transform �� position ���� �޾ƿ���
		XMVECTOR boxCenter = XMLoadFloat3(&other->Box.pos);
		//�� ������ �մ� ����
		XMVECTOR d = XMVectorSubtract(sphereCenter, boxCenter);

		float dist = 0.0f;
		XMVECTOR closest = boxCenter;

		//�ڽ� �ݶ��̴��� �������� ��������
		XMVECTOR axis[3] = {
			XMLoadFloat3(&other->Box.axisX),
			XMLoadFloat3(&other->Box.axisY),
			XMLoadFloat3(&other->Box.axisZ)
		};

		//�ڽ� �ݶ��̴��� ���������� ���� ��������
		float halfLength[3] = {
			other->Box.halfLength.x,
			other->Box.halfLength.y,
			other->Box.halfLength.z
		};

		for (int i = 0; i < 3; i++)
		{
			//�� ������ ���Ϳ� ���� ���� ����
			float distance = XMVectorGetX(XMVector3Dot(d, axis[i]));

			//������ ���� �ش� �ݱ��� ���� ũ�� �ݱ��̸� ����
			if (distance > halfLength[i]) distance = halfLength[i];
			if (distance < -halfLength[i]) distance = -halfLength[i];

			//���� ����� �� ã��
			closest = XMVectorAdd(closest, XMVectorScale(axis[i], distance));
		}
		//���� ����� ���� ���� ���� ���� ����
		XMVECTOR v = XMVectorSubtract(sphereCenter, closest);
		//���� ������ ũ���� ���� ��
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

		// DirectXMath ���� ��ȯ
		XMVECTOR origin = XMLoadFloat3(&MoveEventTransform->position);// Ray ������
		XMVECTOR dir = XMVector3Normalize(XMLoadFloat3(&MoveEventTransform->moveVector));// Ray ���� (����ȭ)
		XMVECTOR sphereCenter = XMLoadFloat3(&targetTransform->position);// Sphere �߽�

		// Ray ���������� Sphere �߽ɱ����� ����
		XMVECTOR length = XMVectorSubtract(sphereCenter, origin);

		// Ray ���� ���� D�� ���� L�� ���� (t_ca)
		float t_ca = XMVectorGetX(XMVector3Dot(length, dir));

		// Ray�� �ݴ� ������ ����Ű�� �浹 ����
		if (t_ca < 0) continue;

		// �߽ɿ��� Ray������ �Ÿ� d^2 = |L|^2 - t_ca^2
		float d2 = XMVectorGetX(XMVector3Dot(length, length)) - (t_ca * t_ca);
		// Sphere�� ������ ����
		float r2 = other->radius * other->radius;

		// �ֱ��� �Ÿ��� ���������� ũ�� �浹 ����
		if (d2 > r2) continue;

		float thc = sqrtf(r2 - d2);      // ���������� �Ÿ�
		float t = t_ca - thc;            // �浹 �������� �Ÿ�

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

		//ray�� ������
		XMVECTOR origin = XMLoadFloat3(&MoveEventTransform->position);
		//ray�� ���⺤��
		XMVECTOR dir = XMVector3Normalize(XMLoadFloat3(&MoveEventTransform->moveVector));
		//ray�� ���⺤���� ũ��
		float length = XMVectorGetX(XMVector3Length(XMLoadFloat3(&MoveEventTransform->moveVector)));
		//box �ݶ��̴��� ����
		XMVECTOR boxCenter = XMLoadFloat3(&other->Box.pos);

		//�ڽ� �ݶ��̴��� �������� ��������
		XMVECTOR axis[3] = {
			XMLoadFloat3(&other->Box.axisX),
			XMLoadFloat3(&other->Box.axisY),
			XMLoadFloat3(&other->Box.axisZ)
		};

		//�ڽ� �ݶ��̴��� ���������� ���� ��������
		float halfLength[3] = {
			other->Box.halfLength.x,
			other->Box.halfLength.y,
			other->Box.halfLength.z
		};

		float tMax = FLT_MAX;
		float tMin = -FLT_MAX;

		//�ڽ� �߽ɿ��� ���� �������� �� ����
		XMVECTOR d = XMVectorSubtract(boxCenter, origin);

		for (int i = 0; i < 3; ++i)
		{
			if (!hit) break;
			//���� �������� �ڽ��� ������� ���� �Ÿ�
			float e = XMVectorGetX(XMVector3Dot(axis[i], d));
			//���� ������ �ڽ� ���� ����
			float f = XMVectorGetX(XMVector3Dot(axis[i], dir));

			//���� ����� �ڽ� ���� ������ ���밪�� 0���� ũ��
			if (fabsf(f) > EPSILON)
			{
				//������ ���Խ� t�� Ż��� t�� ���
				float t1 = (e + halfLength[i]) / f;
				float t2 = (e - halfLength[i]) / f;

				//�� �� ���� ���� ���Խ� t�� 
				if (t1 > t2) std::swap(t1, t2);

				//tMin�� tMax �ֽ�ȭ
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
				// f == 0, ������ ��� ������ ���
				if (-e - halfLength[i] > 0.0f || -e + halfLength[i] < 0.0f)
				{
					// �����ε� ���� ���̸� �浹 ����
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
		//�̺�Ʈ�� �̾ƿ�
		MoveEvent* event = m_eventQueue.front();
		m_eventQueue.pop();

		//�̺�Ʈ�� �����ִ� ������Ʈ��� �н�
		if (!event->transform->gameObject->active) continue;

		//�̺�Ʈ�� �߻��� ����� �ݶ��̴��� �˻�: RayCollider�� �ִ��� �˻�
		if (const auto& Ray = event->transform->gameObject->GetComponentIncludingBase<RayCollider>())
		{
			//RayCollider�� �ִٸ�
			if (Ray)
			{
				//RayCollision�� �˻縦 ����
				auto other = CheckCollision(Ray.get(), event);
				//�浹�� ����� �ִٸ�
				if (other != nullptr)
				{
					Ray->trackingCollider = other;
					CollidedPair.emplace_back(&(*Ray), &(*other));
				}
				event->transform->ApplyTranslate(event->MoveVector);
				continue;
			}
		}
		//�̺�Ʈ�� �߻��� ����� �ݶ��̴��� �˻�: SphereCollider�� �ִ��� �˻�
		if (const auto& Sphere = event->transform->gameObject->GetComponentIncludingBase<SphereCollider>())
		{
			//SphereCollider�� �ִٸ�
			if (Sphere)
			{
				//SphereCollison�� �˻縦 ����
				auto other = CheckCollision(Sphere.get(), event);
				//�浹�� ����� �ִٸ�
				if (other != nullptr)
				{
					//�浹�� ���� �浹���� ����� CollidedCollider�� �߰�
					Sphere->trackingCollider = other;
					CollidedPair.emplace_back(&(*Sphere), &(*other));
				}
				event->transform->ApplyTranslate(event->MoveVector);
				continue;
			}
		}

		//�ݶ��̴��� ���� �̺�Ʈ�� �̵� ���
		//event->transform->ApplyTranslate(event->MoveVector);
	}

	//�ݶ��̴��� ������Ʈ�� �̵� �̺�Ʈ�� ����ϴ� ����
	/*
	1. ���� �浹�� �ִ� ����� tracking ���ϰ� ������ stay ȣ��
	2. �ƴϸ� enter ȣ��
	3. enter �� stay�� ȣ���ߴٸ� �� �����ӿ� �浹�� �ִ� vector���� ����
	4. �� �����ϸ� ���� �� �����ӿ� �浹�� �ִ� vector�� exit ȣ���ϰ� clear ȣ��
	5. ���� �浹�� collider vector�� ��� �� �����ӿ� �浹�� �ִ� ��� �߰��ϰ� ���� vector�� clear
	*/

	//�浹 �˻縦 ���� �浹�� �Ǿ��ٰ� �Ǵܵ� �ݶ��̴�
	for (auto& cp : CollidedPair)
	{
		//�浹 �˻��� ���� �浹�ߴ� ����� ������
		if (cp.second != nullptr)
		{
			//�浹 �˻��� ����� ������ �浹 ������ ������
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
			//�浹 ���� ����� ������ �浹 ������ ������
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
			//�浹 �Ͽ��⿡ �浹�Ͽ��ٰ� ���
			cp.first->trackingCollider = cp.second;
			cp.second->trackingCollider = cp.first;
		}

		//�������� �ݶ��̴����� ����
		m_trackingCollider.erase(cp.first);
		m_trackingCollider.erase(cp.second);
	}
	//���� ���̴� ��� �� �浹�� �Ͼ�� ���� ���
	for (auto& tc : m_trackingCollider)
	{
		if (tc->isCollision)
		{
			tc->gameObject->OnCollisionExit(tc->trackingCollider);
			tc->trackingCollider = nullptr;
		}
	}
	m_trackingCollider.clear();
	//�̹��� �浹�� �־��� ����� ���� ������� �ٽ� �߰�
	for (auto& cp : CollidedPair)
	{
		if (cp.second == nullptr) continue;
		m_trackingCollider.insert(cp.first);
		m_trackingCollider.insert(cp.second);
	}
}