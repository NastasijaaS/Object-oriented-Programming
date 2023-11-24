#pragma once
#include <iostream>
using namespace std;

class SalonPV 
{
protected:
	char* naziv;
	int brojzaposlenihp;
	double x, y;
	int brojprodatihputnickih;
	
public:
	SalonPV()
	{
		naziv = NULL;
	}
	SalonPV(char *n,int b,double xx,double yy,int br)
	{
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);
		brojzaposlenihp = b;
		x = xx;
		y = yy;
		brojprodatihputnickih = br;

	}
	virtual ~SalonPV()
	{
		delete[] naziv;
	}
	virtual double efikasnostprodaje()
	{
		return brojprodatihputnickih / brojzaposlenihp;
	}

	virtual double efikasnostsalona()
	{
		return efikasnostprodaje();
	}

	virtual void print()
	{
		cout << naziv << brojzaposlenihp << brojprodatihputnickih;
	}

	void povecajProdaju(int br_kola, char tip) {
		if (tip == 'p')
		{
			brojprodatihputnickih += br_kola;
		}
		else cout << "GRESKA!";
	}

	virtual int getbrojzapos()
	{
		return brojzaposlenihp;
	}
	virtual int vratiBrojProd()
	{
		return brojprodatihputnickih;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
};

