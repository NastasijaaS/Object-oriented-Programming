#pragma once
#include "Roda.h"
#include "Zaba.h"
#include <iostream>
using namespace std;

template <class T>
class Sablon
{
private:
	int tren;
	int N;
	T* niz;
public:
	Sablon()
	{
		tren = N = 0;
		niz = nullptr;
	}
	Sablon(int N)
	{
		tren = 0;
		this->N = N;
		niz = new T[N];
	}
	~Sablon()
	{
		if (tren == 0)
		{
			throw "Niz je prazan, nemamo sta da izbrisemo!";
			return;
		}
		delete[] niz;
	}
	void dodaj(T& obj)
	{
		if (tren == 0)
		{
			niz[tren] = obj;
			tren++;
		}
		else
		{
			if (tren == N - 1)
			{
				throw "Niz je pun!";
				return;
			}
			/*if (niz[tren - 1] >  obj)
			{
				throw "Narusava se pravnilnost niza!";
				return;
			}*/
			for (int i = 0; i < tren; i++)
			{
				if (niz[i] == obj)
				{
					throw "Vec postoji takav element";
					return;
				}
			}
			//int pom;
			for (int i = 0; i < tren; i++)
			{
				if (niz[i] > obj)
				{
					tren++;
					for (int j = tren; j >i; j--)
					{
						niz[j] = niz[j-1];
					}
					niz[i] = obj;
					return;
				}
			}
			
			niz[tren] = obj;
			tren++;
			
		}
	}
	void izbrisi(int index)
	{
		if (tren == 0)
		{
			throw "Niz je prazan!";
			return;
		}
		if (index > tren)
		{
			throw "Index se ne nalazi u tom  nizu!";
			return;
		}
		else
		{
			for (int i = index; i < tren; i++)
			{
				niz[i] = niz[i + 1];
			}
			tren--;
		}
	}
	int ukupnaMasa()
	{
		int suma = 0;
		for (int i = 0; i < tren; i++)
		{
			suma = suma + niz[i];
		}
		return suma;
	}
	void printALL()
	{
		for (int i = 0; i < tren; i++)
		{
			cout << niz[i];
		}
	}
};