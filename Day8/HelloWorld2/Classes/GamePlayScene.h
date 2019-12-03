
#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "cocos2d.h"
#include "LogoScene.h"
class GamePlayScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void update(float deltaTime);
	void addShip();
	void addBackGround();
	void continueMoving();
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayScene);
};

#endif // __GAMEPLAY_SCENE_H__
