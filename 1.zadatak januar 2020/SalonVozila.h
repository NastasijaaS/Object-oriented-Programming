#pragma once
#include "Salon.h"
#include <iostream>

using namespace std;

class SalonVozila : public Salon {
protected:

	void setEfikasnost() {
		efikasnost = prodata_vozila / br_zaposlenih;
	}

public:
	SalonVozila() {}
	SalonVozila(char* n, int zaposleni, double _x, double _y, int prodato) {
		br_zaposlenih = zaposleni;
		x = _x;
		y = _y;
		prodata_vozila = prodato;
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);
		setEfikasnost();
	}
	~SalonVozila() {
		delete[]naziv;
	}

	void print() {
		cout << naziv << " " << br_zaposlenih << " " << x << "," << y << " " << prodata_vozila << " " << efikasnost << endl;
	}
	
	void povecajProdaju(int br_kola, char tip) {
		if (tip == 'p') prodata_vozila += br_kola;
		else cout << "GRESKA!";
	}

	int getProdato() {
		return prodata_vozila;
	}

	virtual int getZaposleni() {
		return br_zaposlenih;
	}
};
