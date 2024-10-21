#include "Dog.h"

Dog::Dog()
{
	this->animal = "Собака";
}

Dog::Dog(string parbreed, float parWeaght, int parAge) : Animal("Собака", parWeaght, parAge)
{

}

Dog::Dog(int parid, string parname, float parweaght, int parage, string parbreed) : Animal(parid, "Собака", parname, parweaght, parage)
{
	this->breed = parbreed;
}

Dog::Dog(map <string, string> fieldsMap) : Animal(fieldsMap)
{
	if (fieldsMap.count("breed"))	this->breed = fieldsMap["breed"];
}

void Dog::SetBreed(string parBreed)
{
	this->breed = parBreed;
}

string Dog::GetBreed()
{
	return this->breed;
}

float Dog::NeedFeed() const
{
	float result = 0.0;

	result = 0.1 * this->weaght / 2;

	return result;
}

string Dog::Info()
{
	return Animal::Info() + "breed: " + this->breed;
}
