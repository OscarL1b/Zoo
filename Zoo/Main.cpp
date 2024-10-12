#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Chinchila.h"
#include <vector>
using namespace std;

string toUpp(string parStr);
void split(vector < Animal* > &parvect);
bool ContainsValue(vector < string >& parVect, string parValue);
void CaseThree(vector < Animal* > parVect, string parType);

int main()
{
	//какое то добавленное изменение
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const string seperator = "==================";
	//vector < Animal* > vect;
	int choiseMenu;
	string addAnimal;
	string findAnimal;
	string deleteAnimal;
	bool flag = false;
	bool flagDelete = false;
	ofstream out;
	vector<string> typeAnim;

	vector <Animal*> vect = Animal::GetVect();

	split(vect);

	

	while (true)
	{
		int k = 0;
		system("cls");
		cout << "--------- Меню ---------" << endl;
		cout << "1. Добавить животное." << endl
			<< "2. Найти животное." << endl
			<< "3. Найти животных по типу." << endl
			<< "4. Удалить животное." << endl
			<< "5. Расчет колличества корма." << endl
			<< "6. Информация обо всех животных." << endl
			<< "7. Выход." << endl;
		cout << ">>> ";
		cin >> choiseMenu;
		
		system("cls");

		switch (choiseMenu)
		{
		case 1:
			int variant;
			system("cls");
			cout << "--------- Добавление животного ---------" << endl;
			cout << "1. Добавить собаку." << endl
				<< "2. Добавить кошку." << endl
				<< "3. Добавить шиншиллу." << endl
				<< "4. Назад." << endl;
			cout << ">>> ";
			cin >> variant;

			system("cls");

			
			switch (variant)
			{
			case 1:
				vect.push_back(new Dog());
				vect.back()->Fill();
				cout << "Животное добавлено!" << endl;

				break;

			case 2:
				vect.push_back(new Cat());
				vect.back()->Fill();
				cout << "Животное добавлено!" << endl;

				break;

			case 3:
				vect.push_back(new Chinchila());
				vect.back()->Fill();
				cout << "Животное добавлено!" << endl;

				break;

			case 4:
				continue;

			default:
				cerr << "Такого выбора нет! " << endl;
				break;
			}

			
			system("pause");
			break;

		case 2:
			cout << "Кличка животного которое надо найти: ";
			cin >> findAnimal;

			for (int i = 0; i < size(vect); i++)
			{
				if (toUpp(vect[i]->GetName()) == toUpp(findAnimal))
				{
					vect[i]->Print();
					flag = true;
				}
				
			}

			if (flag = false)
			{
				cout << "Животное не найдено! " << endl;
			}

			system("pause");
			break;
			
		case 3:
			for (short i = 0; i < size(vect); i++)
			{
				if (ContainsValue(typeAnim, vect[i]->GetAnimal()) == false)
					typeAnim.push_back(vect[i]->GetAnimal());
			}

			short var;
			for (short i = 0; i < size(typeAnim); i++)
			{
				if (typeAnim[i] == "Собака")
					cout << i + 1 << ". Вывести всех собак." << endl;

				else if (typeAnim[i] == "Кошка")
					cout << i + 1 << ". Вывести всех кошек." << endl;

				else if (typeAnim[i] == "Шиншилла")
					cout << i + 1 << ". Вывести всех шиншилл." << endl;
			}
			cout << ">>> ";
			cin >> var;
			
			CaseThree(vect, typeAnim[var - 1]);

			system("pause");
			break;

		case 4:
			cout << "Кличка животного которое надо удалить: ";
			cin >> deleteAnimal;

			for (int i = 0; i < size(vect); i++)
			{
				if (toUpp(vect[i]->GetName()) == toUpp(deleteAnimal))
				{
					delete vect[i];
					vect.erase(vect.begin() + i);
					cout << "Животное удалено! " << endl;
				}
			}
			system("pause");
			break;

		case 5:
			float needFeed;
			needFeed = 0;

			for (int i = 0; i < size(vect); i++)
			{
				needFeed = needFeed + vect[i]->NeedFeed();
			}
			cout << "Нужно корма: " << needFeed << endl;

			system("pause");
			break;

		case 6:
			for (int i = 0; i < size(vect); i++)
			{
				vect[i]->Print();
			}
			system("pause");
			break;

		case 7:
			out.open("data.txt");
			for (int i = 0; i < size(vect); i++)
			{
				if (out.is_open())
				{
					out << vect[i]->Info();
				}
			}

			out.close();

			exit(EXIT_SUCCESS);

		default:
			cerr << "Такого выбора нет!" << endl;
			continue;
		}
	}

	return 0;
}

string toUpp(string parStr)
{
	string Upp = "";
	Upp = parStr;
	for (int i = 0; i < size(parStr); i++)
	{
		Upp[i] = (char)toupper(parStr[i]);
	}
	return Upp;
}


void split(vector < Animal* > &parvect)
{
	vector<string> tokens;
	string razdel = "\t";
	size_t pos = 0;
	string string_I;
	string token;

	ifstream out("data.txt");
	if (out.is_open())
	{
		while (getline(out, string_I))
		{
			while ((pos = string_I.find(razdel)) != string::npos) 
			{
				token = string_I.substr(0, pos);
				tokens.push_back(token);
				string_I.erase(0, pos + razdel.length());
			}

			tokens.push_back(string_I);

			if (tokens[0] == "Собака")
			{
				parvect.push_back(new Dog(stoi(tokens[1]), tokens[2], stof(tokens[3]), stoi(tokens[4]), tokens[5]));
				tokens.clear();
			}
			else if (tokens[0] == "Кошка")
			{
				parvect.push_back(new Cat(stoi(tokens[1]), tokens[2], stof(tokens[3]), stoi(tokens[4]), tokens[5], stoi(tokens[6]) > 0));
				tokens.clear();
			}
			else if (tokens[0] == "Шиншилла")
			{
				parvect.push_back(new Chinchila(stoi(tokens[1]), tokens[2], stof(tokens[3]), stoi(tokens[4]), tokens[5]));
				tokens.clear();
			}
		}

		out.close();
	}
}


bool ContainsValue(vector < string > &parVect, string parValue)
{
	bool result;
	auto it = find(parVect.begin(), parVect.end(), parValue);

	if (it != parVect.end())
	{
		result = true;
	}
	else
		result = false;

	return result; 
}


void CaseThree(vector < Animal* > parVect, string parType)
{
	for (short i = 0; i < size(parVect); i++)
	{
		if (parVect[i]->GetAnimal() == parType)
			parVect[i]->Print();
	}
}
