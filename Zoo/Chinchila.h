#pragma once
#include "Animal.h"
class Chinchila : public Animal
{
private:
	string color;

public:
	Chinchila(string parColor, float parWeaght, int parAge);
	Chinchila();
	Chinchila(int parid, string parname, float parweaght, int parage, string parcolor);
	Chinchila(map <string, string> fieldsMap);
	void SetColor(string parColor);
	string GetColor();
	float NeedFeed() const override;
	void Print() const override;
	void Fill() override;
	string Info() override;
};
