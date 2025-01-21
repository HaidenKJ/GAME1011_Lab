#include "Character.h"
#include <iostream>

Character::Character() 
{
	std::cout << "Default character constructor has been called.\n";
}

Character::Character(std::string name) 
{
	m_characterName = name;
	std::cout << name << " has been created.\n";
}

void Character::SetName(std::string name) 
{
	m_characterName = name;
}

Character::~Character() 
{
	std::cout << m_characterName << " has been destroyed.\n";
}

void Character::Print()
{
	std::cout << m_characterName << " is calling it's print function.\n";
}