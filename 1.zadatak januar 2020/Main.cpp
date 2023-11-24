#include "Distributer.h"
#include "SalonVozila.h"
#include "SalonDostavna.h"
#include "Salon.h"
#include <iostream>

using namespace std;

void main() {

	Distributer d(5);
	SalonVozila*s1  = new SalonVozila((char*) "salon1", 10, 5.7, 9.4, 25);
	SalonVozila *s2 = new SalonVozila ((char*)"salon2", 15, 55.7, 42.5, 50);
	SalonDostava *sd1 = new SalonDostava((char*)"salondostavna1", 5, 51.7, 2.5, 3, 10, 30);
	SalonDostava *sd2 = new SalonDostava((char*)"salondostavna2", 7, 30.5, 21.5, 3, 12, 23);

	d.dodajSalon(s1);
	d.dodajSalon(s2);
	d.dodajSalon(sd1);
	d.dodajSalon(sd2);

	d.izvestaj();
	d.izbaciSalon(1);
	d.izvestaj();
	Salon* s5 = d.najblizi(12, 25);
	s5->print();
	cout << "\n";
	cout << d.previseZaposlenih(12) << endl;
	cout << d.ukupnoProdatih() << endl;
	cout << d.prosecnaVrednost();

	system("pause");
}