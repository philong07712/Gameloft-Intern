
#pragma once
#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__
#include "ui/CocosGUI.h"
#include "cocos2d.h"

USING_NS_CC;

class SettingScene : public Scene {
public:
	static Scene* createScene();
	virtual bool init(); 
	void update(float deltaTime);
	void addBackground();
	void addMenu();
	void activeSound();
	CREATE_FUNC(SettingScene);
};
#endif // __SETTING_SCENE_H__