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
	addChild(backgroundSprite, 1);
}

void MainMenuScene::addMenu()
{
	// Get Size
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto width = visibleSize.width / 2 + originSize.x;
	auto height = visibleSize.height / 2 + originSize.y;
	// add slide action
	auto femaleSlide = Sprite::create("adventure_slide.png");
	femaleSlide->setPosition(200, height + 200);
	auto moveBy = MoveBy::create(1.5f, Vec2(600, 0));
	auto sequenceSlide = Sequence::create(moveBy, moveBy->reverse(), nullptr);
	femaleSlide->runAction(RepeatForever::create(sequenceSlide));
	addChild(femaleSlide, 3);
	// add fall action
	auto maleFall = Sprite::create("adventure_fall.png");
	maleFall->setPosition(width + 200, height + 200);
	auto moveByFall = MoveBy::create(1.5f, Vec2(0, -500));
	auto sequenceFall = Sequence::create(moveByFall, moveByFall->reverse(), nullptr);
	maleFall->runAction(RepeatForever::create(sequenceFall));
	addChild(maleFall, 3);
	// Init color variable
	// create Menu label
	auto label = Label::create("MENU", "fonts/MarkerFelt.ttf", 50);
	auto endItem = MenuItemLabel::create(label, nullptr);
	endItem->setPosition(width, height + 100);
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
	auto itemSetting = MenuItemLabel::create(settingLabel,
		[&](Ref* pSender) {
		auto myScene = SettingScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, myScene));
	});
	itemSetting->setPosition(width, height - 50);
	// create closeButton
	auto closeButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	closeButton->setPosition(width, height - 200);
	// create settingButton
	auto settingButton = MenuItemImage::create("setting_normal.png", "setting_pressed.png");
	settingButton->setPosition(width - 100, height - 50);
	// create Menu
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(endItem);
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

void MainMenuScene::update(float deltaTime)
{

}
