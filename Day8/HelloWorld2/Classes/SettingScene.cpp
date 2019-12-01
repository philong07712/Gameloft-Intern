# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
# include "MainMenuScene.h"
# include "SettingScene.h"
Scene * SettingScene::createScene()
{
	return SettingScene::create();
}
// global variable
cocos2d::Vec2 originalSize;
float width;
float height;
bool soundMenu;

// soundItem
cocos2d::ui::CheckBox* checkBox;

bool SettingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	originalSize = Director::getInstance()->getVisibleOrigin();
	soundMenu = false;
	width = Director::getInstance()->getVisibleSize().width / 2 + originalSize.x;
	height = Director::getInstance()->getVisibleSize().height / 2 + originalSize.y;
	// create soundItem
	checkBox = ui::CheckBox::create("unselected_checkbox.png", "selected_checkbox.png");
	checkBox->setPosition(Vec2(width + 200, height));
	checkBox->setOpacity(0);
	addChild(checkBox, 3);
	// add background
	addBackground();
	SettingScene::addMenu();
	return true;
}

void SettingScene::addBackground() {
	auto backgroundSprite = Sprite::create("backgroundColorDesert.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, 1);
}

void SettingScene::addMenu()
{
	auto blackColor = cocos2d::Color3B(10, 10, 10);
	// create settingFont
	auto label = Label::create("SETTING", "Arial", 30);
	auto settingLabel = MenuItemLabel::create(label, nullptr);
	settingLabel->setPosition(width, height + 100);
	settingLabel->setColor(blackColor);
	// create soundItem
	auto soundItem = MenuItemFont::create("Sound", 
		[&](Ref* pSender) {
		activeSound();
	});
	soundItem->setPosition(width, height);
	soundItem->setColor(blackColor);
	// create aboutItem
	auto aboutItem = MenuItemFont::create("About", nullptr);
	aboutItem->setPosition(width, height - 50);
	aboutItem->setColor(blackColor);
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(settingLabel);
	menuItems.pushBack(soundItem);
	menuItems.pushBack(aboutItem);
	// Add menu
	auto menu = Menu::createWithArray(menuItems);
	menu->setPosition(0, 0);
	addChild(menu, 2);
}

void SettingScene::activeSound() {
	if (soundMenu == false) {
		checkBox->setOpacity(100);
		soundMenu = true;
	}
	else {
		checkBox->setOpacity(0);
		soundMenu = false;
	}
}



void SettingScene::update(float deltaTime)
{

}
