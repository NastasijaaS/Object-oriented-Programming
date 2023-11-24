#pragma once
#include "Teren.h"
#include "BocniTeren.h"
#include "OkruzenTeren.h"
#include <iostream>
using namespace std;

class Preduzece
{
private:
	int n, tren;
	Teren** niz;
public:
	Preduzece()
	{
		n = tren = 0;
		niz = nullptr;
	}
	Preduzece(int nn)
	{
		n = nn;
		niz = new Teren * [n];
		tren = 0;
	}
	~Preduzece()
	{
		for (int i = 0; i < tren; i++)
		{
			delete niz[i];
		}
		delete[]niz;
	}
	void dodaj(Teren* p)
	{
		if (tren == n)
			cout << "niz je pun";
		else
			niz[tren++] = p;
	}
	void obrisi(int id)
	{
		int ind = 0;
		int p = 0;
		for (int i = 0; i < tren && p == 0; i++)
		{
			if (niz[i]->getbr() == id)
			{
				ind = i;
				p = 1;
			}
		}
		if (p == 1)
		{
			for (int i = ind; i < tren; i++)
			{
				niz[i] = niz[i + 1];
			}
			tren--;
		}
		else
			cout << "ne postoji u nizu";
	}
	void printALL()
	{
		for (int i = 0; i < tren; i++)
		{
			niz[i]->print();
		}
	}
	void kupikartu(int br, char tip)
	{
		int ind = 0;
		int p = 0;
		for (int i = 0; i < tren && p == 0; i++)
		{
			if (niz[i]->getbr() == br)
			{
				ind = i;
				p = 1;
			}
		}
		if (p == 1)
		{
			if (tip == 'j')
			{
				if (niz[ind]->getBrmesta() > niz[ind]->getJef())
				{
					niz[ind]->Setbrmesta;
					niz[ind]->SetJef;
				}
				else
					cout << "Nema vise jeftinijih karata";
			}
			else
			{
				if (niz[ind]->getBrmesta() > niz[ind]->getSkup())
				{
					niz[ind]->Setbrmesta;
					niz[ind]->SetSkup;
				}
				else
					cout << "Nema vise skupljih karata";
			}
		}
		else
			cout << "Ne postoji teren";
	}
	Teren* najprodavaniji()
	{
		Teren* max = niz[0];
		for (int i = 1; i < tren; i++) {
			if (niz[i]->ukupanBrojkarata() > max->ukupanBrojkarata()) {
				max = niz[i];
			}
		}
		return max;
	}
	int ukupanBrojProdatih()
	{
		int suma = 0;
		for (int i = 0; i < tren; i++)
		{
			suma += niz[i]->ukupanBrojkarata();
		}
		return suma;
	}
	double ukupnaZarada(int cena)
	{
		double suma = 0;
		for (int i = 0; i < tren; i++)
		{
			suma += niz[i]->zarada(cena);
		}
		return suma;
	}
};
