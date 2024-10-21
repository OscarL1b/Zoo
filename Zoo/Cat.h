#pragma once
#include "Animal.h"
using namespace std;

class Cat : public Animal
{
private:
	string speech = "ìÿó ìÿó";
	string breed;
	bool balt = false;

public:
	Cat(string parbreed, float parweaght, int parage, bool parbalt);
	Cat();
	Cat(int parid, string parname, float parweaght, int parage, string parbreed, bool parbalt);
	Cat(map <string, string> fieldsMap);
	void SetBreed(string parBreed);
	string GetBreed();
	void SetBalt(bool parBalt);
	bool GetBalt();
	float NeedFeed() const override;
	void Print() const override;
	void Fill() override;
	string Info() override;
};
