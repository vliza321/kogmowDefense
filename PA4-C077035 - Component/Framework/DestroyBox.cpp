#include "DestroyBox.h"
#include "Collider.h"
#include "GameManager.h"

void DestroyBox::OnCollisionEnter(Collider* other)
{
	if (other->gameObject->CompareTag(Tag::ArtilleryBullet) || other->gameObject->CompareTag(Tag::NormalBullet) || other->gameObject->CompareTag(Tag::ScopeBullet))
	{
		Find("ResultUI")->GetComponent<GameManager>()->m_boxCount--;
		this->active = false;
		this->gameObject->SetActive(false);
	}
}
