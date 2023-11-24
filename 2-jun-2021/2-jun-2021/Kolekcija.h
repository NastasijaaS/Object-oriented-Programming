#pragma once
#include "iostream"

using namespace std;

template<class T> class Kolekcija {

private:
	T* niz;
	int max;
	int tren;
public:
	Kolekcija(){}
	Kolekcija(int m) {
	max		= m;

		niz = new T[max];
		tren = 0;
	}
	~Kolekcija() {
		delete niz;
	}
	void dodaj(T& el) {
		if (tren < max) {
			niz[tren++] = el;
		}
		else
		{
			throw exception ("NIZ JE PUN!");
		}
	}

	double prosek() {
		double p = 0;
		for (int i = 0; i < tren; i++) {
			p = p + niz[i];
		}
		return p / tren;
	}

	void izb(int i) {
		for (; i < tren - 1; i++) {
			niz[i] = niz[i + 1];
		}
		tren--;
	}

	void izbaci(double pr) {
		double p = prosek();
		pr =  pr / 100;
		for (int i = 0; i < tren; i++) {

			if ((1 - pr) * niz[i] > p) izb(i);
			else if ((1 + pr) * niz[i] < p) izb(i);
		}
	}
	void print() {
		for (int i = 0; i < tren; i++) {
			cout << niz[i] << endl;
		}
	}


};