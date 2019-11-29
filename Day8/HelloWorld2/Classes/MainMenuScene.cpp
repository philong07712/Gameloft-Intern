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
	auto button = ui::Button::create("normal_button.png", "selected_button.png", "disable_button.png");
	button->setPosition(Vec2(200, 200));
	addChild(button);
	return true;
}

void MainMenuScene::update(float deltaTime)
{

}
