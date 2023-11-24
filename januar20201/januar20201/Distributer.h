#pragma once
#include <iostream>
#include "SalonPiDV.h"
#include "SalonPV.h"
using namespace std;

class Distributer
{
private:
	SalonPV** niz;
	int n, tren;
public:
	Distributer()
	{
		n = 0;
		tren = 0;
		niz = new SalonPV * [n];
	}
	Distributer(int nn)
	{
		n = nn;
		niz = new SalonPV * [n];
		tren = 0;
	}
	~Distributer()
	{
		for (int i = 0; i < tren; i++)
		{
			delete niz[i];
		}
		delete[]niz;
	}
	void dodaj(SalonPV* p)
	{
		if (tren < n)
		{
			niz[tren++] = p;
		}
		else
			cout << "Niz je pun";
	}
	void obrisi(int index)
	{
		for (int i = index; i < tren - 1; i++)
		{
			niz[i] = niz[i + 1];
		}
		tren--;
	}
	void povecajprodaju(int index, char t, int bk)
	{
		niz[index]->povecajProdaju(bk, t);
	}
	void izvestaj()
	{
		for (int i = 0; i < tren; i++)
		{
			niz[i]->print();
		}
	}
	int brojObjekata(int vrednost)
	{
		int brojac = 0;
		for (int i = 0; i < tren; i++)
		{
			if (niz[i]->getbrojzapos() > vrednost)
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
	SalonPV* rastojanje(double x, double y)
	{
		int j;
		double m = niz[0]->getX() - x;
		double s = niz[0]->getY() - y;
		double rastojanje = sqrt(pow(m, 2) + pow(s,2));
		for (int i = 1; i < tren; i++)
		{
			double k = niz[i]->getX() - x;
			double l = niz[i]->getY() - y;
			double rastojanjei= sqrt(pow(k, 2) + pow(l, 2));
			if (rastojanjei < rastojanje)
			{
				j = i;
			}
		}
		return niz[j];
	}
	double prosecno()
	{
		double p;
		for (int i = 0; i < tren; i++)
		{
			p = p + niz[i]->efikasnostsalona;
		}
		p = p / tren;
		return p;
	}
};
