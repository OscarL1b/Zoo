#pragma once
#include <string>
#include <vector>
using namespace std;

class Animal
{

private:
	static vector < Animal* > vect;

protected:
	Animal* mother = nullptr;
	Animal* father = nullptr;
	string animal;
	string name;
	float weaght = 0.0;
	int age = 0;
	static int ID;
	int id = 0;

	Animal(string parAnimal);
	Animal(string parAnimal, float parWeaght, int parAge);
	Animal();
	Animal(int parid, string paranimal, string parname, float parweaght, int parage);
	Animal(unsigned parM, unsigned parF);

public:
	void SetVect(vector < Animal* > parvect);
	static vector < Animal* > GetVect();
	virtual void Print() const;
	void SetName(string parName);
	void SetWeaght(float parWeaght);
	void SetAge(int parAge);
	void SetMother(Animal* parM);
	void SetFather(Animal* parF);
	string GetName();
	float GetWeaght();
	int GetAge();
	string GetAnimal();
	int GetId();
	Animal* GetMother();
	Animal* GetFather();
	virtual float NeedFeed() const; 
	virtual void Fill();
	virtual string Info();
	void SetId(int parid);
	Animal* FindAnimal(unsigned id);
};
