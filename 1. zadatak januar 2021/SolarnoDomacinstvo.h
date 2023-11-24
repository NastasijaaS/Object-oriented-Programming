#pragma once
#include "Domacinstvo.h"
#include <iostream>
using namespace std;
class SolarnoDomacinstvo : public Domacinstvo 
{
private:
	double solarnaE;
	double koefP;
	int cenaSis;
public:
	SolarnoDomacinstvo() {}
	SolarnoDomacinstvo(int jbr, double p, double u, double se, double k, int c)
	:Domacinstvo(jbr,p,u){
		solarnaE = se;
		koefP =k;
		cenaSis = c;
	}
	double potrosnja(double cena) {
		double p = Domacinstvo::potrosnja(cena);
		p = p + cenaSis - solarnaE * cena * koefP;
		return p;
	}
	void print() {
		Domacinstvo::print();
		cout << solarnaE << " " << koefP << " " << cenaSis;
	}

	~SolarnoDomacinstvo() {}


};
