#pragma once
#include "Proizvod.h"
#include <iostream>
#include <fstream>
using namespace std;

class Kondenzator : public Proizvod
{
private:
	int c; //kapacitivnost

public:
	Kondenzator() {}
	Kondenzator(char* bkod, int cc) {
		tip = new char[12];
		strcpy(tip, "kondenztor");
		barkod = new char[strlen(bkod) + 1];
		strcpy(barkod, bkod);
		c = cc;
	}
	Kondenzator(const Kondenzator& k) {
		tip = new char[12];
		strcpy(tip, "kondenztor");
		barkod = new char[strlen(k.barkod) + 1];
		strcpy(barkod, k.barkod);
		c = k.c;
	}
	~Kondenzator() {
		delete barkod;
		delete tip;
	}
	
	bool ispravan() {
		if (c == 0) return false;
		return true;
	}

	void print() {
		cout << tip << " " << barkod << " " << c << endl;
	}
	void print(ofstream& out) {
		out << tip << " " << barkod << " " << c << endl;
	}


};
