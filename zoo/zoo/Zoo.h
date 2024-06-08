#pragma once
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Feline.h"

using namespace std;

class Zoo
{
private:
	vector<Animal*> animals;
public:
	vector<Animal*> GetFishes()
	{
		vector<Animal*> fishes;
		for (Animal* animal : animals)
		{
			if (animal->IsAFish()==true)
			{
				fishes.push_back(animal);
			}
		}
		return fishes;
	}

	vector<Animal*> GetBirds()
	{
		vector<Animal*> birds;
		for (Animal* animal : animals)
		{
			if (animal->IsABird()==true)
			{
				birds.push_back(animal);
			}
		}
		return birds;
	}

	vector<Animal*> GetMammals()
	{
		vector<Animal*> mammals;
		for (Animal* animal : animals)
		{
			if (animal->IsAMammal()==true)
			{
				mammals.push_back(animal);
			}
		}
		return mammals;
	}

	vector<Feline*> GetFelines()
	{
		vector<Feline*> felines;
		for (Animal* animal : animals)
		{
			Feline* feline = dynamic_cast<Feline*>(animal);
			if (feline != nullptr)
			{
				felines.push_back(feline);
			}
		}
		return felines;
	}

	int GetTotalAnimals()
	{
		return animals.size();
	}

	void operator+=(Animal* animal)
	{
		animals.push_back(animal);
	}
	
	bool operator()(string name)
	{
		for (Animal* animal : animals)
		{
			if (animal->GetName() == name)
			{
				return true;
			}
		}
		return false;
	}
};

