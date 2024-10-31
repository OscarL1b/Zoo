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

Animal::Animal(unsigned par)
{
	if (par > 1) 
	{
		this->mother->FindAnimal(par);
	}
}

Animal::Animal(map <string, string> fieldsMap)
{
	if (fieldsMap.count("id"))		SetId(stoi(fieldsMap["id"]));
	if (fieldsMap.count("Животное"))	this->animal = fieldsMap["Животное"];
	if (fieldsMap.count("Кличка"))	this->name = fieldsMap["Кличка"];
	if (fieldsMap.count("Вес"))	this->weaght = stof(fieldsMap["Вес"]);
	if (fieldsMap.count("Возраст"))		this->age = stoi(fieldsMap["Возраст"]);
	if (fieldsMap.count("id матери"))
	{
		unsigned idFindMother = stoi(fieldsMap["id матери"]);
		Animal* findMother = FindAnimal(idFindMother);
		if (findMother != nullptr)
			this->mother = findMother;
	}
	if (fieldsMap.count("id отца"))
	{
		unsigned idFindFather = stoi(fieldsMap["id отца"]);
		Animal* findFather = FindAnimal(idFindFather);
		if (findFather != nullptr)
			this->father = findFather;
	}
}

vector < Animal* > &Animal::GetVect()
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

void Animal::SetMother(Animal* parM)
{
	this->mother = parM;
}

void Animal::SetFather(Animal* parF)
{
	this->father = parF;
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

int Animal::GetId()
{
	if (this != nullptr)
		return this->id;

	else
		return 0;
}

Animal* Animal::GetMother()
{
	return this->mother;
}

Animal* Animal::GetFather()
{
	return this->father;
}

float Animal::NeedFeed() const
{
	return 0;
}

string Animal::Info()
{
	return  "Животное: " + this->animal + "\t" +
		"id: " + to_string(this->id) + "\t" +
		"Кличка: " + this->name + "\t" +
		"Вес: " + to_string(this->weaght) + "\t" +
		"Возраст: " + to_string(this->age) + "\t" +
		"id матери: " + to_string(this->mother->GetId()) + "\t" +
		"id отца: " + to_string(this->father->GetId()) + "\t";
}


void Animal::SetId(int parid)
{
	this->id = parid;

	if (ID < parid)
		ID = parid;
}

Animal* Animal::FindAnimal(unsigned id)
{
	Animal* result = nullptr;

	vector< Animal* > vect = Animal::GetVect();
	for (short i = 0; i < size(vect); i++)
	{
		if (vect[i]->GetId() == id)
			result = vect[i];
	}

	return result;
}
