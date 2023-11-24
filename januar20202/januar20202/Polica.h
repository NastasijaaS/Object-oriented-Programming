#pragma once
#include <iostream>
#include "Knjiga.h"
using namespace std;

template <class T>
class Polica
{
private:
	T* niz;
	int n, tren;
public:
	Polica()
	{
		n = 0; tren = 0;
		niz = nullptr;
	}
	Polica(int nn)
	{
		n = nn;
		tren = 0;
		niz = new T[n];
	}
	~Polica()
	{
		for (i = 0; i < tren; i++)
			delete niz[i];
		delete[] niz;
	}
	void Dodaj(T& m)
	{
		if (tren == 0)
			niz[tren++] = m;
		else
		{
			if (tren == n)
			{
				throw exception("NIZ JE PUN");
				return;
			}
			if (niz[tren - 1] > obj)
			{
				throw "Narusava se pravilnost niza!";
				return;
			}
			for (int i = 0; i < tren; i++)
			{
				if (niz[i] == obj)
				{
					throw "Vec ima takav element!";
					return;
				}
			}
			niz[tren] = obj;
			tren++;
		}
	}
	void izbaci(int index)
	{
		if (tren == 0) 
		{
			throw "Niz je prazan!";
			return;
		}
		if (index<0 || index>tren)
		{
			throw "Nepravilan unos";
			return;
		}
		for (int i = index; i < tren; i++)
		{
			niz[i] = niz[i + 1];
		}
		tren--;
	}
	void print()
	{
		for (int i = 0; i < tren; i++)
		{
			cout << niz[i];
		}
	}
};
