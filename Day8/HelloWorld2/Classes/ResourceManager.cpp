# include "ResourceManager.h"
ResourceManager::ResourceManager()
{
	//FileUtils::setWritablePath("D:\GameloftIntern\Day8\HelloWorld2\Resources");
}

ResourceManager* ResourceManager::getInstance()
{
	if (!s_instance) {
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::Init(const String path)
{
	m_dataFolderPath = path;
	//char* name = (char*)FileUtils::getInstance()->getFileData(path);
}

void ResourceManager::Load(String fileName)
{

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
