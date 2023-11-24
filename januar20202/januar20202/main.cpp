//#include "CD.h"
#include "Knjiga.h"
#include "Polica.h"
#include <iostream>
using namespace std;


void main()
{
	Knjiga k1, k2, k3, k4, k5;
	//CD c1,c2,c3;
	Polica<Knjiga> pk(5);
	//Polica<CD> polica2(5);
	try {
		fstream ulaz("polica1.txt");
		if (ulaz.good())
		{
			ulaz >> k1;
			ulaz >> k2;
			pk.Dodaj(k1);
			pk.Dodaj(k2);
			pk.izbaci(-1);
			pk.izbaci(2);
			pk.print();
		}

	}
	catch (exception e) {
		cout << e.what();
	}
	catch (...) {

	}

	
}