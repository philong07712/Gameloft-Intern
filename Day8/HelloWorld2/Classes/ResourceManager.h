
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
# include <string>

USING_NS_CC;

class ResourceManager {
private:
	int m_score;
	int m_highScore;
	ResourceManager();
	static ResourceManager* s_instance; 
	std::string m_dataFolderPath;
	Map<int, Sprite*> m_sprites;
	Map<int, ui::Button*> m_buttons;
	Map<int, Label*> m_labels;
public:
	int getScore();
	void setScore(int);
	int getHighScore();
	void setHighScore(int);
	~ResourceManager();
	static ResourceManager* getInstance();
	void Init(const std::string path);
	void Load(std::string fileName);
	Sprite* GetSpriteById(int id);
	ui::Button* GetButtonById(int id);
	Label* GetLabelById(int id);
	Label* GetLabelArial();

	// Pre load the audio
	void preloadAudio();

};
