# include "GameOverScene.h"
# include "MainMenuScene.h"
# include "GamePlayScene.h"
#include "ResourceManager.h"
Scene * GameOverScene::createScene()
{
	return GameOverScene::create();
}


bool GameOverScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}

	scheduleUpdate();
	addBackground();
	addMenu();
	return true;
}

void GameOverScene::update(float deltaTime)
{
}

void GameOverScene::addBackground()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto bgImage = ResourceManager::getInstance()->GetSpriteById(0);
	auto background = Sprite::createWithSpriteFrame(bgImage->getSpriteFrame());
	background->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(background, -1);
	background->setScale(1.5f);
}

void GameOverScene::addMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto label = Label::create("GAME OVER", "fonts/MarkerFelt.ttf", 50);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 200);
	// Return to mainMenu Button
	auto homeButton = ui::Button::create("icons/home_normal.png", "icons/home_pressed.png");
	addChild(homeButton);
	// 
	homeButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		auto myScene = MainMenuScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, myScene));
	});	
	homeButton->setPosition(Size(visibleSize.width / 2 + 100, visibleSize.height / 2 - 100));
	homeButton->setScale(1.5f);
	// PlayAgain
	auto playAgainButton = ui::Button::create("Buttons/resume_normal.png", "Buttons/resume_pressed.png");
	addChild(playAgainButton);
	// 
	playAgainButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		auto myScene = GamePlayScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, myScene));
	});
	playAgainButton->setPosition(Size(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
}
