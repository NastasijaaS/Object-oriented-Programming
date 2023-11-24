#pragma once
#include <iostream>
#include "Predmet.h"
using namespace std;

class Jabuka : public Predmet {

private:
	double ks, kk;
	char* boja;
public:
	Jabuka(int m, double kss, double kkk, char* b) {
		masa = m; 
		ks = kss; 
		kk = kkk;
		boja = new char[strlen(b) + 1];
		strcpy(boja, b);
		setVrednost();
	}
	~Jabuka() {
		delete boja;
	}

	void setVrednost() {
		if (ks < 0.5 || kk < 0.5) vrednost = 0;
		else
		{
			vrednost = ks * kk, masa * 1000;
		}
	}
	void print() {
		cout << masa << " " << vrednost << " " << ks << " " << kk << " " << boja << "\n";
	} 

};
