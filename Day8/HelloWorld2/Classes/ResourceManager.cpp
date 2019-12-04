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
			auto sprite = Sprite::create(idPath);
			this->m_sprites.insert(number[0], sprite);
		}
	}
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
			// convert stringId to int
			auto button = ui::Button::create(idPath1, idPath2);
			this->m_buttons.insert(number[0], button);
		}
	}

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
			auto label = Label::create("Hello", idPath, 24);
			this->m_labels.insert(number[0], label);
		}
	}
}

Sprite * ResourceManager::GetSpriteById(char id)
{
	return this->m_sprites.at(id);
}

ui::Button * ResourceManager::GetButtonById(char id)
{
	return this->m_buttons.at(id);
}

Label * ResourceManager::GetLabelById(char id)
{
	return this->m_labels.at(id);
}


ResourceManager::~ResourceManager()
{
}
