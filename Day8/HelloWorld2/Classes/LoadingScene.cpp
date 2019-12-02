# include "LoadingScene.h"
# include "HelloWorldScene.h"
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
	// Add background
	background();
	addLoading();
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Robot1.plist", "Robot1.png");
	auto player = Sprite::create();
	player->setPosition(100, 200);
	addChild(player);
	Vector<SpriteFrame*> animFrames; 
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk0.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk1.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk2.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk3.png"));
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto scaleBy = ScaleBy::create(2.0f, 2.0f);
	auto moveBy = MoveBy::create(2.0f, Vec2(300, 0));
	player->runAction(RepeatForever::create(animate));
	auto scale = Sequence::create(scaleBy, scaleBy->reverse(), nullptr);
	auto move = Sequence::create(moveBy, moveBy->reverse(), nullptr);
	auto spawn = Spawn::create(scale, move, nullptr);
	player->runAction(RepeatForever::create(spawn));
	return true;
}

void LoadingScene::background() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("backgroundColorForest.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(backgroundSprite);
}

void LoadingScene::addLoading()
{
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("loading.plist", "loading.png");
	auto loading = Sprite::create();
	Vector<SpriteFrame*> spriteFrames;
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-0.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-1.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-2.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-3.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-4.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-5.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-6.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-7.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-8.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-9.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-10.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-11.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-12.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-13.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-14.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-15.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-16.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-17.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-18.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-19.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-20.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-21.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-22.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-23.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-24.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-25.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-26.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-27.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-28.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-29.png"));
	spriteFrames.pushBack(spriteCache->getSpriteFrameByName("frame-30.png"));
	auto animation = Animation::createWithSpriteFrames(spriteFrames, 0.025f);
	auto animate = Animate::create(animation);
	loading->runAction(RepeatForever::create(animate));
	loading->setPosition(400, 400);
	addChild(loading);
}

void LoadingScene::update(float deltaTime)
{
}
