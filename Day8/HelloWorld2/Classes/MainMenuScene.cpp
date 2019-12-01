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
	auto backgroundSprite = Sprite::create("backgroundCastles.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, 1);
}

void MainMenuScene::addMenu()
{
	// Get Size
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto width = visibleSize.width / 2 + originSize.x;
	auto height = visibleSize.height / 2 + originSize.y;
	// Init color variable
	auto colorBlack = cocos2d::Color3B(10, 10, 10);
	// create Menu label
	auto label = Label::create("MENU", "Arial", 30);
	auto endItem = MenuItemLabel::create(label, nullptr);
	endItem->setPosition(width, height + 100);
	endItem->setColor(colorBlack);
	// create itemPlay
	auto itemPlay = MenuItemFont::create("Play", 
		[&](Ref* pSender) {
		auto mySence = SettingScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, mySence));
	});
	itemPlay->setPosition(width, height);
	itemPlay->setColor(colorBlack);
	// create itemExit
	auto itemExit = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemExit->setPosition(width, height - 50);
	itemExit->setColor(colorBlack);
	// create closeButton
	auto closeButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeButton->setPosition(width, height - 100);
	// create settingButton
	auto settingButton = MenuItemImage::create("normal_button_small.png", "selected_button_small.png");
	settingButton->setPosition(width, height + 250);
	// create Menu
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(endItem);
	menuItems.pushBack(itemPlay);
	menuItems.pushBack(itemExit);
	menuItems.pushBack(closeButton);
	menuItems.pushBack(settingButton);
	auto myMenu = Menu::createWithArray(menuItems);
	myMenu->setPosition(0, 0);
	addChild(myMenu, 2);
}

void MainMenuScene::menuCloseCallback(Ref* pSender) {
	exit(0);
}

void MainMenuScene::update(float deltaTime)
{

}
