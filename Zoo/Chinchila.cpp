#include "Chinchila.h"

Chinchila::Chinchila()
{
	this->animal = "Ўиншилла";
}
Chinchila::Chinchila(string parColor, float parWeaght, int parAge) : Animal("Ўиншилла", parWeaght, parAge)
{

}

Chinchila::Chinchila(int parid, string parname, float parweaght, int parage, string parcolor) : Animal(parid, "Ўиншилла", parname, parweaght, parage)
{
	this->color = parcolor;
}

Chinchila::Chinchila(map <string, string> fieldsMap) : Animal(fieldsMap)
{
	if (fieldsMap.count("color"))	this->color = fieldsMap["color"];
}

void Chinchila::SetColor(string parColor)
{
	this->color = parColor;
}

string Chinchila::GetColor()
{
	return this->color;
}

float Chinchila::NeedFeed() const
{
	float result = 0.0;

	result = 0.03 * this->weaght / 1;

	return result;
}

string Chinchila::Info()
{
	return Animal::Info() + "÷вет: " + this->color + "\n";
}
