#pragma once
#include "Salon.h"
#include <iostream>

using namespace std;

class SalonDostava : public Salon
{
protected:
	int br_zaposlenih_dostavna;
	int br_prodatih_dostavna;

public:
	SalonDostava() {};
	SalonDostava( char* n, int z, double x, double y, int p, int zd, int pd)
	{
		br_zaposlenih = z;
		this->x = x;
		this->y = y;
		prodata_vozila = p;
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);
		setEfikasnost();
		br_prodatih_dostavna = pd;
		br_zaposlenih_dostavna = zd;
		setEfikasnost();
	}

	void setEfikasnost() {
		efikasnost = (br_prodatih_dostavna / br_zaposlenih + prodata_vozila / br_zaposlenih) / 2;
	}
	~SalonDostava() {};

	void print() {
		cout << naziv << " " << br_zaposlenih << " " << x << "," << y << " " << prodata_vozila << " " << efikasnost << " ";
		cout << br_zaposlenih_dostavna << " " << br_prodatih_dostavna <<endl;
	}
	void povecajProdaju(int br_kola, char tip) {
		if (tip == 'd') br_prodatih_dostavna += br_kola;
		else
		{
		Salon:povecajProdaju(br_kola, tip);
		}
	}
	int getProdato() {
		return prodata_vozila + br_prodatih_dostavna;
	}
	int getZaposleni() {
		return br_zaposlenih+br_zaposlenih_dostavna;
	}
};
