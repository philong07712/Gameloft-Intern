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
	//for (int i = 0; i < content.size(); i++) {
	//	if (content[i] == '#')
	//	{
	//		std::getline(content)
	//	}
	//}
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
