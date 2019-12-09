# include "Bullet.h"
# include "ResourceManager.h"
Bullet::Bullet(cocos2d::Scene * scene)
{
	auto bullet = DuplicateSprite(ResourceManager::getInstance()->GetSpriteById(2));
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
