#pragma once
#include "SalonPV.h"
#include "SalonPiDVh.h"
#include <iostream>
using namespace std;

class Distributer
{
private:
	int N;
	int tren = 0;
	SalonPV** niz;
public:
	Distributer()
	{
		N = 0;
		tren = 0;
		niz = nullptr;
	}
	Distributer(int N)
	{
		this->N = N;
		niz = new SalonPV * [N];
		tren = 0;
	}
	~Distributer()
	{
		for (int i = 0; i < tren; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}
	void dodaj(SalonPV& obj)
	{
		if (tren < N)
		{
			niz[tren] = &obj;
			tren++;
		}
		else
		{
			cout << "Niz je pun!";
		}
	}
	void izbrisi(int index)
	{
		for (int i = index; i < tren; i++)
		{
			niz[i] = niz[i + 1];
		}
		tren--;
	}
	void uvecaj(int index,char* naziv, int brojVozila)
	{
		if (strcmp(niz[index]->vratiNaziv(), naziv)== 0)
		{
			niz[index]->uvecajBrojProd(brojVozila);
		}
		else
		{
			cout << "Greska!";
		}
	}
	void printALL()
	{
		for (int i = 0; i < tren; i++)
		{
			niz[i]->print();
		}
		cout << endl;
	}
	int brojObjekata(int vrednost)
	{
		int brojac = 0;
		for (int i = 0; i < tren; i++)
		{
			if (niz[i]->vratiBrojZap() > vrednost)
				brojac++;
		}
		return brojac;
	}
	int ukupanBrojProdatih()
	{
		int suma = 0;
		for (int i = 0; i < tren; i++)
		{
			suma += niz[i]->vratiBrojProd();
		}
		return suma;
	}
	int rastojanje(int x, int y)
	{
		int temp = abs(x - y);
		int j = 0;
		for (int i = 0; i < tren; i++)
		{
			if (abs(niz[i]->getX() - niz[i]->getY()) <= temp)
			{
				j = i;
			}
		}
		return j;
	}
};