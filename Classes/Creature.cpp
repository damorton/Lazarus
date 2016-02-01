#include "Creature.h"
#include "WorldManager.h"

Creature::Creature(Deities deity)
{
	m_Deity = deity;
	if (deity == HELIX)
	{
		m_Sprite = cocos2d::Sprite::create("helixCreature.png");
	}
	else
	{
		m_Sprite = cocos2d::Sprite::create("domeCreature.png");
	}
	m_fHealth = 100;
	m_eState = ALIVE;
	m_eObjectType = CREATURE;
	Init();
}

void Creature::Init()
{
	float smallestDistance = 99999;	
	for (int i = 0; i < WorldManager::getInstance()->getGameObects().size(); i++)
	{
		float xDist = (WorldManager::getInstance()->getGameObects().at(i)->GetSprite()->getPositionX() - m_Sprite->getPositionX());
		float yDist = (WorldManager::getInstance()->getGameObects().at(i)->GetSprite()->getPositionY() - m_Sprite->getPositionY());
		float distance = sqrt((xDist * xDist) + (yDist * yDist));
		if (distance < smallestDistance && WorldManager::getInstance()->getGameObects().at(i)->GetDeity() != m_Deity && WorldManager::getInstance()->getGameObects().at(i)->GetObjectType() == RITUAL)
		{
			m_pTarget = WorldManager::getInstance()->getGameObects().at(i).get();
			smallestDistance = distance;
		}
	}
	
	m_Sprite->setScale(0.1f, 0.1f);
	auto growAction = cocos2d::ScaleTo::create(0.5f * ACTION_SPEED, 0.5f);
	m_Sprite->runAction(growAction);
	MoveToTarget();
}

void Creature::Update(float dt)
{
	if (m_Sprite->getBoundingBox().intersectsRect(m_pTarget->GetSprite()->getBoundingBox()) && m_Sprite->isVisible() && m_pTarget->GetSprite()->isVisible())
	{
		Attack();
		m_Sprite->getParent()->removeChild(m_Sprite);
		m_eState = DEAD;
	}
		
}

void Creature::MoveToTarget()
{
	if (m_pTarget != nullptr)
	{
		// Move to target
		auto moveAction = cocos2d::MoveTo::create(4.0f * ACTION_SPEED, m_pTarget->GetSprite()->getPosition());
		auto easeInOut = cocos2d::EaseInOut::create(moveAction->clone(), 2.0f);
		//auto delay = cocos2d::DelayTime::create(4.0f * ACTION_SPEED);
		//auto attack = cocos2d::CallFunc::create(std::bind(&Creature::Attack, this));
		auto sequence = cocos2d::Sequence::create(easeInOut, nullptr);

		m_Sprite->runAction(sequence);
	}
}

void Creature::Attack()
{
	CCLOG("Creature attacked!");
	m_pTarget->ApplyDamage(m_fAttackValue);
}