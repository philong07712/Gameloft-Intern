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
	auto rockSprite = ResourceManager::getInstance()->GetSpriteById(3);
	auto rock = Sprite::createWithSpriteFrame(rockSprite->getSpriteFrame());
	rock->setScale(randomSize);
	setSprite(rock);
	getSprite()->setVisible(false);
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
