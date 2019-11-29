# include "LogoScene.h"
# include "HelloWorldScene.h"
Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

cocos2d::Sprite* king;
cocos2d::Sprite* pig;
bool LogoScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	//
	king = Sprite::create("GroundKing.png");
	king->setPosition(100, 100);
	king->setScale(2.0f);
	addChild(king, 1);
	auto moveTo = MoveTo::create(2, Vec2(300, 300));
	king->runAction(moveTo);
	//
	pig = Sprite::create("GroundPig.png");
	pig->setScale(2.0f);
	pig->setPosition(100, 200);
	addChild(pig, 2);
	//
	return true;
}

int a = 0;
void LogoScene::update(float deltaTime)
{
	if (a == 20) {
		auto scaleBy = ScaleBy::create(3.0f, 3.0f);
		pig->runAction(scaleBy);
	}
	a++;
	//if (a == 10) {
	//	this->changeScene();
	//}
}


void LogoScene::changeScene() {
	auto myScene = HelloWorld::createScene();
	// Transition Fade
	int random = rand() % 5;
	switch (random)
	{
	case 0:
		Director::getInstance()->replaceScene(
			TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));
		break;
	case 1:
		Director::getInstance()->replaceScene(TransitionFlipX::create(2, myScene));
		break;
	case 2:
		Director::getInstance()->replaceScene(TransitionMoveInR::create(2, myScene));
		break;
	case 3:
		Director::getInstance()->replaceScene(TransitionFlipAngular::create(2, myScene));
		break;
	case 4:
		Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, myScene));
		break;
	default:
		Director::getInstance()->replaceScene(TransitionFlipY::create(2, myScene));
		break;
	}



}