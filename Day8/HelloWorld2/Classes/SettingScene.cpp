# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
# include "MainMenuScene.h"
# include "SettingScene.h"
# include "SimpleAudioEngine.h"
Scene * SettingScene::createScene()
{
	return SettingScene::create();
}
// global variable
cocos2d::Vec2 originalSize;
float width;
float height;

// soundItems
LayerColor* layerSound;
// aboutItems
LayerColor* layerAbout;

bool SettingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	originalSize = Director::getInstance()->getVisibleOrigin();
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
		playConfirmAudio();
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
		playConfirmAudio();
		activeSound();
	});
	soundItem->setPosition(width - 150, height);
	// create aboutItem
	auto aboutLabel = Label::create("About", "fonts/MarkerFelt.ttf", 30);
	auto aboutItem = MenuItemLabel::create(aboutLabel, 
		[&](Ref* pSender) {
		playConfirmAudio();
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

void SettingScene::activeSound() 
{
	if (!layerSound->isVisible()) {
		layerSound->setVisible(true);
	}
	else {
		layerSound->setVisible(false);
	}
}

void SettingScene::createSound() {
	// Adding the layout
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	// create layerSound
	layerSound = LayerColor::create(Color4B(198, 153, 222, 255));
	auto size = layerSound->getContentSize();
	layerSound->setContentSize(Size(size.width, size.height - 200));
	layerSound->setVisible(false);
	layerSound->setPosition(0, 100);
	addChild(layerSound, 2);
	// create return button
	auto returnButton = ui::Button::create("Buttons/resume_normal.png", "Buttons/resume_pressed.png");
	layerSound->addChild(returnButton);
	returnButton->setPosition(Vec2(50, layerSound->getContentSize().height - 50));
	returnButton->setScale(0.5f);
	returnButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		layerSound->setVisible(false);
	});	
	// create labelSoundTitile
	auto labelSoundTitile = Label::create("SOUND", "fonts/MarkerFelt.ttf", 50);
	layerSound->addChild(labelSoundTitile);
	labelSoundTitile->enableGlow(Color4B::YELLOW);
	labelSoundTitile->enableShadow();
	labelSoundTitile->setPosition(Vec2(layerSound->getContentSize().width / 2, layerSound->getContentSize().height - 50));
	// create checkBoxMute and create labelMute
	auto checkBoxMute = ui::CheckBox::create("icons/checkbox_normal.png", "icons/checkbox_checked.png");
	layerSound->addChild(checkBoxMute);
	checkBoxMute->setPosition(Vec2(labelSoundTitile->getPosition().x - 50, labelSoundTitile->getPosition().y - 100));
	checkBoxMute->setScale(0.5f);

	auto labelMute = Label::create("Mute", "fonts/MarkerFelt.ttf", 25);
	layerSound->addChild(labelMute);
	labelMute->setPosition(Vec2(checkBoxMute->getPosition().x + 50, checkBoxMute->getPosition().y));
	// create checkBoxSound and create labelSound
	auto checkBoxSound = ui::CheckBox::create("icons/checkbox_normal.png", "icons/checkbox_checked.png");
	layerSound->addChild(checkBoxSound);
	checkBoxSound->setPosition(Vec2(checkBoxMute->getPosition().x, checkBoxMute->getPosition().y - 50));
	checkBoxSound->setScale(0.5f);

	auto  labelSound = Label::create("Sound", "fonts/MarkerFelt.ttf", 25);
	labelSound->setPosition(Vec2(checkBoxSound->getPosition().x + 50, checkBoxSound->getPosition().y));
	layerSound->addChild(labelSound);
	// create sliderVolume and labelVolume
	auto  labelVolume = Label::create("Volume", "fonts/MarkerFelt.ttf", 25);
	labelVolume->setPosition(Vec2(checkBoxSound->getPosition().x, checkBoxSound->getPosition().y - 100));
	layerSound->addChild(labelVolume);

	auto sliderVolume = ui::Slider::create();
	sliderVolume->loadBarTexture("slider_bar_bg.png");
	sliderVolume->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable.png");
	sliderVolume->loadProgressBarTexture("slider_bar_pressed.png");
	sliderVolume->setPercent(10);
	sliderVolume->setPosition(Vec2(labelVolume->getPosition().x + 50, labelVolume->getPosition().y - 50));
	// layerSound created
	layerSound->addChild(sliderVolume);

}

void SettingScene::createAbout() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	// init Layer
	layerAbout = LayerColor::create(Color4B(198, 153, 222, 255));
	auto size = layerAbout->getContentSize();
	layerAbout->setContentSize(Size(size.width, size.height - 200));
	layerAbout->setVisible(false);
	layerAbout->setPosition(0, 100);
	addChild(layerAbout, 2);
	// create return button
	auto returnButton = ui::Button::create("Buttons/resume_normal.png", "Buttons/resume_pressed.png");
	layerAbout->addChild(returnButton);
	returnButton->setPosition(Vec2(50, layerSound->getContentSize().height - 50));
	returnButton->setScale(0.5f);
	returnButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		layerAbout->setVisible(false);
	});
	// create labelAboutTitle
	auto labelAboutTitle = Label::create("ABOUT", "fonts/MarkerFelt.ttf", 50);
	layerAbout->addChild(labelAboutTitle);
	labelAboutTitle->enableGlow(Color4B::YELLOW);
	labelAboutTitle->enableShadow();
	labelAboutTitle->setPosition(Vec2(layerAbout->getContentSize().width / 2, layerAbout->getContentSize().height - 50));
	// create scrollView
	auto scrollView = ui::ScrollView::create();
	layerAbout->addChild(scrollView);
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setPosition(Vec2(50, 0));
	scrollView->setContentSize(Size(400, 400));
	scrollView->setBounceEnabled(true);
	// Add information about the game
	auto inSize = Vec2(scrollView->getContentSize().width / 2, scrollView->getContentSize().height / 2);
	auto label = Label::createWithSystemFont("Game information: ", "Arial", 20);
	label->setPosition(inSize);
	auto label1 = Label::createWithSystemFont("Author: Hung", "Arial", 20);
	label1->setPosition(Vec2(scrollView->getContentSize().width / 2, label->getPosition().y + 30));
	scrollView->addChild(label);
	scrollView->addChild(label1);
}

void SettingScene::playConfirmAudio()
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/confirm.wav", false,
		1.0f, 1.0f, 1.0f);
}

void SettingScene::activeAbout() {
	if (!layerAbout->isVisible()) {
		layerAbout->setVisible(true);
	}
	else {
		layerAbout->setVisible(false);
	}
}

void SettingScene::update(float deltaTime)
{

}
