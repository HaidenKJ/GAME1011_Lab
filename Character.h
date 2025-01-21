#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character {
private:
	std::string m_characterName = "";
public:
	Character();
	Character(std::string name);
	~Character();
	void Print();
	void SetName(std::string name);
};

#endif // !CHARACTER_H
