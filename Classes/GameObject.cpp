#include "GameObject.h"

namespace gameobject{
	void GameObject::ApplyDamage(float damage)
	{
		m_fHealth -= damage;
	}

	Deities GameObject::GetDeity()
	{
		return m_Deity;
	}

	void GameObject::SetDeity(Deities deity)
	{
		m_Deity = deity;
	}

	void GameObject::SetTarget(GameObject *target)
	{
		m_pTarget = target;
	}

	State GameObject::GetState()
	{
		return m_eState;
	}

	void GameObject::SetState(State state)
	{
		m_eState = state;
	}

	ObjectType GameObject::GetObjectType()
	{
		return m_eObjectType;
	}


	GameObject *GameObject::GetTarget()
	{
		return m_pTarget;
	}

	void GameObject::SetHealth(float health)
	{
		m_fHealth = health;
	}

	float GameObject::GetHealth()
	{
		return m_fHealth;
	}

	cocos2d::Sprite *GameObject::GetSprite()
	{
		return m_Sprite;
	}

}