#include "Kolekcija.h"
#include"Banana.h"
#include "iostream"
using namespace std;

void main() {
	try {
		Kolekcija<Banana> k(10);
		Banana b1(10, 1, 0);
		Banana b2(10, 1, 0);
		Banana b3(10, 1, 0);
		Banana b4(10, 1, 0);
		k.dodaj(b1);
		k.dodaj(b2);
		k.dodaj(b3);
		k.dodaj(b4);

		Kolekcija<double> k1(10);
		double e1 = 100.5;
		double e2 = 140.8;
		double e3 = 90;
		double e4 = 110;
		double e5 = 76.66;
		k1.dodaj(e1);
		k1.dodaj(e2);
		k1.dodaj(e3);
		k1.dodaj(e4);
		k1.dodaj(e5);
		cout << k1.prosek() << endl;
		k1.izbaci(15);
		k1.print();
	}
	catch (exception e) {
		cout << e.what();
	}
	catch (...) {
	}


}