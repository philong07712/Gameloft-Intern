﻿# include "SpaceShooter.h"
# include "Bullet.h"
# include "MainMenuScene.h"
# include "GameOverScene.h"
using namespace std;

cocos2d::Scene* targetScene;
SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	targetScene = scene;
	SpaceShooter::Init();
	// create the bullet
	for (int i = 0; i < 20; i++)
	{
		Bullet *bullet = new Bullet(scene);
		this->m_bullets.push_back(bullet);
		scene->addChild(bullet->getSprite());
		bullet->getSprite()->setVisible(false);
	}

	// create the spaceShip
	auto ship = cocos2d::Sprite::create();
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Sprites\\SpaceShip\\ship.plist", "Sprites\\SpaceShip\\ship.png");
	cocos2d::Vector<cocos2d::SpriteFrame*> shipFrames;
	scene->addChild(ship);
	int maxFrame = 8;
	const auto maxChar = 35;
	char frameName[maxChar] = { 0 };
	for (int i = 1; i <= maxFrame; i++) {
		sprintf(frameName, "%d.png", i);
		shipFrames.pushBack(spriteCache->getSpriteFrameByName(frameName));
	}
	auto animation = cocos2d::Animation::createWithSpriteFrames(shipFrames, 0.15f);
	auto animate = cocos2d::Animate::create(animation);
	ship->runAction(cocos2d::RepeatForever::create(animate));
	setSprite(ship);
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	SpaceShooter::Effect();
}
// Intial Global
static float a = 0;

void SpaceShooter::Update(float dt)
{
	a += dt;
	auto moveBy = MoveBy::create(1.5f, Vec2(0, 1100));
	auto sequence = Sequence::create(moveBy, nullptr);
	for (int i = 0; i < 20; i++)
	{
		auto bullet = this->m_bullets[i]->getSprite();
		if (!bullet->isVisible() && a > dt * 10) {
			bullet->setVisible(true);
			bullet->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
			bullet->runAction(sequence->clone());
			a = 0;
			break;
		}
		if (bullet->getPosition().y > 1000)
		{
			bullet->stopAllActions();
			bullet->setVisible(false);
			bullet->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
		}
	}
}

void SpaceShooter::Shoot()
{

}
Sprite* effect;
void SpaceShooter::Effect()
{
	auto emitter = CCParticleSystemQuad::create("purple_effect.plist");
	//emitter->setTextureWithRect(Director::getInstance()->getTextureCache()->addImage("purple_effect.png"), Rect(0, 0, 32, 32));
	//auto emitter = ParticleExplosion::create();
	emitter->setDuration(5.0f);
	emitter->setScale(0.25f);
	targetScene->addChild(emitter);
	emitter->setPosition(300, 500);
}

void SpaceShooter::Collision(vector<Rock*> rocks)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		auto rock = rocks[i]->getSprite();
		for (int i = 0; i < this->m_bullets.size(); i++)
		{
			auto bullet = this->m_bullets[i]->getSprite();
			if (bullet->getBoundingBox().intersectsRect(rock->getBoundingBox()) 
				&& rock->isVisible() && bullet->isVisible())
			{
				bullet->setVisible(false);
				rock->setVisible(false);
				rock->setPosition(rock->getPosition().x, -100);
				bullet->setPosition(bullet->getPosition().x, 1000);

			}
		}
		if (getSprite()->getBoundingBox().intersectsRect(rock->getBoundingBox()) && rock->isVisible())
		{
			auto myScene = GameOverScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.0f, myScene));
		}
	}
}
