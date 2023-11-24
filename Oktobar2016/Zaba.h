#pragma once
#include <iostream>
using namespace std;

class Zaba
{
private:
	int gustinaPega;
	int masa;
	int omiljenaMuva;
public:
	Zaba()
	{
		gustinaPega = masa = omiljenaMuva = 0;
	}
	Zaba(int gp, int masa, int om)
	{
		if (gp > 0)
		{
			gustinaPega = gp;
		}
		if (masa > 0)
		{
			this->masa = masa;
		}
		if (om > 0)
		{
			omiljenaMuva = om;
		}
	}
	~Zaba()
	{

	}
	bool operator>(Zaba& obj)
	{
		if (masa > obj.masa)
			return true;
		else if (masa == obj.masa && omiljenaMuva > obj.omiljenaMuva)
			return true;
		else
			if (masa == obj.masa && omiljenaMuva == obj.omiljenaMuva && gustinaPega > obj.gustinaPega)
				return true;
			else
				return false;
	}
	int vratiMasu()
	{
		return masa;
	}
	friend int operator+(int suma, Zaba& obj)
	{
		int s;
		s = suma + obj.vratiMasu();
		return s;
	}
	bool operator==(Zaba& obj)
	{
		if (masa == obj.masa && omiljenaMuva == obj.omiljenaMuva && gustinaPega == obj.gustinaPega)
			return true;
		else
			return false;
	}
	void print()
	{
		cout << "ZABA" << "     Masa zabe: " << masa << endl;
	}
	friend ostream& operator<<(ostream& izlaz, const Zaba& obj)
	{
		izlaz << "Zaba" << "   Masa zabe je " << obj.masa << endl;
		return izlaz;
	}
};