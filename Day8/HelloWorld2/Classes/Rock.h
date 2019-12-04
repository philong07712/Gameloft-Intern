
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "Object.h"
class Rock : public Object {
public:
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init();
	void Update(float dt);
};