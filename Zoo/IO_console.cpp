#include "Chinchila.h"
#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include <iostream>
using namespace std;

vector <Animal*>& vect = Animal::GetVect();

void Animal::Print() const
{
	cout <<  "------" << this->animal << "------" << endl;
	cout << "Id: " << this->id << endl;
	cout << "������: " << this->name << "\n���: " << this->weaght << "\n�������: " << this->age << endl;
}

void Dog::Print() const
{
	Animal::Print();
	cout << "������: " << this->breed << endl;
	cout << "��� ������: " << this->speech << endl;
}

void Cat::Print() const
{
	Animal::Print();
	cout << "������: " << this->breed;
	cout << "\n��� ������: " << this->speech << endl;
	
	if (this->balt)
	{
		cout << "����� ����� " << endl;
	}

	else
		cerr << "����� �� ����� " << endl;
}

void Chinchila::Print() const
{
	Animal::Print();
	cout << "�������: " << this->color << endl;
}

void Animal::Fill()
{
	unsigned id_mother;
	unsigned id_father;
	string f_name;
	float f_weaght;
	int f_age;
	bool whileMother = true;
	bool whileFather = true;

	cout << "������: ";
	cin >> f_name;
	this->SetName(f_name);

	cout << "���: ";
	cin >> f_weaght;
	this->SetWeaght(f_weaght);

	cout << "�������: ";
	cin >> f_age;
	this->SetAge(f_age);
	
	while (whileMother == true)
	{
		cout << "Id ������: ";
		cin >> id_mother;

		Animal* mother_inId = FindAnimal(id_mother); // ��������� ������ ������� ������
		if (mother_inId != nullptr) // ���� ������ ������ ������, ��
		{
			if (mother_inId->GetAnimal() == this->animal or id_mother == 0)
				this->SetMother(mother_inId);
			whileMother = false;
		}
		
	}

	while (whileFather == true)
	{
		cout << "Id ����: ";
		cin >> id_father;

		Animal* father_inId = FindAnimal(id_father);
		if (father_inId != nullptr)
		{
			if (father_inId->GetAnimal() == this->animal or id_father == 0)
				this->SetFather(father_inId);
			whileFather = false;
		}	
	}
}

void Dog::Fill()
{
	string f_breed;

	cout << "������: ";
	cin >> f_breed;
	this->SetBreed(f_breed);

	Animal::Fill();
}

void Cat::Fill()
{
	string f_breed;
	bool f_balt;
	string f_str_balt;
	
	cout << "������: ";
	cin >> f_breed;
	this->SetBreed(f_breed);

	Animal::Fill();

	cout << "����� �����?: ";
	cin >> f_str_balt;

	if (f_str_balt == "��")
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

	cout << "����: ";
	cin >> f_color;
	this->SetColor(f_color);
}
