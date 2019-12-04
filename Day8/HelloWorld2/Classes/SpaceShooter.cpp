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
		bullet->getSprite()->setPosition(i * 20, 0);
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
static int a = 0;
void SpaceShooter::Update(float dt)
{
	auto moveBy = MoveBy::create(10.0f, Vec2(0, 20));
	auto sequence = Sequence::create(moveBy, moveBy->reverse(), nullptr);
	for (int i = 0; i < 20; i++)
	{
		auto bullet = this->m_bullets[i]->getSprite();
		bullet->runAction(RepeatForever::create(sequence->clone()));
		bullet->setVisible(true);
		if (bullet->getPosition().y > 1000)
		{
			bullet->setPosition(bullet->getPosition().x, 0);
		}
	}
}

void SpaceShooter::Shoot()
{ 

}

void SpaceShooter::Collision(vector<Rock*> rock)
{
}
