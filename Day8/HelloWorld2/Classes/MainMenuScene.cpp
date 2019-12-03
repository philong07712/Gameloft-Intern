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
	auto playLabel = Label::create("PLAY", "fonts/MarkerFelt.ttf", 25);
	auto itemPlay = MenuItemLabel::create(playLabel,
		[&](Ref* pSender) {
		auto myScene = LogoScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, myScene));
	});
	itemPlay->setPosition(width, height);
	// create itemExit
	auto exitLabel = Label::create("EXIT", "fonts/MarkerFelt.ttf", 25);
	auto itemExit = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemExit->setPosition(width, height - 100);
	// create settingButton
	auto settingLabel = Label::create("SETTING", "fonts/MarkerFelt.ttf", 25);
	auto itemSetting = MenuItemLabel::create(settingLabel, CC_CALLBACK_1(MainMenuScene::changeSetting, this));
	itemSetting->setPosition(width, height - 50);
	// create closeButton
	auto closeButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeButton->setPosition(width, height - 200);
	// create settingButton
	auto settingButton = MenuItemImage::create("setting_normal.png", "setting_pressed.png", CC_CALLBACK_1(MainMenuScene::changeSetting, this));
	settingButton->setPosition(width - 100, height - 50);
	// create Menu
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemPlay);
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

void MainMenuScene::update(float deltaTime)
{

}
