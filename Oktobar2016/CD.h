#pragma once
#include <iostream>
using namespace std;

class CD
{
private:
	int velicina;
	int zauzetiProstor;
	int slobodanProstor;
public:
	CD()
	{
		velicina = slobodanProstor = zauzetiProstor = 0;
	}
	CD(int v, int z, int s)
	{
		if (v > 0)
		{
			velicina = v;
		}
		if (z > 0)
		{
			zauzetiProstor = z;
		}
		if (slobodanProstor > 0)
		{
			slobodanProstor = s;
		}
	}
	~CD()
	{
	
	}
	bool operator>(CD& obj)
	{
		if (velicina > obj.velicina)
			return true;
		else if (velicina == obj.velicina && zauzetiProstor > obj.zauzetiProstor)
			return true;
		else if (velicina == obj.velicina && zauzetiProstor == obj.zauzetiProstor && slobodanProstor > obj.slobodanProstor)
			return true;
		else
			return false;
	}
	bool operator==(CD& obj)
	{
		if (velicina == obj.velicina && zauzetiProstor == obj.zauzetiProstor && slobodanProstor == obj.slobodanProstor)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& izlaz, const CD& obj)
	{
		izlaz << "CD-" << "Velicina:" << obj.velicina << "  Slobodan prostor:" << obj.slobodanProstor << endl;
		return izlaz;
	}

};