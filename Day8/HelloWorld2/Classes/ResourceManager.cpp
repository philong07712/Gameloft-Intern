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
	std::stringstream ss(content);
	std::string line;
	std::string text, numberLine, idPath;

	getline(ss, line, '\n');
	std::istringstream is(line);
	is >> text >> numberLine;
	int size = std::stoi(numberLine);
	if (text == "#SPRITE") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine(line);
			pathLine >> text >> idPath;
			// convert stringId to int
			int id = stoi(number);
			auto sprite = Sprite::create(idPath);
			this->m_sprites.insert(id, sprite);
		}
	}
	getline(ss, line, '\n');
	std::istringstream buttonstream(line);
	buttonstream >> text >> numberLine;
	size = std::stoi(numberLine);
	if (text == "#BUTTON") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath1, idPath2;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine1(line);
			pathLine1 >> text >> idPath1;
			// get PATH2 line
			std::getline(ss, line, '\n');
			std::istringstream pathLine2(line);
			pathLine2 >> text >> idPath2;
			int id = stoi(number);
			// convert stringId to int
			auto button = ui::Button::create(idPath1, idPath2);
			this->m_buttons.insert(id, button);
		}
	}
	getline(ss, line, '\n');
	std::istringstream fontStream(line);
	fontStream >> text >> numberLine;
	size = std::stoi(numberLine);
	if (text == "#FONT") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath1, idPath2;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine1(line);
			pathLine1 >> text >> idPath1;
			// convert stringId to int
			int id = stoi(number);
			auto label = Label::createWithTTF("Hello", idPath1, 24);
			this->m_labels.insert(id, label);
		}
	}
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	return this->m_sprites.at(id);
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	return this->m_buttons.at(id);
}

Label * ResourceManager::GetLabelById(int id)
{
	return m_labels.at(id);
}

Label * ResourceManager::GetLabelArial()
{
	return nullptr;
}

ResourceManager::~ResourceManager()
{
}
