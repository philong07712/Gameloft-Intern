# include "LogoScene.h"
# include "HelloWorldScene.h"
Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	srand((unsigned)time(0));
	if (!Scene::init()) {
		return false;
	}
	scheduleUpdate();
	return true;
}

int a = 0;
void LogoScene::update(float deltaTime)
{
	auto king = Sprite::create("GroundKing.png");
	auto scaleBy = ScaleBy::create(2.0f, 3.0f);
	auto pig = Sprite::create("GroundPig.png");
	king->setPosition(100, 100);
	pig->setPosition(100, 150);
	addChild(king, 1);
	addChild(pig, 2);

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