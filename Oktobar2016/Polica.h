#pragma once
#include "CD.h"
#include "Knjiga.h"
using namespace std;

template <class T>
class Polica
{
private:
	int N;
	int tren;
	T* niz;
public:
	Polica()
	{
		N = tren = 0;
		niz = nullptr;
	}
	Polica(int n)
	{
		N = n;
		tren = 0;
		niz = new T[n];
	}
	~Polica()
	{
		delete[] niz;
	}
	void dodaj(T& obj)
	{
		if (tren == 0)
		{
			niz[tren++] = obj;
		}
		else
		{
			if (tren == N)
			{
				throw " Niz je pun! ";
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
	void izbrisi(int index)
	{
		if (tren == 0)
		{
			throw "Niz je prazan!";
			return;
		}
		if (index>tren)
		{
			throw "Index nije u tom nizu!";
			return;
		}
		for (int i = index; i < tren; i++)
		{
			niz[i] = niz[i + 1];
		}
		tren--;
	}
	void printALL()
	{
		for (int i = 0; i < tren; i++)
		{
			cout << niz[i];
		}
	}
};