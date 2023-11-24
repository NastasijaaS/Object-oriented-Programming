#pragma once
#include <iostream>
#include <fstream>
#include "Vozilo.h"
using namespace std;

class Automobil : public Vozilo
{
private:
	int brput;
public:
	Automobil() //pozivam konstruktor iz vozilo
	{

	}
	~Automobil()
	{

	}

	void upisi(ofstream& of)
	{
		Vozilo::upisi(of);
		of << brput;
	}

	virtual void procitaj(ifstream& i)
	{
		Vozilo::procitaj(i);
		i >> brput;
	}
	double getSpec()
	{
		return maksbr;//za kamion vracam potrosnju goriva
	}
	int uporedi(Vozilo* v)
	{
		if (maksbr > v->getSpec())
		{
			return 1;
		}
		else if (maksbr < v->getSpec())
		{
			return -1;
		}
		return 0;
	}

	void print()
	{
		Vozilo::print();
		cout << brput;
	}

};
