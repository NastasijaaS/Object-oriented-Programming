#include "Predmet.h"
#include "DragiKamen.h"
#include "Jabuka.h"
#include "Ranac.h"
#include "Zlato.h"
#include <iostream>

using namespace std;

void main() {

	Ranac r(10);
	Jabuka* j = new Jabuka (1, 0.2, 0.7,(char*)"crvena");
	Jabuka j1(1, 0.7, 0.8, (char*)"zuta");
	r.dodajPredmet(j);
	r.dodajPredmet(&j1);
	Zlato* z1 = new Zlato(1, 3);
	Zlato* z2 = new Zlato(1, 5);
	DragiKamen* d = new DragiKamen(2, 0.7, (char*)"bela", 5);
	r.dodajPredmet(z1);
	r.dodajPredmet(z2);
	r.dodajPredmet(d);
	r.prikaz();
	cout << r.srednjaVrednost() << "\n";
	Predmet *p = r.najvredniji();
	p->print();

	system("pause");
}
