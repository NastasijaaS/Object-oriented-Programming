#pragma once
#include "Predmet.h"

class Ranac
{
private:
	Predmet** ranac;
	int n;
	int zauzeto;


public:
	Ranac(int n) {
		this->n = n;
		ranac = new Predmet*[n];
		zauzeto = 0;
	}
	~Ranac()
	{
		delete ranac;
	}

	void dodajPredmet(Predmet* p) {
		if (zauzeto < n) {
			ranac[zauzeto++] = p;
		}
	}
	void prikaz() {
		for (int i = 0; i < zauzeto; i++) {
			ranac[i]->print();
		}
	}

	Predmet* najvredniji() {
		Predmet* max = ranac[0];
		for (int i = 1; i < zauzeto; i++) {
			if ((ranac[i]->getVrednost() / ranac[i]->getMasa()) > (max->getVrednost() / max->getMasa())) {
				max = ranac[i];
			}
		}
		return max;
	}

	double srednjaVrednost() {
		double ukupno = 0;
		for (int i = 0; i < zauzeto; i++) {
			ukupno += ranac[i]->getVrednost();
		}
		ukupno /= zauzeto;
		return ukupno;
	}

};