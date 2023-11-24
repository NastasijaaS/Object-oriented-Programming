#pragma once
#include <iostream>
using namespace std;
class Domacinstvo {
	
protected:
	int jbroj;
	double povrsina;
	double utrosenaE;

public:
	Domacinstvo() {}
	~Domacinstvo() {}
	Domacinstvo(int jbr, double p, double u) {
		jbroj = jbr; povrsina = p; utrosenaE = u;
	}
	double getP() { return povrsina; }
	int getBr() { return jbroj; }
	double porosnjaPovrsina() {
		return utrosenaE / povrsina;
	}
	virtual double potrosnja(double cena) {
		return utrosenaE * cena;
	}
	virtual void print() {
		cout << jbroj << " " << povrsina << " " << utrosenaE << " ";
	}
};
