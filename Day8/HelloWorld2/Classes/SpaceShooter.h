
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "Object.h"
#include "Rock.h"
using namespace std;
class SpaceShooter : public Object {
	vector<Object*> m_bullets;
public:
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init();
	void Update(float dt);
	void Shoot();
	void Collision(vector<Rock*> rock);
};