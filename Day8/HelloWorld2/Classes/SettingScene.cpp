﻿# include "LogoScene.h"
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
cocos2d::Color3B blackColor;

// soundItems
bool soundMenu;
cocos2d::ui::Layout* soundLayout;

// aboutItems
cocos2d::ui::Layout* aboutLayout;
bool aboutMenu;

bool SettingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	blackColor = cocos2d::Color3B(10, 10, 10);
	originalSize = Director::getInstance()->getVisibleOrigin();
	soundMenu = false;
	aboutMenu = false;
	width = Director::getInstance()->getVisibleSize().width / 2 + originalSize.x;
	height = Director::getInstance()->getVisibleSize().height / 2 + originalSize.y;
	// create soundItem
	createSound();
	// create scrollView
	createAbout();
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
	// Add textField
	auto textField = ui::TextField::create("Insert Name:", "fonts/MarkerFelt.ttf", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(20);
	textField->setColor(blackColor);
	textField->setPosition(Vec2(width, height + 200));
	addChild(textField, 3);
	// create settingFont
	auto label = Label::create("SETTING", "fonts/MarkerFelt.ttf", 50);
	label->enableGlow(Color4B::YELLOW);
	label->enableShadow();
	auto settingLabel = MenuItemLabel::create(label, nullptr);
	settingLabel->setPosition(width, height + 300);
	settingLabel->setColor(blackColor);
	// create soundItem
	auto soundLabel = Label::create("Sound", "fonts/MarkerFelt.ttf", 30);
	auto soundItem = MenuItemLabel::create(soundLabel,
		[&](Ref* pSender) {
		activeSound();
	});
	soundItem->setPosition(width - 300, height);
	soundItem->setColor(blackColor);
	// create aboutItem
	auto aboutLabel = Label::create("About", "fonts/MarkerFelt.ttf", 30);
	auto aboutItem = MenuItemLabel::create(aboutLabel, 
		[&](Ref* pSender) {
		activeAbout();
	});
	aboutItem->setPosition(width - 300, height - 200);
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
		soundLayout->setVisible(true);
		soundMenu = true;
	}
	else {
		soundLayout->setVisible(false);
		soundMenu = false;
	}
}

void SettingScene::createSound() {
	soundLayout = ui::Layout::create();
	soundLayout->setPosition(Vec2(width - 100, height));
	soundLayout->setContentSize(Size(200, 50));
	soundLayout->setAnchorPoint(Vec2(0, 1));
	// create checkBox
	auto checkBox = ui::CheckBox::create("unselected_checkbox.png", "selected_checkbox.png");
	checkBox->setPosition(Vec2(300, 50));
	// create slider
	auto slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(100, 50));
	soundLayout->addChild(slider, 1);
	soundLayout->addChild(checkBox, 1);
	soundLayout->setVisible(false);
	addChild(soundLayout, 3);
}

void SettingScene::createAbout() {
	// init aboutLayout
	aboutLayout = ui::Layout::create();
	aboutLayout->setVisible(false);
	aboutLayout->setContentSize(Size(300, 300));
	aboutLayout->setPosition(Vec2(width - 100, height + 50));
	aboutLayout->setAnchorPoint(Vec2(0, 1));

	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(200, 200));
	scrollView->setBounceEnabled(true);
	// Add information about the game
	auto label = Label::createWithSystemFont("Game information", "Arial", 24);
	label->setPosition(Vec2(scrollView->getContentSize().width / 2, 50));
	label->setColor(blackColor);
	scrollView->addChild(label);
	aboutLayout->addChild(scrollView);
	addChild(aboutLayout, 3);
}

void SettingScene::activeAbout() {
	if (aboutMenu == false) {
		aboutLayout->setVisible(true);
		aboutMenu = true;
	}
	else {
		aboutLayout->setVisible(false);
		aboutMenu = false;
	}
}
void SettingScene::update(float deltaTime)
{

}