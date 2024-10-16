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

	cout << "Id матери: ";
	cin >> id_mother;
	//this->SetIdMother(id_mother);

	cout << "Id отца: ";
	cin >> id_father;
	//this->SetIdFather(id_father);
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
