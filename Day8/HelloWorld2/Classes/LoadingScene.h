
#pragma once
#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__
#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public Scene {
public:
	static Scene* createScene();
	virtual bool init(); 
	void background();
	void update(float deltaTime);
	void addLoading();
	void changeMainMenu(float dt);
	CREATE_FUNC(LoadingScene);
};
#endif // __LOADING_SCENE_H__