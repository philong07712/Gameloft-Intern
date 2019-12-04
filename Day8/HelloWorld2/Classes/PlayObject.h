
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"

class PlayObject {
	cocos2d::Sprite* m_sprite;
public:
	cocos2d::Sprite* getSprite();
	void setSprite(cocos2d::Sprite* sprite);
	PlayObject();
	~PlayObject();
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
};