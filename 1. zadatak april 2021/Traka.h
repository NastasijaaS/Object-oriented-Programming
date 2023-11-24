#pragma once
#include "Proizvod.h"
#include "Otpornik.h"
#include "Kondenzator.h"
#include <iostream>
#include <fstream>
using namespace std;
class Traka {

private:
	Proizvod** traka;
	int n; int zauzeto;

public:
	Traka(int nn) {
		n = nn;
		traka = new Proizvod *[n];
		zauzeto = 0;
	}
	void prosiriTraku() {
		Proizvod** pom = new Proizvod*[n];
		for (int i = 0; i < zauzeto; i++) {
			pom[i] = traka[i];
		}
		n = n + 1;
		traka = new Proizvod *[n];
		for (int i = 0; i < zauzeto; i++) {
			traka[i] = pom[i];
		}
		delete []pom;
		cout << "TRAKA JE PROSIRENA" << endl;

	}
	void dodaj(Proizvod* p) {
		if (zauzeto < n) {
			traka[zauzeto++] = p;
		}
		else
		{
			prosiriTraku();
			traka[zauzeto++] = p;
		}
	}

	void zameniILIukloni(char* kod , Proizvod *p) {
		int index = 0; bool postoji = false;
		for (int i = 0; i < zauzeto && postoji == false; i++) {
			if (strcmp(traka[i]->getKod(), kod) == 0) {
				postoji = true;
				index = i;
			}
		}if (index <= (zauzeto / 3)) {
			cout << "PROIZVOD JE ZAMENJEN "; traka[index]->print(); cout << endl;
			traka[index] = p;
			traka[index]->print(); cout << endl;
		}
		else {
			cout << "PROIZVOD JE OBRASAN "; traka[index]->print(); cout << endl;
			for (int i = index; i < zauzeto - 1; i++) {
				traka[i] = traka[i + 1];
			}
			zauzeto--;
		}
	}
	void print() {
		for (int i = 0; i < zauzeto; i++) {
			traka[i]->print();
		}
	}
	void ukloni() {
		ofstream out("izvestaj.txt", ios::app);
		if (out.good()) {
			traka[0]->print(out);
			// out << traka[0]->getKod() << endl << traka[0]-getTip() << endl;
			cout << "UKLONJEN!";
			traka[0]->print();
			out.close();

		}
		for (int i = 0; i < zauzeto-1; i++) {
			traka[i] = traka[i + 1];
		}
		zauzeto--;
	}
	int brojDefektnih() {
		int b = 0;
		for (int i = 0; i < zauzeto; i++) {
			if (!traka[i]->ispravan())b++;
		}
		return b;
	}
	int brojPraznihMesta() { return n - zauzeto;}


};