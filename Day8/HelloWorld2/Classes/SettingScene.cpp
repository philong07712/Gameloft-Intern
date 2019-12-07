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

// soundItems
bool soundMenu;
LayerColor* layerSound;
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
	auto backgroundSprite = Sprite::create("background.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, -1);
}

void SettingScene::addMenu()
{
	// add returnItem
	auto returnButton = ui::Button::create("icons/home_normal.png", "icons/home_pressed.png");
	//auto returnLabel = Label::create("RETURN", "fonts/MarkerFelt.ttf", 24);
	//returnButton->setTitleLabel(returnLabel);
	returnButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		auto myScene = MainMenuScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, myScene));
	});
	returnButton->setPosition(Vec2(50, height * 2 - 50));
	addChild(returnButton);
	// Add textField
	auto textField = ui::TextField::create("Insert Name:", "fonts/MarkerFelt.ttf", 30);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(20);
	textField->setPosition(Vec2(width, height + 200));
	addChild(textField);
	// create settingFont
	auto label = Label::create("SETTING", "fonts/MarkerFelt.ttf", 50);
	label->enableGlow(Color4B::YELLOW);
	label->enableShadow();
	auto settingLabel = MenuItemLabel::create(label, nullptr);
	settingLabel->setPosition(width, height + 300);
	// create soundItem
	auto soundLabel = Label::create("Sound", "fonts/MarkerFelt.ttf", 30);
	auto soundItem = MenuItemLabel::create(soundLabel,
		[&](Ref* pSender) {
		activeSound();
	});
	soundItem->setPosition(width - 150, height);
	// create aboutItem
	auto aboutLabel = Label::create("About", "fonts/MarkerFelt.ttf", 30);
	auto aboutItem = MenuItemLabel::create(aboutLabel, 
		[&](Ref* pSender) {
		activeAbout();
	});
	aboutItem->setPosition(width - 150, height - 100);

	Vector<MenuItem*> menuItems;
	menuItems.pushBack(settingLabel);
	menuItems.pushBack(soundItem);
	menuItems.pushBack(aboutItem);
	// Add menu
	auto menu = Menu::createWithArray(menuItems);
	menu->setPosition(0, 0);
	addChild(menu);
}

void SettingScene::activeSound() {

	if (!layerSound->isVisible()) {
		layerSound->setVisible(true);
	}
	else {
		layerSound->setVisible(false);
	}
}

void SettingScene::createSound() {
	//auto soundLayout = ui::Layout::create();
	//soundLayout->setPosition(Vec2(width - 100, height));
	//soundLayout->setContentSize(Size(200, 50));
	//soundLayout->setAnchorPoint(Vec2(0, 1));
	// create checkBox
	auto checkBox = ui::CheckBox::create("icons/checkbox_normal.png", "icons/checkbox_checked.png");
	checkBox->setPosition(Vec2(250, 50));
	// create slider
	auto slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(100, 50));
	//soundLayout->addChild(slider, 1);
	//soundLayout->addChild(checkBox, 1);
	// Adding the layout
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	// layerSound created
	layerSound = LayerColor::create(Color4B(0, 204, 102, 255));
	//layerSound->addChild(soundLayout);
	layerSound->addChild(slider);
	layerSound->addChild(checkBox);
	auto size = layerSound->getContentSize();
	layerSound->setContentSize(Size(size.width, size.height - 200));
	layerSound->setVisible(false);
	layerSound->setPosition(0, 100);
	addChild(layerSound, 2);

	auto labelSound = Label::create("SOUND", "fonts/MarkerFelt.ttf", 40);
	labelSound->enableGlow(Color4B::YELLOW);
	labelSound->enableShadow();
	layerSound->addChild(labelSound);
	labelSound->setPosition(size.width / 2, size.height / 2 + 100);

}

void SettingScene::createAbout() {
	// init aboutLayout
	aboutLayout = ui::Layout::create();
	aboutLayout->setVisible(false);
	aboutLayout->setContentSize(Size(500, 300));
	aboutLayout->setPosition(Vec2(width - 100, height + 50));
	aboutLayout->setAnchorPoint(Vec2(0, 1));

	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(200, 200));
	scrollView->setBounceEnabled(true);
	// Add information about the game
	auto inSize = Vec2(scrollView->getContentSize().width / 2, 50);
	auto label = Label::createWithSystemFont("Game information: ", "Arial", 15);
	label->setPosition(inSize);
	auto label1 = Label::createWithSystemFont("Author: Hung", "Arial", 15);
	label1->setPosition(Vec2(scrollView->getContentSize().width / 2, 50 + 30));
	scrollView->addChild(label);
	scrollView->addChild(label1);
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
