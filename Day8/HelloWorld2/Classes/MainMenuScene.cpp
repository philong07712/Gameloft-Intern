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
	logo->setPosition(Vec2(width, height + 200));
	addChild(logo);
	// create itemPlay
	auto playLabel = Label::create("PLAY", "fonts/MarkerFelt.ttf", 40);
	auto itemPlay = MenuItemLabel::create(playLabel, CC_CALLBACK_1(MainMenuScene::changePlay, this));
	itemPlay->setPosition(width, height);
	// create playButton
	auto playButton = MenuItemImage::create("icons/play_normal.png", "icons/play_pressed.png", CC_CALLBACK_1(MainMenuScene::changePlay, this));
	playButton->setPosition(itemPlay->getPosition().x - 125, itemPlay->getPosition().y);
	playButton->setScale(0.5f);
	// create settingButton
	auto settingLabel = Label::create("SETTING", "fonts/MarkerFelt.ttf", 40);
	auto itemSetting = MenuItemLabel::create(settingLabel, CC_CALLBACK_1(MainMenuScene::changeSetting, this));
	itemSetting->setPosition(itemPlay->getPosition().x, itemPlay->getPosition().y - 100);
	// create settingButton
	auto settingButton = MenuItemImage::create("setting_normal.png", "setting_pressed.png", CC_CALLBACK_1(MainMenuScene::changeSetting, this));
	settingButton->setPosition(itemSetting->getPosition().x - 125, itemSetting->getPosition().y);
	// create itemExit
	auto exitLabel = Label::create("EXIT", "fonts/MarkerFelt.ttf", 40);
	auto itemExit = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemExit->setPosition(itemSetting->getPosition().x, itemSetting->getPosition().y - 100);
	// create closeButton
	auto closeButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeButton->setPosition(itemExit->getPosition().x - 125, itemExit->getPosition().y);
	closeButton->setScale(1.75f);
	// create Menu
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemPlay);
	menuItems.pushBack(playButton);
	menuItems.pushBack(itemExit);
	menuItems.pushBack(closeButton);
	menuItems.pushBack(itemSetting);
	menuItems.pushBack(settingButton);
	auto myMenu = Menu::createWithArray(menuItems);
	myMenu->setPosition(0, 0);
	addChild(myMenu, 2);
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
	auto myScene = LogoScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, myScene));
}
void MainMenuScene::update(float deltaTime)
{

}
