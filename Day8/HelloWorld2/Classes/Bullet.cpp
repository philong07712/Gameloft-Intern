# include "Bullet.h"
# include "ResourceManager.h"
Bullet::Bullet(cocos2d::Scene * scene)
{
	auto bulletSprite = ResourceManager::getInstance()->GetSpriteById(2);
	auto bullet = Sprite::createWithSpriteFrame(bulletSprite->getSpriteFrame());
	this->setSprite(bullet);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
}

void Bullet::Update(float dt)
{

}
