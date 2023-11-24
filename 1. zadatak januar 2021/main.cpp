#include "Preduzece.h"
#include "Domacinstvo.h"
#include "SolarnoDomacinstvo.h"
#include <iostream>
using namespace std;

void main()
{
	SolarnoDomacinstvo* s1 = new SolarnoDomacinstvo(1, 20, 150, 50, 0.4, 1000);
	SolarnoDomacinstvo* s2 = new SolarnoDomacinstvo(2, 72, 200, 10, 0.7, 1500);
	SolarnoDomacinstvo* s3 = new SolarnoDomacinstvo(3, 70, 450, 40, 0.9, 2000);
	Domacinstvo* d1 = new Domacinstvo(4, 150, 500);
	Domacinstvo* d2 = new Domacinstvo(5, 78, 250);
	Domacinstvo* d3 = new Domacinstvo(6, 75, 400);
	Domacinstvo* min = new Domacinstvo();
	Domacinstvo* max = new Domacinstvo();
	Preduzece p(10);
	p.dodaj(s1);
	p.dodaj(s2);
	p.dodaj(s3);
	p.dodaj(d1);
	p.dodaj(d2);
	p.dodaj(d3);
	p.print(); 
	p.minmax(&min, &max, 10);
	min->print();
	cout << endl;
	cout << min->potrosnja(10);
	cout << endl;
	max->print();
	cout << endl;
	cout << max->potrosnja(10);

	cout << endl;
	cout << p.prosecnaPotrosnja();

}