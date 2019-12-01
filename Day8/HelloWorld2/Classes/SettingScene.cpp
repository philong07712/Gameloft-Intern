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
cocos2d::Color3B blackColor;

// soundItems
bool soundMenu;
cocos2d::ui::CheckBox* checkBox;

// aboutItems
cocos2d::ui::ScrollView* scrollView;
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
	addChild(checkBox, 3);
	// create scrollView
	createAbout();
	addChild(scrollView, 3);
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
	auto textField = ui::TextField::create("Insert Name:", "Arial", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(20);
	textField->setColor(blackColor);
	textField->setPosition(Vec2(width, height + 200));
	addChild(textField, 3);
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
	auto aboutItem = MenuItemFont::create("About", 
		[&](Ref* pSender) {
		activeAbout();
	});
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

void SettingScene::createSound() {
	checkBox = ui::CheckBox::create("unselected_checkbox.png", "selected_checkbox.png");
	checkBox->setPosition(Vec2(width + 200, height));
	checkBox->setOpacity(0);
}

void SettingScene::createAbout() {
	scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(200, 200));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(width - 100, height - 300));
	// Add information about the game
	auto label = Label::createWithSystemFont("Game information", "Arial", 24);
	label->setPosition(Vec2(scrollView->getContentSize().width / 2, 50));
	label->setColor(blackColor);
	scrollView->addChild(label);
	scrollView->setOpacity(0);
}

void SettingScene::activeAbout() {
	if (aboutMenu == false) {
		scrollView->setOpacity(100);
		aboutMenu = true;
	}
	else {
		scrollView->setOpacity(0);
		aboutMenu = false;
	}
}
void SettingScene::update(float deltaTime)
{

}
