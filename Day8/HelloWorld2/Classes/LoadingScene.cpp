# include "LoadingScene.h"
# include "HelloWorldScene.h"
Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	return true;
}

void LoadingScene::update(float deltaTime)
{
}
