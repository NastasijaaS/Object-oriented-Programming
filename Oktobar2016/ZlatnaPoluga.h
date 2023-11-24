#pragma once
#include <iostream>
using namespace std;

class ZlatnaPoluga
{
private:
	int finocaZlata;
	int masa;
public:
	ZlatnaPoluga()
	{
		finocaZlata = masa = 0;
	}
	ZlatnaPoluga(int fz,int masa)
	{
		if (fz > 1 || fz < 999)
		{
			this->finocaZlata = fz;
		}
		if (masa > 0)
		{
			this->masa = masa;
		}
		else
		{
			this->masa = masa * (-1);
		}
	}
	~ZlatnaPoluga()
	{

	}
	bool operator>(ZlatnaPoluga& obj)
	{
		if (finocaZlata > obj.finocaZlata)
			return true;
		else
			return false;
	}
	bool operator==(ZlatnaPoluga& obj)
	{
		if (finocaZlata == obj.finocaZlata && masa == obj.masa)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& izlaz, const ZlatnaPoluga& obj)
	{
		izlaz << "Zlatna Poluga:" << "  ima finocu zlata:" << obj.finocaZlata << "  i masu:" << obj.masa << endl;
		return izlaz;
	}
	friend double operator+(double suma, ZlatnaPoluga& obj)
	{
		//double s;
		//s = suma + obj.vrednost();
		return suma + obj.vrednost();
	}
	friend bool operator>(double suma, ZlatnaPoluga& obj)
	{
		if (suma > obj.vrednost())
			return true;
		else
			return false;
	}
	void print()
	{
		cout << "Finoca zlata: " << this->finocaZlata << " Masa: " << this->masa << endl;
	}
	int vrednost()
	{
		return masa;
	}
};