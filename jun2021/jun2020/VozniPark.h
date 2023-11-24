#pragma once
#include "Automobil.h"
#include "Vozilo.h"
#include <iostream>
#include <fstream>
using namespace std;

class VozniPark
{
private:
	Vozilo** p;
	int maksbrv;
	char tip;
	int tren;//u konstr tren=0;
public:
	VozniPark() {

	}
	void dodaj(Vozilo* v)
	{
		if (tren < maksbrv)
		{
			p[tren] = v;
			tren++;
		}

		else
		{
			Vozilo** pom = new Vozilo * [maksbrv];
			for (int i = 0; i < maksbrv; i++)
			{
				pom[i] = p[i];
			}
			maksbrv += maksbrv / 2;
		
			p = new Vozilo * [maksbrv];
			for (int i = 0; i < tren; i++)
			{
				p[i] = pom[i];
			}

			p[tren] = v;
			tren++;

		}
	}

	void upisi(char* s)
	{
		ofstream of(s);
		
		if (of.is_open)
		{
			of << maksbrv << tip << tren;
			for (int i = 0; i < tren; i++)
			{
				p[i]->upisi(of);
			}
		}
	}

	void procitaj(char* s)
	{
		ifstream m(s);
		
		if (m.good())
		{
			m >> maksbrv >> tip>> tren;
			p = new Vozilo * [maksbrv];
			if (tip == 'A')
			{
				for (int i = 0; i < tren; i++)
				{
					p[i] = new Automobil();
					p[i]->procitaj(m);
					
				}
			}
			else
			{
				for (int i = 0; i < tren; i++)
				{
					//p[i] = new Kamion();
					p[i]->procitaj(m);

				}
			}
		}
	}

	void sort()
	{
		Vozilo* pom;
		for (int i=0;i<tren-1;i++)
			for (int j = i + 1; j < tren; j++)
			{
				if (p[i]->uporedi(p[j]) < 0)
				{
					pom = p[i];
					p[i] = p[j];
					p[j] = pom;
				}
			}
	}

	Vozilo* najveci()
	{
		sort();
		return p[0];
	}




};
