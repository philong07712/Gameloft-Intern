
#include "SimpleAudioEngine.h"
#include "GamePlay2Scene.h"
# include "ResourceManager.h"
# include "GameOverScene.h"
USING_NS_CC;

// Global variable
std::vector <TMXTiledMap*> maps;

Scene* GamePlay2Sene::createScene()
{
    return GamePlay2Sene::create();
}

// on "init" you need to initialize your instance
bool GamePlay2Sene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	addMap();
	scheduleUpdate();
    return true;
}

void GamePlay2Sene::addMap()
{
	auto map = TMXTiledMap::create("TileMaps/bg.tmx");
	maps.push_back(map);
	map = TMXTiledMap::create("TileMaps/bg.tmx");
	maps.push_back(map);
	maps[0]->setPosition(Vec2(0, 0));
	maps[1]->setPosition(Vec2(0, (maps[0]->getContentSize().height)));
	addChild(maps[0], -1);
	addChild(maps[1], -1);

	auto moveBy = MoveBy::create(5.0f, Vec2(0, -1500));
	maps[0]->runAction(RepeatForever::create(moveBy));
	maps[1]->runAction(RepeatForever::create(moveBy->clone()));
}


void GamePlay2Sene::update(float DeltaTime)
{
	updateMap();
}

void GamePlay2Sene::updateMap()
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
