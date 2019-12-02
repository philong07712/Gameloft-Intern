
#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "cocos2d.h"
#include "LogoScene.h"
class GamePlayScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayScene);
};

#endif // __GAMEPLAY_SCENE_H__
