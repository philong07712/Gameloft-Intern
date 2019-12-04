
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"

class Object {
	cocos2d::Sprite* m_sprite;
public:
	Object();
	~Object();
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
};