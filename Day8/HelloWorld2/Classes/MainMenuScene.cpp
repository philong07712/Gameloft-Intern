# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
# include "MainMenuScene.h"

Scene * MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	addBackground();
	auto button = ui::Button::create("normal_button.png", "selected_button.png", "disable_button.png");
	button->setPosition(Vec2(200, 200));
	addChild(button, 2);
	return true;
}

void MainMenuScene::addBackground() {
	auto backgroundSprite = Sprite::create("backgroundCastles.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, 1);
}
void MainMenuScene::update(float deltaTime)
{

}
