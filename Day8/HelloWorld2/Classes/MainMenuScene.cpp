# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
# include "MainMenuScene.h"
# include "GamePlayScene.h"
# include "SimpleAudioEngine.h"
using namespace CocosDenshion;
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
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Sounds/title.mp3", true);
	addMenu();
	return true;
}

void MainMenuScene::addBackground() {
	auto backgroundSprite = Sprite::create("background.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, -1);
}

void MainMenuScene::addMenu()
{
	// Get Size
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto width = visibleSize.width / 2 + originSize.x;
	auto height = visibleSize.height / 2 + originSize.y;
	// addLogo
	auto logo = Sprite::create("logo.png");
	logo->setPosition(Vec2(width, height + 150));
	addChild(logo);
	// create itemPlay
	// create playButton
	auto playButton = MenuItemImage::create("icons/play_normal.png", "icons/play_pressed.png", CC_CALLBACK_1(MainMenuScene::changePlay, this));
	playButton->setPosition(width, height - 75);
	// create settingButton
	auto settingButton = MenuItemImage::create("setting_normal.png", "setting_pressed.png", CC_CALLBACK_1(MainMenuScene::changeSetting, this));
	settingButton->setPosition(width * 2 - 75, height - 300);
	// create closeButton
	auto closeButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeButton->setPosition(width, height - 300);
	// create Menu
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(playButton);
	menuItems.pushBack(closeButton);
	menuItems.pushBack(settingButton);
	auto myMenu = Menu::createWithArray(menuItems);
	myMenu->setPosition(0, 0);
	addChild(myMenu);
}

void MainMenuScene::menuCloseCallback(Ref* pSender) {
	exit(0);
}

void MainMenuScene::changeSetting(Ref* pSender)
{
	auto myScene = SettingScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, myScene));
}

void MainMenuScene::changePlay(Ref* pSender)
{
	auto myScene = GamePlayScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, myScene));
}
void MainMenuScene::update(float deltaTime)
{

}
