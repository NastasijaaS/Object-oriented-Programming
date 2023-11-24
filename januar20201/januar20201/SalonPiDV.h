#pragma once
#include <iostream>
#include "SalonPV.h"
using namespace std;

class SalonPiDV : public SalonPV
{
private:
	int brojprodatihdostavna;
	int brojzaposlenihd;
public:
	SalonPiDV(){}
	SalonPiDV(char* n, int b, double xx, double yy, int br, int vv, int dd) : SalonPV(n, b, xx, yy, br)
	{
		brojprodatihdostavna = dd;
		brojzaposlenihd = vv;
	}
	~SalonPiDV(){}
	double efikasnostprodaje()
	{
		return ((brojprodatihdostavna + brojprodatihputnickih) / (brojzaposlenihd + brojzaposlenihp));
	}
	double efikasnostsalona()
	{
		return (efikasnostprodaje() / 2);
	}
	void print()
	{
		SalonPV::print();
		cout << brojprodatihdostavna << brojzaposlenihd;
	}
	void povecajProdaju(int br_kola, char tip) {
		if (tip == 'd')
		{
			brojprodatihdostavna += br_kola;
		}
		else
		{
		SalonPV::povecajProdaju(br_kola, tip);
		}
	}
	int  getbrojzapos()
	{
		return brojzaposlenihd + brojzaposlenihp;
	}
	 int vratiBrojProd()
	{
		return brojprodatihputnickih+brojprodatihdostavna;
	}
};
