#pragma once
#include <iostream>
#include "Predmet.h"
using namespace std;
class Zlato : public Predmet {

private:
	int stepenCistoce;

public:
	Zlato(int m, int sc) {
		masa = m; stepenCistoce = sc;
		setVrednost();
	}
	~Zlato(){}
	void setVrednost() {
		vrednost = (masa / 24) * stepenCistoce;
	}
	void print() {
		cout << masa << " " << vrednost << " " << stepenCistoce << "\n";
	}


};