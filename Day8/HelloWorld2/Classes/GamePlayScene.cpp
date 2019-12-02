
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GamePlayScene.h"
USING_NS_CC;

Scene* GamePlayScene::createScene()
{
    return GamePlayScene::create();
}

// on "init" you need to initialize your instance
bool GamePlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	scheduleUpdate();
	addShip();
    return true;
}
// Add the ship to the gameplay
void GamePlayScene::addShip()
{
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("ship.plist", "ship.png");
	Vector<SpriteFrame*> shipFrames;
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("1.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("2.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("3.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("4.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("5.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("6.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("7.png"));
	shipFrames.pushBack(spriteCache->getSpriteFrameByName("8.png"));
	auto animation = Animation::createWithSpriteFrames(shipFrames, 0.1f);
	auto animate = Animate::create(animation);

	auto ship = Sprite::create();
	addChild(ship);
	ship->setPosition(200, 200);
	ship->runAction(RepeatForever::create(animate));
}

void GamePlayScene::update(float DeltaTime) {

}