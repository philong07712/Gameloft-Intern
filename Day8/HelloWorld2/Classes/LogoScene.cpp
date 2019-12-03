# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
#include "MainMenuScene.h"
// Global variable
cocos2d::Size visibleSize;
cocos2d::Vec2 originSize;

Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	visibleSize = Director::getInstance()->getVisibleSize();
	originSize = Director::getInstance()->getVisibleOrigin();
	addLogo();
	addBackground();
	this->schedule(schedule_selector(LogoScene::changeLoading), 3.0f);
	return true;
}

void LogoScene::update(float deltaTime)
{
}

void LogoScene::addBackground() {
	auto background = Sprite::create("bg_for_game.png");
	background->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(background, -1);
	background->setScale(1.5f);
}


void LogoScene::changeLoading(float dt) {
	auto myScene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(
		TransitionFade::create(0.5, myScene));
}

void LogoScene::addLogo()
{
	auto logo = Sprite::create("logo__.png");
	logo->setPosition(Vec2(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y + 200));
	addChild(logo);
	auto move = MoveBy::create(1.5f, Vec2(0, -300));
	auto move_ease_in = EaseBounceIn::create(move->clone());
	auto move_ease_back = move_ease_in->reverse();
	auto sequence = Sequence::create(move_ease_in, move_ease_back, nullptr);
	logo->runAction(RepeatForever::create(sequence));
}

void LogoScene::changeScene() {
	auto myScene = HelloWorld::createScene();
	// Transition Fade
	int random = rand() % 5;
	switch (random)
	{
	case 0:
		Director::getInstance()->replaceScene(
			TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));
		break;
	case 1:
		Director::getInstance()->replaceScene(TransitionFlipX::create(2, myScene));
		break;
	case 2:
		Director::getInstance()->replaceScene(TransitionMoveInR::create(2, myScene));
		break;
	case 3:
		Director::getInstance()->replaceScene(TransitionFlipAngular::create(2, myScene));
		break;
	case 4:
		Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, myScene));
		break;
	default:
		Director::getInstance()->replaceScene(TransitionFlipY::create(2, myScene));
		break;
	}
}