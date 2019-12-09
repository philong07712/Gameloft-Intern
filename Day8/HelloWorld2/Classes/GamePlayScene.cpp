
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GamePlayScene.h"
#include "SpaceShooter.h"
# include "ResourceManager.h"
# include "GameOverScene.h"
USING_NS_CC;

// Global variable

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
	addBackGround();
	addAudio();
	scheduleUpdate();
	addShip();
	GenerateRock();
	// Add touch listener
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	
	auto listenerKeyBoard = EventListenerKeyboard::create();
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GamePlayScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_spaceShip->getSprite());
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, m_spaceShip->getSprite());

    return true;
}

void GamePlayScene::addBackGround()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	auto backGround = Sprite::create("bg_for_game.png");
	backGround->setPosition(Vec2(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	backGround->setScale(1.5f);
	addChild(backGround, -1);
}

// Add the m_spaceShip to the gameplay
void GamePlayScene::addShip()
{
	m_spaceShip = new SpaceShooter(this);
}

void GamePlayScene::GenerateRock()
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
// Touch move
bool GamePlayScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto mousePos = touch->getLocation();
	auto moveTo = MoveTo::create(0.3f, mousePos);
	m_spaceShip->getSprite()->runAction(moveTo);
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

float a = 0;
void GamePlayScene::update(float DeltaTime) 
{
	if (ResourceManager::getInstance()->getScore() >= 10 && maps.empty())
	{
		addMap();
	}
	if (!maps.empty())
	{
		updateMap();
	}
	a += DeltaTime;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	m_spaceShip->Update(DeltaTime);

	// make the rock move
	int rockSize = this->m_rocks.size();
	int randomNumber = rand() % (rockSize + 1);
	auto moveBy = MoveBy::create(5.0f, Vec2(0, -1300));
	if (a > 15 * DeltaTime)
	{
		for (int i = randomNumber; i < rockSize; i++)
		{
			auto rock = this->m_rocks[i]->getSprite();
			if (!rock->isVisible())
			{
				rock->runAction(moveBy->clone());
				rock->setVisible(true);
				i = rockSize + 10;
				a = 0;
			}
		}
	}
	for (int i = 0; i < rockSize; i++)
	{
		this->m_rocks[i]->Update(DeltaTime);
	}
	
	m_spaceShip->Collision(m_rocks);
	if (!m_spaceShip->getSprite()->isVisible())
	{
		stopAudio();
		auto myScene = GameOverScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.0f, myScene));
	}
}

void GamePlayScene::addAudio()
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying()) {
		audio->playBackgroundMusic("Sounds/ingame.mp3", true);
	}
	else
	{
		audio->resumeBackgroundMusic();
	}
}

void GamePlayScene::stopAudio()
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->pauseBackgroundMusic();
}

void GamePlayScene::addMap()
{
	auto map = TMXTiledMap::create("TileMaps/bg.tmx");
	maps.push_back(map);
	map = TMXTiledMap::create("TileMaps/bg.tmx");
	maps.push_back(map);
	maps[0]->setPosition(Vec2(0, Director::getInstance()->getVisibleSize().height));
	maps[1]->setPosition(Vec2(0, maps[0]->getPosition().y + (maps[0]->getContentSize().height)));
	addChild(maps[0], -1);
	addChild(maps[1], -1);
	auto moveBy = MoveBy::create(10.0f, Vec2(0, -1500));
	maps[0]->runAction(RepeatForever::create(moveBy));
	maps[1]->runAction(RepeatForever::create(moveBy->clone()));
}

void GamePlayScene::updateMap()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i < 2; i++)
	{
		if (maps[i]->getPosition().y < -((maps[i]->getContentSize().height)))
		{
			maps[i]->setPosition(Vec2(0, 1 * (maps[i]->getContentSize().height)));
		}
	}
}
