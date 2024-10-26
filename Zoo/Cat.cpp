#include "Cat.h"

Cat::Cat()
{
	this->animal = "Кошка";
}

Cat::Cat(string parbreed, float parWeaght, int parAge, bool parBalt) : Animal("Кошка", parWeaght, parAge)
{

}

Cat::Cat(int parid, string parname, float parweaght, int parage, string parbreed, bool parbalt) : Animal(parid, "Кошка", parname, parweaght, parage)
{
	this->breed = parbreed;
	this->balt = parbalt > 0;
}

Cat::Cat(map <string, string> fieldsMap) : Animal(fieldsMap)
{
	if (fieldsMap.count("breed"))	this->breed = fieldsMap["breed"];
	if (fieldsMap.count("balt"))	this->balt = stoi(fieldsMap["balt"]);
}

void Cat::SetBreed(string parBreed)
{
	this->breed = parBreed;
}

string Cat::GetBreed()
{
	return this->breed;
}

void Cat::SetBalt(bool parBalt)
{
	this->balt = parBalt;
}
bool Cat::GetBalt()
{
	return this->balt;
}

float Cat::NeedFeed() const
{
	float result = 0.0;

	result = 0.05 * this->weaght / 2;

	return result;
}

string Cat::Info()
{
	return Animal::Info() +
		"Порода: " + this->breed + "\t" +
		"Лысая: " + to_string(this->balt) + "\n";
}
