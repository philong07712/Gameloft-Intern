
#pragma once
#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__
#include "ui/CocosGUI.h"
#include "cocos2d.h"

USING_NS_CC;

class MainMenuScene : public Scene {
public:
	static Scene* createScene();
	virtual bool init(); 
	void update(float deltaTime);
	CREATE_FUNC(MainMenuScene);
};
#endif // __MAINMENU_SCENE_H__