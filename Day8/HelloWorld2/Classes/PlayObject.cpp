# include "PlayObject.h"

cocos2d::Sprite * PlayObject::getSprite()
{
	return m_sprite;
}

void PlayObject::setSprite(cocos2d::Sprite * sprite)
{
	m_sprite = sprite;
}

PlayObject::PlayObject()
{

}

PlayObject::~PlayObject()
{

}
