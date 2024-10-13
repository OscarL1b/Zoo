#include "Animal.h"
#include "vector"

int Animal::ID;
vector<Animal*> Animal::vect;

Animal::Animal()
{
	this->id = ++ID;
}

Animal::Animal(string parAnimal)
{
	this->id = ++ID;
	this->animal = parAnimal;
}

Animal::Animal(string parAnimal, float parWeaght, int parAge)
{
	this->id = ++ID;
	this->animal = parAnimal;
	this->weaght = parWeaght;
	this->age = parAge;
}

Animal::Animal(int parid, string paranimal, string parname, float parweaght, int parage)
{
	SetId(parid);
	this->animal = paranimal;
	this->name = parname;
	this->weaght = parweaght;
	this->age = parage;
}

Animal::Animal(unsigned parId_M, unsigned parId_F)
{
	this->idMother = parId_M;
	this->idFather = parId_F;
}

void Animal::SetVect(vector < Animal* > parvect)
{
	Animal::vect = parvect;
}

vector < Animal* > Animal::GetVect()
{
	return Animal::vect;
}

void Animal::SetName(string parName)
{
	this->name = parName;
}

void Animal::SetWeaght(float parWeaght)
{
	this->weaght = parWeaght;
}
void Animal::SetAge(int parAge)
{
	this->age = parAge;
}

void Animal::SetIdMother(unsigned parId_M)
{
	this->idMother = parId_M;
}

void Animal::SetIdFather(unsigned parId_F)
{
	this->idFather = parId_F;
}

string Animal::GetName()
{
	return this->name;
}

float Animal::GetWeaght()
{
	return this->weaght;
}
int Animal::GetAge()
{
	return this->age;
}

string Animal::GetAnimal()
{
	return this->animal;
}

unsigned Animal::GetIdMother()
{
	return this->idMother;
}

unsigned Animal::GetIdFather()
{
	return this->idFather;
}

float Animal::NeedFeed() const
{
	return 0;
}

string Animal::Info()
{
	return  this->animal + "\t" + to_string(this->id) + "\t" + this->name + "\t" + to_string(this->weaght) + "\t" + to_string(this->age) + "\t";
}

void Animal::SetId(int parid)
{
	this->id = parid;

	if (ID < parid)
		ID = parid;
}
