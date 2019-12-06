
#pragma once
#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "SettingScene.h"
USING_NS_CC;

class GameOverScene : public Scene {
public:
	static Scene* createScene();
	virtual bool init(); 
	void update(float deltaTime);
	void addBackground();
	void addMenu();
	CREATE_FUNC(GameOverScene);
};
#endif // __GAMEOVER_SCENE_H__