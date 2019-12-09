
#ifndef __GAMEPLAY2_SCENE_H__
#define __GAMEPLAY2_SCENE_H__

#include "cocos2d.h"
#include "LogoScene.h"
#include "Rock.h"
#include "SpaceShooter.h"
using namespace std;
class GamePlay2Sene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
	virtual bool init();
	void addMap();
	void update(float deltaTime);
	void updateMap();
    CREATE_FUNC(GamePlay2Sene);
};

#endif // __GAMEPLAY2_SCENE_H__
