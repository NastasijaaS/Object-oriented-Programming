#pragma once
#include "SalonPV.h"
#include <iostream>
using namespace std;

class SalonPiDV :public SalonPV
{
private:
	int brojZapDV;
	int brojProdatihDV;
public:
	SalonPiDV():SalonPV()
	{
		brojZapDV = 0;
		brojProdatihDV = 0;
		this->naziv = new char[strlen("Salon putnickih i dostavnih vozila") + 1];
		strcpy(this->naziv, "Salon putnickih i dostavnih vozila");
	}
	SalonPiDV(int bzpv, int x, int y, int bppv, int bzdv, int bpdv) :SalonPV(bzpv, x, y, bppv)
	{
		this->brojZapDV = bzdv;
		this->brojProdatihDV = bpdv;
		this->naziv = new char[strlen("Salon putnickih i dostavnih vozila") + 1];
		strcpy(this->naziv, "Salon putnickih i dostavnih vozila");
	}
	~SalonPiDV()
	{

	}
	double efikasnostProdaje()
	{
		return (this->brojProdatihDV + brojProdatihPV) / (brojZapDV + brojZapPV);
	}
	double efikasnostRada()
	{
		return this->efikasnostProdaje() / (brojProdatihDV + brojProdatihPV);
	}
	void print()
	{
		cout << "Naziv: " << this->naziv << " Broj zaposlenih PV: " << this->brojZapPV << " Broj prodatih PV : " << this->brojProdatihPV << " Broj zaposlenih DV: "<<this->brojZapDV<<" Broj prodativ DV: "<<this->brojProdatihDV<<endl;

	}
	char* vratiNaziv()
	{
		return naziv;
	}
	void uvecajBrojProd(int broj)
	{
		 brojProdatihDV += broj;
	}
	int vratiBrojZap()
	{
		return brojZapPV+brojZapDV;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int vratiBrojProd()
	{
		return brojProdatihPV+brojProdatihDV;
	}
};