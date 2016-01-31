#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <memory>

#include "GameDefines.h"

namespace gameobject{

	class GameObject {
	public:
		virtual ~GameObject(){}
		virtual void ApplyDamage(float damage);
				
		void SetDeity(Deities deity);
		Deities GetDeity();

		cocos2d::Sprite *GetSprite();
		
		void SetHealth(float health);
		float GetHealth();

		void SetTarget(GameObject *target);
		GameObject *GetTarget();
		
	protected:
		float m_fHealth;
		Deities m_Deity;
		float m_fAttackValue;
		cocos2d::Sprite *m_Sprite;
		GameObject *m_pTarget;
	};

}

#endif