#pragma once
#include "Animal.h"
using namespace std;

class Dog : public Animal
{
private:
	string speech = "гав гав";
	string breed;

public:
	Dog(string breed, float weaght, int age);
	Dog();
	Dog(int parid, string parname, float parweaght, int parage, string parbreed);
	void SetBreed(string parBreed);
	string GetBreed();
	float NeedFeed() const override;
	void Print() const override;
	void Fill() override;
	string Info() override;
};
