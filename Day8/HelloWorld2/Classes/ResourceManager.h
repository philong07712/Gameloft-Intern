
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
# include <string>

USING_NS_CC;

class ResourceManager {
private:
	ResourceManager();
	static ResourceManager* s_instance; 
	std::string m_dataFolderPath;
	Map<char, Sprite*> m_sprites;
	Map<char, ui::Button*> m_buttons;
	Map<char, Label*> m_labels;
public:
	~ResourceManager();
	static ResourceManager* getInstance();
	void Init(const std::string path);
	void Load(std::string fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLabelById(char id);

};
