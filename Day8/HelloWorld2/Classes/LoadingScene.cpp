# include "LoadingScene.h"
# include "HelloWorldScene.h"
# include "GamePlayScene.h"
Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	addLoading();
	// Change to GamePlayScene
	this->schedule(schedule_selector(LoadingScene::changeGamePlay), 3.0f);
	return true;
}

void LoadingScene::changeGamePlay(float dt)
{
	auto myScene = GamePlayScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(2.0f, myScene));
}

void LoadingScene::background() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("background.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite, -1);
}

void LoadingScene::addLoading()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();

	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Loading/loading1.plist", "Loading/loading1.png");
	auto loading = Sprite::create();
	loading->setPosition(Vec2(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(loading);
	Vector<SpriteFrame*> spriteFrames;
	int maxFrame = 36;
	const auto maxChar = 35;
	char frameName[maxChar] = { 0 };
	for (int i = 0; i <= maxFrame; i++) {
		sprintf(frameName, "frame_%d.png", i);
		spriteFrames.pushBack(spriteCache->getSpriteFrameByName(frameName));
	}
	auto animation = Animation::createWithSpriteFrames(spriteFrames,0.15f);
	auto animate = Animate::create(animation);
	loading->runAction(RepeatForever::create(animate));
}

void LoadingScene::update(float deltaTime)
{
}
