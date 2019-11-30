# include "LogoScene.h"
# include "HelloWorldScene.h"
# include "LoadingScene.h"
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
	// Adding animation
	auto zombie = Sprite::create();
	zombie->setPosition(150, 150);
	addChild(zombie, 3);

	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("Zombie0.png", Rect(0, 0, 100, 130)));
	animFrames.pushBack(SpriteFrame::create("Zombie1.png", Rect(0, 0, 100, 130)));
	//animFrames.pushBack(SpriteFrame::create("Zombie2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("Zombie3.png", Rect(0, 0, 100, 130)));
	animFrames.pushBack(SpriteFrame::create("Zombie4.png", Rect(0, 0, 100, 130)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);

	zombie->runAction(RepeatForever::create(animate));

	//addChild(player);
	// Adding background
	addBackground();
	// Adding king character
	king = Sprite::create("GroundKing.png");
	king->setPosition(100, 100);
	king->setScale(2.0f);
	addChild(king, 1);
	auto moveBy = MoveBy::create(1, Vec2(200, 0));
	auto sequence = Sequence::create(moveBy, moveBy->reverse(), nullptr);
	auto fullsequence = Sequence::create(sequence, sequence->reverse(), nullptr);
	king->runAction(RepeatForever::create(fullsequence));
	// Adding pig character
	pig = Sprite::create("GroundPig.png");
	pig->setScale(2.0f);
	pig->setPosition(100, 200);
	addChild(pig, 2);
	//
	this->schedule(schedule_selector(LogoScene::changeLoading), 3.0f);
	return true;
}

int a = 0;
void LogoScene::update(float deltaTime)
{
	if (a == 20) {
		auto move = MoveBy::create(2, Vec2(200, 0));
		auto move_ease_in = EaseBounceIn::create(move->clone());
		auto move_ease_in_back = move_ease_in->reverse();

		auto sequence = Sequence::create(move_ease_in, move_ease_in_back, nullptr);
		pig->runAction(RepeatForever::create(sequence));
	}
	a++;
}

void LogoScene::addBackground() {
	auto background = Sprite::create("backgroundColorFall.png");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();
	background->setPosition(Point(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(background, 1);
}

void LogoScene::changeLoading(float dt) {
	auto myScene = LoadingScene::createScene();
	Director::getInstance()->replaceScene(
		TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));
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