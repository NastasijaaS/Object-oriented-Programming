#pragma once
#include <iostream>
using namespace std;

class SefUOblikuKocke
{
private:
	int brojBrava;
	int brojZidova;
	int duzinaStr;
	int gustinaMaterijala;
public:
	SefUOblikuKocke()
	{
		brojBrava = 0;
		brojZidova = 0;
		duzinaStr = 0;
		gustinaMaterijala = 0;
	}
	SefUOblikuKocke(int bb, int bz, int ds, int gm)
	{
		if (bb > 1 || bb < 4)
		{
			brojBrava = bb;
		}
		if (bz > 0)
		{
			brojZidova = bz;
		}
		if (ds > 0)
		{
			duzinaStr = ds;
		}
		if (gm > 0)
		{
			gustinaMaterijala = gm;
		}
	}
	~SefUOblikuKocke()
	{

	}
	bool operator>(SefUOblikuKocke& obj)
	{
		if (this->brojBrava > obj.brojBrava)
			return true;
		else
			return false;
	}
	bool operator==(SefUOblikuKocke& obj)
	{
		if (this->brojBrava == obj.brojBrava && brojZidova == obj.brojZidova && duzinaStr == obj.duzinaStr && gustinaMaterijala == obj.gustinaMaterijala)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& izlaz, const SefUOblikuKocke& obj)
	{
		izlaz << "Sef:" << "  ima " << obj.brojBrava << " brava i " << obj.brojZidova << " zidova sa duzinom od "<<obj.duzinaStr<<endl;
		return izlaz;
	}
	void print()
	{
		cout << "Broj brava: " << this->brojBrava << " Debljina zida: " << this->brojZidova << " Duzina stranice: " << this->duzinaStr << " Gustina materijala: " << this->gustinaMaterijala << endl;
	}
	int vrednost()
	{
		return ((brojZidova/1000) * (duzinaStr/100)) * gustinaMaterijala;
	}
};