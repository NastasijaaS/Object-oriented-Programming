#pragma once
#include <iostream>
using namespace std;

class SalonPV
{
protected:
	char* naziv;
	int brojZapPV;
	int x, y;
	int brojProdatihPV;
public:
	SalonPV()
	{
		brojZapPV = 0;
		brojProdatihPV = 0;
		x = y = 0;
		this->naziv = new char[strlen("Salon putnickih vozila") + 1];
		strcpy(this->naziv, "Salon putnickih vozila");
	}
	SalonPV(int bzpv, int x, int y, int bppv)
	{
		brojZapPV = bzpv;
		this->x = x;
		this->y = y;
		brojProdatihPV = bppv;
		this->naziv = new char[strlen("Salon putnickih vozila") + 1];
		strcpy(this->naziv, "Salon putnickih vozila");
	}
	virtual ~SalonPV()
	{
		delete[] naziv;
	}
	virtual double efikasnostProdaje()
	{
		return this->brojProdatihPV / this->brojZapPV;
	}
	virtual double efikasnostRada()
	{
		return this->efikasnostProdaje();
	}
	virtual void print()
	{
		cout << "Naziv: " << this->naziv << " Broj zaposlenih: " << this->brojZapPV << " Broj prodatih vozila: " << this->brojProdatihPV << endl;
	}
	virtual void uvecajBrojProd(int broj)
	{
	      brojProdatihPV+=broj;
	}
	virtual char* vratiNaziv()
	{
		return naziv;
	}
	virtual int vratiBrojZap()
	{
		return brojZapPV;
	}
	virtual int getX()
	{
		return x;

	}
	virtual int getY()
	{
		return y;
	}
	virtual int vratiBrojProd()
	{
		return brojProdatihPV;
	}
};