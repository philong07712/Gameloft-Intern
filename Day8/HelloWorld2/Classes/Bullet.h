
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "PlayObject.h"
	
class Bullet : public PlayObject {
public:
	Bullet(cocos2d::Scene* scene);
	~Bullet();
	void initPhysicBody();
	void Init();
	void Update(float dt);
};