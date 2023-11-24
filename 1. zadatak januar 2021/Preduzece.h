#pragma once
#include "SolarnoDomacinstvo.h"
#include "Domacinstvo.h"
#include <iostream>
using namespace std;

class Preduzece
{
private:
	Domacinstvo** niz;
	int n; int trenutno;

public:
	Preduzece(int nn) {
		n = nn;
		trenutno = 0;
		niz = new Domacinstvo* [n];
		
	}
	~Preduzece() {
		for (int i = 0; i < trenutno; i++) {
			delete niz[i];
		}
		delete[]niz;
	}
	void dodaj(Domacinstvo* s) {
		if (trenutno < n) niz[trenutno++] = s;
		else cout << "NIZ JE PUN!\n";
	}
	void obrisi(int jbr) {
		int p = 0;
		int ind = 0;
		for (int i = 0; i < trenutno && p!= 1; i++) {
			if (niz[i]->getBr() == jbr) {
				p = 1;
				ind = i;
			}
		}
		if (p == 1) {
			for (int i = ind; i < trenutno - 1; i++) {
				niz[i] = niz[i + 1];
			}
			trenutno--;
		}
		else {
			cout << "DOMACINSTVO NE POSTOJI!\n";
		}
	}
	double prosecnaPotrosnja() {
		double p = 0;
		for (int i = 0; i < trenutno; i++) {
			p = niz[i]->porosnjaPovrsina();
		}
		return p / trenutno;
	}

	void minmax(Domacinstvo** min, Domacinstvo** max, double cena) {
		*min = niz[0];
		*max = niz[0];
		for (int i = 0; i < trenutno; i++) {
			if( (*min)->potrosnja(cena) > niz[i]->potrosnja(cena))*min = niz[i];
			if ((*max)->potrosnja(cena) < niz[i]->potrosnja(cena))*max = niz[i];
		}
	}
	void print() {
		for (int i = 0; i < trenutno; i++) {
			niz[i]->print();
			cout << endl;
		}
	}

};
