# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
# include "MainMenuScene.h"
# include "SettingScene.h"
Scene * SettingScene::createScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	addBackground();
	return true;
}

void SettingScene::addBackground() {
	auto backgroundSprite = Sprite::create("backgroundCastles.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, 1);
}


void SettingScene::update(float deltaTime)
{

}
