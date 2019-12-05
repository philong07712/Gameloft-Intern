# include "SpaceShooter.h"
# include "Bullet.h"
using namespace std;

SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
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
}
// Intial Global
static float a = 0;

void SpaceShooter::Update(float dt)
{
	a += dt;
	auto moveBy = MoveBy::create(2.0f, Vec2(0, 1100));
	auto sequence = Sequence::create(moveBy, nullptr);
	for (int i = 0; i < 20; i++)
	{
		auto bullet = this->m_bullets[i]->getSprite();
		if (!bullet->isVisible() && a > dt * 15) {
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

void SpaceShooter::Collision(vector<Rock*> rock)
{
}
