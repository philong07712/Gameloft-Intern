# include "ResourceManager.h"
ResourceManager* ResourceManager::s_instance;
ResourceManager::ResourceManager()
{
}

ResourceManager* ResourceManager::getInstance()
{
	if (!s_instance) {
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::Init(const std::string path)
{
	m_dataFolderPath = path;
	Load("Data.bin");
}

void ResourceManager::Load(std::string fileName)
{
	auto isExist = FileUtils::getInstance()->isFileExist(fileName);
	std::string content = "";
	if (isExist) {
		content = FileUtils::getInstance()->getStringFromFile(fileName);
	}

	std::string spriteString = "SPRITE ";
	std::string buttonString = "BUTTON ";
	std::string fontString = "FONT ";
	size_t findSprite = content.find(spriteString);
	size_t findFont = content.find(fontString);
	size_t findButton = content.find(buttonString);
	// Size

	int sizeSprite = content[findSprite + spriteString.size() + 1] - '0';
	int sizeButton = content[findButton + buttonString.size() + 1] - '0';
	int sizeFont = content[findFont + fontString.size() + 1] - '0';

	std::stringstream ss(content);
	std::string line;
	int size;
	while (std::getline(ss, line, '#'))
	{
		if (line.find(spriteString) != std::string::npos)
		{
			size = line[spriteString.size()] - '0'; 
			std::stringstream ssLine(line);
			std::string miniLine;
			//while (std::getline(ssLine, miniLine, ))
			//{

			//}
		}
		else if (line.find(buttonString) != std::string::npos)
		{
			size = line[buttonString.size()] - '0';
		}
		if (line.find(fontString) != std::string::npos)
		{
			size = line[fontString.size()] - '0';
		}
	}
}

Sprite * ResourceManager::GetSpriteById(char id)
{
	return nullptr;
}

ui::Button * ResourceManager::GetButtonById(char id)
{
	return nullptr;
}

Label * ResourceManager::GetLabelById(char id)
{
	return nullptr;
}


ResourceManager::~ResourceManager()
{

}
