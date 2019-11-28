#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
USING_NS_CC;

class LogoScene : public Scene {
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);
	CREATE_FUNC(LogoScene);
};
#endif // __LOGO_SCENE_H__
