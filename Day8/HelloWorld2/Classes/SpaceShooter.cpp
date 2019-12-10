# include "SpaceShooter.h"
# include "Bullet.h"
# include "MainMenuScene.h"
# include "GameOverScene.h"
# include "ResourceManager.h"
# include "SimpleAudioEngine.h"
using namespace std;

cocos2d::Scene* targetScene;
SpaceShooter::SpaceShooter(cocos2d::Scene* scene)
{
	targetScene = scene;
	SpaceShooter::Init();
	// create the bullet
}

void SpaceShooter::Init()
{
	for (int i = 0; i < 20; i++)
	{
		Bullet *bullet = new Bullet(targetScene);
		this->m_bullets.push_back(bullet);
		targetScene->addChild(bullet->getSprite());
		bullet->getSprite()->setVisible(false);
	}

	// create the spaceShip
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("Sprites\\SpaceShip\\ship.plist", "Sprites\\SpaceShip\\ship.png");
	auto ship = cocos2d::Sprite::createWithSpriteFrame(spriteCache->getSpriteFrameByName("1.png"));
	cocos2d::Vector<cocos2d::SpriteFrame*> shipFrames;
	int maxFrame = 8;
	const auto maxChar = 35;
	char frameName[maxChar] = { 0 };
	for (int i = 2; i <= maxFrame; i++) {
		sprintf(frameName, "%d.png", i);
		shipFrames.pushBack(spriteCache->getSpriteFrameByName(frameName));
	}
	auto animation = cocos2d::Animation::createWithSpriteFrames(shipFrames, 0.15f);
	auto animate = cocos2d::Animate::create(animation);
	ship->runAction(cocos2d::RepeatForever::create(animate));
	setSprite(ship);
}
// Intial Global
static float a = 0;

void SpaceShooter::Update(float dt)
{
	a += dt;
	Shoot(dt);
	borderShip();
}

void SpaceShooter::Shoot(float dt)
{
	auto moveBy = MoveBy::create(1.5f, Vec2(0, 1100));
	auto sequence = Sequence::create(moveBy, nullptr);
	for (int i = 0; i < 20; i++)
	{
		auto bullet = this->m_bullets[i]->getSprite();
		if (!bullet->isVisible() && a > dt * 20) {
			auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
			audio->playEffect("Sounds/shoot.wav", false, 1.0f, 1.0f, 1.0f);

			bullet->setVisible(true);
			bullet->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
			bullet->runAction(sequence->clone());
			a = 0;
			break;
		}
		if (bullet->getPosition().y > 1000)
		{
			bullet->stopAllActions();
			bullet->setVisible(false);
			bullet->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
		}
	}
}

void SpaceShooter::borderShip()
{
	// Set border for the ship
	Vec2 loc = getSprite()->getPosition();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (loc.x < -150)
	{
		getSprite()->setPosition(visibleSize.width, loc.y);
	}
	else if (loc.x > visibleSize.width + 100)
	{
		getSprite()->setPosition(-50, loc.y);
	}
	else if (loc.y < -150)
	{
		getSprite()->setPosition(loc.x, visibleSize.height);
	}
	else if (loc.y > visibleSize.height + 100)
	{
		getSprite()->setPosition(loc.x, -50);
	}
}

int score;
void SpaceShooter::Collision(vector<Rock*> rocks)
{
	if (score == 10)
	{
		ResourceManager::getInstance()->setScore(score);
	}
	for (int i = 0; i < rocks.size(); i++)
	{
		auto rock = rocks[i]->getSprite();
		for (int i = 0; i < this->m_bullets.size(); i++)
		{
			auto bullet = this->m_bullets[i]->getSprite();
			if (bullet->getBoundingBox().intersectsRect(rock->getBoundingBox())
				&& rock->isVisible() && bullet->isVisible())
			{
				score++;
				// create soundEffect
				auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
				audio->playEffect("Sounds/explosion.wav", false, 1.0f, 1.0f, 1.0f);
				// create Effect
				auto emitter = CCParticleSystemQuad::create("explosion.plist");
				emitter->setPosition(rock->getPosition().x, rock->getPosition().y);
				targetScene->addChild(emitter);
				emitter->setScale(0.25f);
				emitter->setAutoRemoveOnFinish(true);

				bullet->setVisible(false);
				rock->setVisible(false);
				rock->setPosition(rock->getPosition().x, -100);
				bullet->setPosition(bullet->getPosition().x, 1000);
			}
		}
		if (getSprite()->getBoundingBox().intersectsRect(rock->getBoundingBox()) && rock->isVisible())
		{
			WriteScore();
			getSprite()->setVisible(false);
		}
	}
}

bool SpaceShooter::onContactBegin(PhysicsContact * contact)
{
	return false;
}

void SpaceShooter::WriteScore()
{
	ResourceManager::getInstance()->setScore(score);
	int maxScore = ResourceManager::getInstance()->getHighScore();
	if (maxScore < score)
	{
		maxScore = score;
	}
	ResourceManager::getInstance()->setHighScore(maxScore);
	score = 0;
}

SpaceShooter::~SpaceShooter()
{
}