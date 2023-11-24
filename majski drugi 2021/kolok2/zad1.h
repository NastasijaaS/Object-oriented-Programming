#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class LabVezbe
{
private:
	T* studenti;
	int n, tren;
public:
	LabVezbe(){}
	LabVezbe(int nn)
	{
		n = nn;
		studenti = new T[n];
		tren = 0;
	}
	~LabVezbe()
	{
		delete[] studenti;
	}
	void dodaj(T& s)
	{
		if (tren == 0)
		{
			studenti[tren++] = s;
		}
		else if (tren == n)
		{
			throw exception("nema mesta");
		}
		else
		{
			niz[tren++] = s;
		}
	}
	void obrisi(int index)
	{
		if (index > tren || index < 0) {
			throw exception("pogresan unos");
		}
		else
		{
			for (int i = index; i < zauzeto; i++)
			{
				niz[i] = niz[i++];
			}
			tren--;
		}
	}
	/*int vratipoz(int index)
	{
		if (index > tren || index < 0) {
			throw exception("ne postoji podatak");
		}
		else return index + 1;
	}*/

	T& vratipodatak(int index)
	{
		if (index > tren || index < 0) {
			throw exception("ne postoji podatak");
		}
		else
			return studenti[index];
	}

	double razlika(T& p1, T& p2)
	{
		int index1 = 0, index2 = 0;
		bool nadjen1 = false, nadjen2 = false;
		for (int i = 0; i < tren && (!nadjen1 || !nadjen2); i++)
		{
			if (studenti[i] = p1)
			{
				nadjen1 = true;
				index1 = i;
			}
			else if (studenti[i] = p2)
			{
				nadjen2 = true;
				index2 = i;
			}
		}
		if (nadjen1 == false || nadjen2 == false || i>tren)
		{
			throw exception("ne postoji podatak");
		}
		else 
			return index1 - index2;
	}

	void minmax(T* min, T* max)
	{
		min = studenti[0];
		max = studenti[0];
		for (int i = 0; i < tren; i++) {
			if (min > studenti[i]) min = niz[i];
			if (max < studenti[i]) max = niz[i];
		}
	}
	void zamenamesta()
	{
		for (int i = 0; i < tren / 2; i++)
		{
			studenti[i] = studenti[tren - 1 - i];
		}
	}
	void upisi(ofstream &out)
	{
		out << tren;
		for (int i = 0; i < tren; i++)
		{
			out << studenti[i];
		}
	}
	void ucitaj(ifstream& in)
	{
		//KAKO NADOOOOOOOOOOOOOOOO?? 
	}
};