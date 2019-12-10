#pragma
#include "SimpleAudioEngine.h"
#include "GamePlay2Scene.h"
# include "ResourceManager.h"
# include "GameOverScene.h"
# include "SpaceShooter.h"
# include "Bullet.h"
USING_NS_CC;
// Global variable

Scene* GamePlay2Scene::createScene()
{
    return GamePlay2Scene::create();
}

// on "init" you need to initialize your instance
bool GamePlay2Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	delayRock = 0;
	initPhysic();
	initShip();
	GenerateRock();
	addListener();
	scheduleUpdate();
    return true;
}

void GamePlay2Scene::addMap()
{
}

void GamePlay2Scene::update(float DeltaTime)
{
	delayRock += DeltaTime;
	moveRock(DeltaTime);
	m_spaceShip->Update(DeltaTime);
	m_spaceShip->Collision(this->m_rocks);
}

void GamePlay2Scene::updateMap()
{
}

void GamePlay2Scene::initPhysic()
{
	// make the red bounder around the sprite
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto centre = visibleSize / 2;

	// Make the bounding around the screen
	// Create an empty PhysicsBody with the size as the screen
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize);
	auto edgeNode = Node::create();
	edgeNode->setPosition(centre);
	addChild(edgeNode);
	edgeNode->setPhysicsBody(edgeBody);
}

void GamePlay2Scene::GenerateRock()
{
	ResourceManager::getInstance()->setScore(0);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	int size = 30;
	for (int i = 0; i < size; i++)
	{
		auto rock = new Rock(this);
		m_rocks.push_back(rock);
		addChild(rock->getSprite());
		rock->getSprite()->setPosition(90 + (i * (visibleSize.width - 180) / size), visibleSize.height + 300);
	}
}

void GamePlay2Scene::addListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlay2Scene::onTouchBegan, this);

	auto listenerKeyBoard = EventListenerKeyboard::create();
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GamePlay2Scene::onKeyPressed, this);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GamePlay2Scene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_spaceShip->getSprite());
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, m_spaceShip->getSprite());
}

void GamePlay2Scene::moveRock(float DeltaTime)
{
	// make the rock move
	int rockSize = this->m_rocks.size();
	int randomNumber = rand() % (rockSize + 1);
	auto moveBy = MoveBy::create(5.0f, Vec2(0, -1300));
	if (delayRock > 15 * DeltaTime)
	{
		for (int i = randomNumber; i < rockSize; i++)
		{
			auto rock = this->m_rocks[i]->getSprite();
			if (!rock->isVisible())
			{
				rock->runAction(moveBy->clone());
				rock->setVisible(true);
				i = rockSize + 10;
				delayRock = 0;
			}
		}
	}
	for (int i = 0; i < rockSize; i++)
	{
		this->m_rocks[i]->Update(DeltaTime);
	}

}

void GamePlay2Scene::initShip()
{
	m_spaceShip = new SpaceShooter(this);
	m_spaceShip->getSprite()->setPosition(Vec2(200, 200));
	auto shipBody = PhysicsBody::createBox(m_spaceShip->getSprite()->getContentSize());
	shipBody->setRotationEnable(false);
	shipBody->setGravityEnable(false);
	m_spaceShip->getSprite()->setPhysicsBody(shipBody);
	addChild(m_spaceShip->getSprite());
}

bool GamePlay2Scene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto mousePos = touch->getLocation();
	auto moveTo = MoveTo::create(0.3f, mousePos);
	m_spaceShip->getSprite()->runAction(moveTo);
	return true;
}

//move the keyboard and the ship move follow
void GamePlay2Scene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	auto moveUp = MoveBy::create(0.1f, Vec2(0, 30));
	auto moveRight = MoveBy::create(0.1f, Vec2(30, 0));
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		auto repeatForever = RepeatForever::create(moveUp);
		repeatForever->setTag(1);
		event->getCurrentTarget()->runAction(repeatForever);
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		auto repeatForever = RepeatForever::create(moveUp->reverse());
		repeatForever->setTag(2);
		event->getCurrentTarget()->runAction(repeatForever);
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		auto repeatForever = RepeatForever::create(moveRight);
		repeatForever->setTag(3);
		event->getCurrentTarget()->runAction(repeatForever);
		break;
	}
	case  EventKeyboard::KeyCode::KEY_LEFT_ARROW:
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

void GamePlay2Scene::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_spaceShip->getSprite()->stopActionByTag(1);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_spaceShip->getSprite()->stopActionByTag(2);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_spaceShip->getSprite()->stopActionByTag(3);
		break;
	case  EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_spaceShip->getSprite()->stopActionByTag(4);
		break;
	default:
		break;
	}
}