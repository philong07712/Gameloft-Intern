# include "LogoScene.h"

Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	return true;
}

void LogoScene::update(float deltaTime)
{
}
