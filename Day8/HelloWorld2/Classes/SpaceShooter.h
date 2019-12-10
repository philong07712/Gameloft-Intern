
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "PlayObject.h"
#include "Rock.h"
using namespace std;
USING_NS_CC;
class SpaceShooter : public PlayObject {
	vector<PlayObject*> m_bullets;
	int score;
public:
	SpaceShooter(cocos2d::Scene* scene);
	~SpaceShooter();
	void Init();
	void Update(float dt);
	void Shoot(float dt);
	void borderShip();
	void Effect(cocos2d::Node* , cocos2d::Node*);
	void Collision(vector<Rock*> rock);
	bool onContactBegin(PhysicsContact& contact);
	void WriteScore();
};