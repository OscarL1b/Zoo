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
#include <map>
using namespace std;

void SetSettingConsole();
void ShowMainMenu();
void ShowSelectAddAnimal();
void FindAnimalByName(vector <Animal*>& vect);
void FindAnimalsByType(vector <Animal*>& vect);
void DeleteAnimalByName(vector <Animal*>& vect);
void CalculatingFeed(vector <Animal*>& vect);
void InfoAnimals(vector <Animal*>& vect);
void SaveData(vector <Animal*>& vect, const string parFile);
string StringToUpp(string parStr);
void ReadData(vector < Animal* > &parvect, const string parFile);
pair <string, string> GetPair(string str, string separator);
bool ContainsValue(vector < string >& parVect, string parValue);
void PrintByType(vector < Animal* >& parVect, string parType);

int main()
{
	SetSettingConsole();
	
	int choiseMenu;
	const string file = "data.txt";
	vector <Animal*> &vect = Animal::GetVect();

	ReadData(vect, file);

	while (true)
	{
		system("cls");

		ShowMainMenu();
		cin >> choiseMenu;
		
		system("cls");

		switch (choiseMenu)
		{
		case 1:

			int variant;
			ShowSelectAddAnimal();
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

			FindAnimalByName(vect);

			system("pause");
			break;
			
		case 3:

			FindAnimalsByType(vect);

			system("pause");
			break;

		case 4:

			DeleteAnimalByName(vect);
			
			system("pause");
			break;

		case 5:

			CalculatingFeed(vect);

			system("pause");
			break;

		case 6:

			InfoAnimals(vect);

			system("pause");
			break;

		case 7:

			SaveData(vect, file);

			exit(EXIT_SUCCESS);

		default:

			cerr << "Такого выбора нет!" << endl;
			continue;
		}
	}
	return 0;
}


/// <summary>
/// Настройка текста в консоли
/// </summary>
void SetSettingConsole() 
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

/// <summary>
/// Вывод главного меню
/// </summary>
void ShowMainMenu()
{
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
}

/// <summary>
/// Вывод меню добавления животного
/// </summary>
void ShowSelectAddAnimal()
{
	system("cls");
	cout << "--------- Добавление животного ---------" << endl;
	cout << "1. Добавить собаку." << endl
		<< "2. Добавить кошку." << endl
		<< "3. Добавить шиншиллу." << endl
		<< "4. Назад." << endl;
	cout << ">>> ";
}

/// <summary>
/// Поиск животного по кличке
/// </summary>
/// <param name="vect"> Вектрор всех животных. </param>
void FindAnimalByName(vector <Animal*>& vect)
{
	string findAnimal;
	bool flag = false;
	cout << "Кличка животного которое надо найти: ";
	cin >> findAnimal;

	for (int i = 0; i < size(vect); i++)
	{
		if (StringToUpp(vect[i]->GetName()) == StringToUpp(findAnimal))
		{
			vect[i]->Print();
			flag = true;
		}

	}

	if (flag = false)
	{
		cout << "Животное не найдено! " << endl;
	}
}

/// <summary>
/// Поиск животных по типу
/// </summary>
/// <param name="vect"> Вуктор всех животных. </param>
void FindAnimalsByType(vector <Animal*>& vect)
{
	vector<string> typeAnim;

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

	PrintByType(vect, typeAnim[var - 1]);
}

/// <summary>
/// Удаление животного по кличке
/// </summary>
/// <param name="vect"> Вектрор всех животных. </param>
void DeleteAnimalByName(vector <Animal*>& vect)
{
	string deleteAnimal;
	bool flag = false;
	int indexDeleleAnimal;

	cout << "Кличка животного которое надо удалить: ";
	cin >> deleteAnimal;

	Animal* findDeleteAnimal = nullptr;

	for (int i = 0; i < size(vect); i++)
	{
		if (StringToUpp(vect[i]->GetName()) == StringToUpp(deleteAnimal))
		{
			findDeleteAnimal = vect[i];
			indexDeleleAnimal = i;
			flag = true;
		}
	}

	if (flag)
	{
		for (int i = 0; i < size(vect); i++)
		{
			if (findDeleteAnimal->GetId() == vect[i]->GetMother()->GetId() or findDeleteAnimal->GetId() == vect[i]->GetFather()->GetId())
			{
				cerr << "Животное нельзя удалить так как оно является родителем! " << endl;
				return;
			}
		}

		delete vect[indexDeleleAnimal];
		vect.erase(vect.begin() + indexDeleleAnimal);
		cout << "Животное удалено! " << endl;

	}
	else
		cerr << "Такого животного нет! " << endl;
}


