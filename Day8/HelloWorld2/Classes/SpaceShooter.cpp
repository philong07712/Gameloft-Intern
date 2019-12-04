# include "SpaceShooter.h"
using namespace std;

SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
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
}

void SpaceShooter::Update(float dt)
{
}

void SpaceShooter::Shoot()
{
}

void SpaceShooter::Collision(vector<Rock*> rock)
{
}
