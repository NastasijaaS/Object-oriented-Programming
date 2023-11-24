#include "Distributer.h"
#include "SalonPiDV.h"
#include "SalonPV.h"
#include <iostream>
using namespace std;

int main()
{
	Distributer d(5);
	SalonPV* s1 = new SalonPV((char*)"salon1", 10, 5.7, 9.4, 25);
	SalonPV* s2 = new SalonPV((char*)"salon2", 15, 55.7, 42.5, 50);
	SalonPiDV* sd1 = new SalonPiDV((char*)"salondostavna1", 5, 51.7, 2.5, 3, 10, 30);
	SalonPiDV* sd2 = new SalonPiDV((char*)"salondostavna2", 7, 30.5, 21.5, 3, 12, 23);

	d.dodaj(s1);
	d.dodaj(s2);
	d.dodaj(sd1);
	d.dodaj(sd2);

	d.izvestaj();
	d.obrisi(1);
	d.izvestaj();
	SalonPV* s5 = d.rastojanje(12, 25);
	s5->print();
	cout << "\n";
	cout << d.brojObjekata(12) << endl;
	cout << d.ukupanBrojProdatih() << endl;
	cout << d.prosecno();

	system("pause");
}
