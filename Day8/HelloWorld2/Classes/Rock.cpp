# include "Rock.h"
# include "ResourceManager.h"
Rock::Rock(cocos2d::Scene * scene)
{
	Rock::Init();
}

Rock::~Rock()
{
}

void Rock::Init()
{
	float randomSize = 0.5 + ((float)rand()) / (float)RAND_MAX;
	auto rock = DuplicateSprite(ResourceManager::getInstance()->GetSpriteById(3));
	rock->setScale(randomSize);
	setSprite(rock);
	getSprite()->setVisible(false);
	InitPhysic();
}

void Rock::Update(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = getSprite();
	if (rock->getPosition().y < -100)
	{
		rock->setVisible(false);
		rock->stopAllActions();
		rock->setPosition(rock->getPosition().x, visibleSize.height + 300);
	}
}

void Rock::InitPhysic()
{
	auto physicBody = PhysicsBody::createBox(getSprite()->getContentSize());
	physicBody->setCategoryBitmask(0x02);
	physicBody->setCollisionBitmask(0x01);
	getSprite()->setPhysicsBody(physicBody);
}