/// <summary>
/// Расчёт колличества корма
/// </summary>
/// <param name="vect"> Вектрор всех животных. </param>
void CalculatingFeed(vector <Animal*>& vect)
{
	float needFeed;
	needFeed = 0;

	for (int i = 0; i < size(vect); i++)
	{
		needFeed = needFeed + vect[i]->NeedFeed();
	}
	cout << "Нужно корма: " << needFeed << endl;
}

/// <summary>
/// Информация обо всех животных.
/// </summary>
/// <param name="vect"> Вектор всех животных. </param>
void InfoAnimals(vector <Animal*>& vect)
{
	for (int i = 0; i < size(vect); i++)
	{
		vect[i]->Print();
	}
}

/// <summary>
/// Загрузка данных в файл
/// </summary>
/// <param name="vect"> Вектор всех животных. </param>
/// <param name="parFile"> Файл данных. </param>
void SaveData(vector <Animal*>& vect, const string parFile)
{
	ofstream out;

	out.open(parFile);
	for (int i = 0; i < size(vect); i++)
	{
		if (out.is_open())
		{
			out << vect[i]->Info();
		}
	}
	out.close();
}

/// <summary>
/// Перевод строки в верхний регистр
/// </summary>
/// <param name="parStr"> Строка которую нужно перевести в верхний регистр. </param>
/// <returns> Строка переведенная в верхний регистр. </returns>
string StringToUpp(string parStr)
{
	string Upp = "";
	Upp = parStr;
	for (int i = 0; i < size(parStr); i++)
	{
		Upp[i] = (char)toupper(parStr[i]);
	}
	return Upp;
}

/// <summary>
/// Чтение данных из файла
/// </summary>
/// <param name="parvect"> Вектор всех животных. </param>
/// <param name="parFile"> Файл данных. </param>
void ReadData(vector < Animal* >& parvect, const string parFile)
{
	vector<string> tokens;
	string separator = "\t";
	size_t separatorIndex = 0;
	string string_I;

	string pairField;
	string pairSeparator = ": ";

	map<string, string> fields;

	ifstream out(parFile);
	if (out.is_open())
	{
		while (getline(out, string_I))
		{
			//находим разделитель пар
			while ((separatorIndex = string_I.find(separator)) != string::npos)
			{
				//Пара ключ-значение
				pairField = string_I.substr(0, separatorIndex);

				//Записываем пару ключ-значение в словарь
				//Например "Животное" - "Собака"
				fields.insert(GetPair(pairField, pairSeparator));

				//из строки вырезаем уже обработанную пару
				string_I.erase(0, separatorIndex + separator.length());
			}

			//добавляем в словарь последнюю, не обработанную пару ключ-значение
			fields.insert(GetPair(string_I, pairSeparator));

			//создаем объект по параметрам
			if (fields["Животное"] == "Собака")
			{
				parvect.push_back(new Dog(fields));
			}
			else if (fields["Животное"] == "Кошка")
			{
				parvect.push_back(new Cat(fields));
			}
			else if (fields["Животное"] == "Шиншилла")
			{
				parvect.push_back(new Chinchila(fields));
			}

			//очищаем словарь
			//по сути, при последующих итерациях значения будут перезаписаны
			//но если какая то пара не будет перезаписана, она будет "висеть"
			//поэтому лучше все таки очистить
			fields.clear();

		}

		//закрываем файл
		out.close();
	}
}

/// <summary>
/// Разбирает строку на ключ-значение и возвращает пару
/// </summary>
/// <param name="str">Исходная строка</param>
/// <param name="separator">Разделитель ключа и значения</param>
/// <returns>Пара ключ-значение</returns>
pair <string, string> GetPair(string str, string separator)
{
	//Находим индекс разделителя пары
	int pairSeparatorIndex = str.find(separator);

	//Получаем ключ пары - это имя поля объекта
	string pairKey = str.substr(0, pairSeparatorIndex);

	//Получаем значение пары
	string pairValue = str.substr(pairSeparatorIndex + separator.length(), str.length());

	//возвращаем пару "ключ-значение"
	return pair<string, string> {pairKey, pairValue};

}


/// <summary>
///  Сравнение животного из vect и typeAnim
/// </summary>
/// <param name="parVect"> Вектор животных. </param>
/// <param name="parValue"> Животное с которым сравнивают </param>
/// <returns> Результат сравнения (true/false) </returns>
bool ContainsValue(vector < string >& parVect, string parValue)
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

/// <summary>
/// Вывод данных по типу
/// </summary>
/// <param name="parVect"> Вектор всех животных. </param>
/// <param name="parType"> Тип животного. </param>
void PrintByType(vector < Animal* >& parVect, string parType)
{
	for (short i = 0; i < size(parVect); i++)
	{
		if (parVect[i]->GetAnimal() == parType)
			parVect[i]->Print();
	}
}
