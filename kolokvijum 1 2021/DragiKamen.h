#pragma once
#include <iostream>
#include "Predmet.h"
using namespace std;

class DragiKamen : public Predmet
{
private:
	double cistoca;
	char* boja; 
	int rez;
	
public:
	DragiKamen(int m, double c, char* b, int r) {
		masa = m; cistoca = c; rez = r;
		boja = new char[(strlen(b) + 1)];
		strcpy(boja, b);
		setVrednost();
	}
	~DragiKamen() {
		delete boja;
	}
	void setVrednost() {
		vrednost = masa * cistoca;
	}
	void print() {
		cout << masa << " " << vrednost << " " << boja << " " << cistoca << " " << rez << "\n";
	}



};

