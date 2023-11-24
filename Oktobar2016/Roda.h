#pragma once
#include <iostream>
using namespace std;

class Roda
{
private:
	double masa;
	double visina;
	double rasponKrila;
	int brojZaba;
public:
	Roda()
	{
		masa = visina = rasponKrila = brojZaba = 0;
	}
	Roda(double masa, double visina, double rk, int bz)
	{
		if (masa > 0)
		{
			this->masa = masa;
		}
		if (visina > 0)
		{
			this->visina = visina;
		}
		if (rk > 0)
		{
			this->rasponKrila = rk;
		}
		if (bz > 0)
		{
			this->brojZaba = bz;
		}
		
	}
	~Roda()
	{

	}
	bool operator>(Roda& obj)
	{
		if (masa > obj.masa)
			return true;
		else
			if (masa == obj.masa && brojZaba > obj.brojZaba)
				return true;
			else
				if (masa = obj.masa && brojZaba == obj.brojZaba && visina > obj.visina)
					return true;
				else
					if (masa = obj.masa && brojZaba == obj.brojZaba && visina == obj.visina && rasponKrila > obj.rasponKrila)
						return true;
					else
						return false;
	}
	void print()
	{
		cout << "Roda" << "    Masa:" << masa << endl;
	}
	bool operator==(Roda& obj)
	{
		if (masa = obj.masa && brojZaba == obj.brojZaba && visina == obj.visina && rasponKrila == obj.rasponKrila)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& izlaz, const Roda& obj)
	{
		izlaz << "Roda" << "   Masa roda je " << obj.masa << endl;
		return izlaz;
	}
};