
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "PlayObject.h"
#include "Rock.h"
using namespace std;
USING_NS_CC;
class SpaceShooter : public PlayObject {
	vector<PlayObject*> m_bullets;
public:
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init();
	void Update(float dt);
	void Shoot();
	void Collision(vector<Rock*> rock);
	void WriteScore();
};