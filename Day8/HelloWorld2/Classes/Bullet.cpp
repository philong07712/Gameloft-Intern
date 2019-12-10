# include "Bullet.h"
# include "ResourceManager.h"
Bullet::Bullet(cocos2d::Scene * scene)
{
	auto bullet = DuplicateSprite(ResourceManager::getInstance()->GetSpriteById(2));
	this->setSprite(bullet);
	Init();
}

Bullet::~Bullet()
{
}

void Bullet::initPhysicBody()
{
	auto physicBody = PhysicsBody::createBox(this->getSprite()->getContentSize());
	physicBody->setGravityEnable(false);
	physicBody->setRotationEnable(false);
	physicBody->setContactTestBitmask(1);
	physicBody->setTag(10);
	getSprite()->setTag(10);
	getSprite()->setPhysicsBody(physicBody);
}

void Bullet::Init()
{
	initPhysicBody();
}

void Bullet::Update(float dt)
{

}
