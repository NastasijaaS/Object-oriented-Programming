#pragma once
#include "Letovanje.h"
#include "ObilazakGrada.h"
#include "Putovanje.h"
#include <iostream>
#include <fstream>

using namespace std;

class Agencija
{
private:
	Putovanje** niz;
	int n;
	int zauzeto;
public:
	Agencija()
	{
		zauzeto = n = 0;
		niz = nullptr;
	}
	Agencija(int nn)
	{
		n = nn;
		niz = new Putovanje * [n];
		zauzeto = 0;

	}
	~Agencija()
	{
		for (int i = 0; i < zauzeto; i++)
			delete niz[i];
		delete[] niz;
	}
	void upisiufajlsve()
	{
		ofstream out("ponuda.txt", ios::app);
		if (out.good())
		{
			for (int i = 0; i < zauzeto; i++)
				niz[i]->print(out);
			out.close();
		}
	}
	Putovanje* najzanimljivije()
	{
		Putovanje* max = niz[0];
		for (int i = 1; i < zauzeto; i++)
		{
			if ((niz[i]->zanimljivosti()) > (max->zanimljivosti()))
				max = niz[i];
		}
		return max;
	}

	double srednjavred()
	{
		double ukupno = 0;
		for (int i = 0; i < zauzeto; i++)
		{
			ukupno = ukupno + niz[i]->cena();
		}
		ukupno = ukupno / zauzeto;
		return ukupno;
	}
	void Dodaj(Putovanje* p)
	{
		if (zauzeto == 0)
		{
			niz[zauzeto++] = p;
		}
		else
		{
			bool smesteno = false;
			int index = 0;
			for (int i = 0; i < zauzeto && !smesteno; i++)
				if (niz[i]->cena() < niz[i + 1]->cena())
				{
					smesteno = true;
					index = i;
				}
			if (smesteno == false)
			{
				niz[zauzeto++] = p;
			}
			else
			{
				for (int i = zauzeto - 1; i >= index; i--)
				{
					niz[i + 1] = niz[i];
				}
				niz[index] = p;
				zauzeto++;
			}
		}

	}

	void izmeniticenuputovanja(int index, int novacena)
	{
		Putovanje* pom;
		niz[index]->SetCenaNocenja(novacena);
		for (int i = 0; i < zauzeto - 1; i++)
			for (int j = i + 1; j < zauzeto; j++)
				if (niz[i]->cena() > niz[j]->cena())
				{
					pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
	 
	}
};

