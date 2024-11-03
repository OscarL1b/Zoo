#include "Chinchila.h"
#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include <iostream>
using namespace std;

void Animal::Print() const
{
	cout <<  "------" << this->animal << "------" << endl;
	cout << "Id: " << this->id << endl;
	cout << "Кличка: " << this->name << "\nВес: " << this->weaght << "\nВозраст: " << this->age << endl;
}

void Dog::Print() const
{
	Animal::Print();
	cout << "Порода: " << this->breed << endl;
	cout << "Она делает: " << this->speech << endl;
}

void Cat::Print() const
{
	Animal::Print();
	cout << "Порода: " << this->breed;
	cout << "\nОна делает: " << this->speech << endl;
	
	if (this->balt)
	{
		cout << "Кошка лысая " << endl;
	}

	else
		cerr << "Кошка не лысая " << endl;
}

void Chinchila::Print() const
{
	Animal::Print();
	cout << "Окраска: " << this->color << endl;
}

void Animal::Fill()
{
	unsigned id_mother;
	unsigned id_father;
	string f_name;
	float f_weaght;
	int f_age;

	cout << "Кличка: ";
	cin >> f_name;
	this->SetName(f_name);

	cout << "Вес: ";
	cin >> f_weaght;
	this->SetWeaght(f_weaght);

	cout << "Возраст: ";
	cin >> f_age;
	this->SetAge(f_age);
	
	while (true)
	{
		cout << "Id матери: ";
		cin >> id_mother;

		if (id_mother == 0)
			break;

		Animal* foundMother = FindAnimal(id_mother); // получение самого объекта матери
		if (foundMother != nullptr) // если объект матери не пустой, то
		{
			if (this->id != foundMother->GetId())
			{
				if (foundMother->GetAnimal() == this->animal)
				{
					this->SetMother(foundMother);
					break;
				}
				else
					cerr << "Разные типы животных! " << endl;
			}
			else
				cerr << "Нельзя сделать родителем само животное! " << endl;
		}
		else
			cerr << "Нет такого животного! " << endl;
	}

	while (true)
	{
		cout << "Id отца: ";
		cin >> id_father;

		if (id_father == 0)
			break;

		Animal* foundFather = FindAnimal(id_father);
		if (foundFather != nullptr)
		{
			if (this->id != foundFather->GetId())
			{
				if (foundFather->GetAnimal() == this->animal)
				{
					this->SetFather(foundFather);
					break;
				}
				else
					cerr << "Разные типы животных! " << endl;
			}
			else
				cerr << "Нельзя сделать родителем само животное! " << endl;
		}
		else
			cerr << "Нет такого животного! " << endl;
	}
}

void Dog::Fill()
{
	string f_breed;

	cout << "Порода: ";
	cin >> f_breed;
	this->SetBreed(f_breed);

	Animal::Fill();
}

void Cat::Fill()
{
	string f_breed;
	bool f_balt;
	string f_str_balt;
	
	cout << "Порода: ";
	cin >> f_breed;
	this->SetBreed(f_breed);

	Animal::Fill();

	cout << "Кошка лысая?: ";
	cin >> f_str_balt;

	if (f_str_balt == "Да")
	{
		f_balt = true;
	}
	else
		f_balt = false;
	this->SetBalt(f_balt);
}

void Chinchila::Fill()
{
	string f_color;

	Animal::Fill();

	cout << "Цвет: ";
	cin >> f_color;
	this->SetColor(f_color);
}
