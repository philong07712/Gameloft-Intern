
#pragma once
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;

class ResourceManager {
private:
	ResourceManager();
	static ResourceManager* s_instance;
	String m_dataFolderPath;
	Map<char, Sprite*> m_sprites;
	Map<char, ui::Button*> m_buttons;
	Map<char, Label*> m_labels;
public:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* getInstance();
	void Init(const String path);
	void Load(String fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLabelById(char id);

};
