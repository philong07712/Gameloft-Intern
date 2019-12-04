#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "PlayObject.h"

class Rock : public PlayObject {
public:
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init();
	void Update(float dt);
};