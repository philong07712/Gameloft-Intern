
#pragma once
#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__
#include "cocos2d.h"
USING_NS_CC;

class LogoScene : public Scene {
public:
	static Scene* createScene();
	virtual bool init(); 
	void update(float deltaTime);
	void changeScene();
	void changeLoading(float dt);
	CREATE_FUNC(LogoScene);
};
#endif // __LOGO_SCENE_H__