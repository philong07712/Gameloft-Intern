
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
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

// Call back to logo
