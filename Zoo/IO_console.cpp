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

	cout << "������: ";
	cin >> f_name;
	this->SetName(f_name);

	cout << "���: ";
	cin >> f_weaght;
	this->SetWeaght(f_weaght);

	cout << "�������: ";
	cin >> f_age;
	this->SetAge(f_age);
	
	while (true)
	{
		cout << "Id ������: ";
		cin >> id_mother;

		if (id_mother == 0)
			break;

		Animal* foundMother = FindAnimal(id_mother); // ��������� ������ ������� ������
		if (foundMother != nullptr) // ���� ������ ������ �� ������, ��
		{
			if (this->id != foundMother->GetId())
			{
				if (foundMother->GetAnimal() == this->animal)
				{
					this->SetMother(foundMother);
					break;
				}
				else
					cerr << "������ ���� ��������! " << endl;
			}
			else
				cerr << "������ ������� ��������� ���� ��������! " << endl;
		}
		else
			cerr << "��� ������ ���������! " << endl;
	}

	while (true)
	{
		cout << "Id ����: ";
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
					cerr << "������ ���� ��������! " << endl;
			}
			else
				cerr << "������ ������� ��������� ���� ��������! " << endl;
		}
		else
			cerr << "��� ������ ���������! " << endl;
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
