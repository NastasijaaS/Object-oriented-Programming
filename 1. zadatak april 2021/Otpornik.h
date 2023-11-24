#pragma once
#include "Proizvod.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Otpornik : public Proizvod
{
private:

	int o;
	int min, max;

public:
	Otpornik() {}
	Otpornik(char* bkod, int ot, int minn, int maxx) {
		tip = new char[9];
		strcpy(tip, "otpornik");
		barkod = new char[strlen(bkod) + 1];
		strcpy(barkod, bkod);
		o = ot; min = minn; max = maxx;
	}
	~Otpornik() {
		delete barkod;
		delete tip;
	}

	bool ispravan() {
		if (o == 0) return false;
		return true;
	}

	void print() {
		cout << tip << " " << barkod << " " << o <<" " <<min <<" " << max << endl;
	}
	void print(ofstream& out) {
		out << tip << " " << barkod << " " << o << " " << min << " " << max << endl;
	}
};