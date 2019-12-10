
#ifndef __GAMEPLAY2_SCENE_H__
#define __GAMEPLAY2_SCENE_H__

#include "cocos2d.h"
#include "LogoScene.h"
#include "Rock.h"
#include "SpaceShooter.h"
using namespace std;
class GamePlay2Scene : public cocos2d::Scene
{
	vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
	std::vector <TMXTiledMap*> maps;
	float delayRock;
public:
    static cocos2d::Scene* createScene();
	virtual bool init();
	void addMap();
	void update(float deltaTime);
	void updateMap();
	void initPhysic();
	void initShip();
	void GenerateRock();
	void addListener();
	void moveRock(float DeltaTime);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(GamePlay2Scene);
};

#endif // __GAMEPLAY2_SCENE_H__
