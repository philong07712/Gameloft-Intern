
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
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	addMap();
	scheduleUpdate();
    return true;
}

void GamePlay2Sene::addMap()
{
}


void GamePlay2Sene::update(float DeltaTime)
{
}

void GamePlay2Sene::updateMap()
{
}
