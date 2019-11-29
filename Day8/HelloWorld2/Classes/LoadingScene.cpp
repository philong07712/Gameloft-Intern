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
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Robot1.plist", "Robot1.png");
	auto player = Sprite::create();
	player->setPosition(100, 100);
	addChild(player);
	Vector<SpriteFrame*> animFrames; 
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk0.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk1.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk2.png"));
	animFrames.pushBack(spriteCache->getSpriteFrameByName("character_robot_walk3.png"));
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	player->runAction(RepeatForever::create(animate));
	return true;
}

void LoadingScene::update(float deltaTime)
{
}
