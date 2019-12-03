
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GamePlayScene.h"
USING_NS_CC;

// Global variable
cocos2d::Sprite* ship;

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
	addBackGround();
	addShip();
	// Add touch listener
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	
	auto listenerKeyBoard = EventListenerKeyboard::create();
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GamePlayScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, ship);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, ship);

    return true;
}

void GamePlayScene::addBackGround()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto backGround = Sprite::create("bg_for_game.png");
	backGround->setPosition(Vec2(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	backGround->setScale(1.5f);
	addChild(backGround);
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

	ship = Sprite::create();
	addChild(ship);
	ship->setPosition(200, 200);
	ship->runAction(RepeatForever::create(animate));
}
// Touch move
bool GamePlayScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto mousePos = touch->getLocation();
	auto moveTo = MoveTo::create(0.3f, mousePos);
	ship->runAction(moveTo);
	return true;
}

void GamePlayScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

void GamePlayScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}
//Keyboard move
void GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	auto moveUp = MoveBy::create(0.1f, Vec2(0, 30));
	auto moveRight = MoveBy::create(0.1f, Vec2(30, 0));
	switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_UP_ARROW :
		{
			auto repeatForever = RepeatForever::create(moveUp);
			repeatForever->setTag(1);
			event->getCurrentTarget()->runAction(repeatForever);
			break;
		}
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW :
		{
			auto repeatForever = RepeatForever::create(moveUp->reverse());
			repeatForever->setTag(2);
			event->getCurrentTarget()->runAction(repeatForever);
			break;
		}
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW :
		{
			auto repeatForever = RepeatForever::create(moveRight);
			repeatForever->setTag(3);
			event->getCurrentTarget()->runAction(repeatForever);
			break;
		}
		case  EventKeyboard::KeyCode::KEY_LEFT_ARROW :
		{
			auto repeatForever = RepeatForever::create(moveRight->reverse());
			repeatForever->setTag(4);
			event->getCurrentTarget()->runAction(repeatForever);
			break;
		}
		default:
			break;
	}
}

void GamePlayScene::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		ship->stopActionByTag(1);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		ship->stopActionByTag(2);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		ship->stopActionByTag(3);
		break;
	case  EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		ship->stopActionByTag(4);
		break;
	default:
		break;
	}
}

void GamePlayScene::update(float DeltaTime) {
}

