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
void LoadingScene::update(float deltaTime)
{
}
