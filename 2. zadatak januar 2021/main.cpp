#include "Skola.h"
#include "Sport.h"
#include <iostream>
#include <fstream>

using namespace std;

void main() {

	Sport s1, s2, s3;
	int u1, u2, u3;
	Skola<Sport> skola1(3);
	Skola<int> skola2(10);
	try {
		fstream ulaz("sport.txt");
		if (ulaz.good()) {
			ulaz >> s1;//Sport *s1=new Sport(..) skola1.dodajAktivnost(s1);
			
			ulaz >> s2;
			ulaz >> s3;
			cout << s1.getVrednost() << endl;
			cout << s2.getVrednost() << endl;
			cout << s3.getVrednost() << endl;
			skola1.dodajAktivnost(s2);
			skola1.dodajAktivnost(s3);
			skola1.dodajAktivnost(s1);
			skola1.dodajAktivnost(s1);
			skola1.dodajAktivnost(s1);

		}
		skola1.print();
		cin >> u1 >> u2 >> u3;
		skola2.dodajAktivnost(u1);
		skola2.dodajAktivnost(u2);
		skola2.dodajAktivnost(u3);
		skola2.print();
		Sport min = skola1.najmanjevredna();
		Sport max = skola1.najvrednija();
		cout << min << endl;
		cout << max << endl;

		cout << skola1.prosecnaVrednost() << endl;
		cout << skola2.prosecnaVrednost() << endl;

	}
	catch (exception e) {
		cout << e.what();
	}
	catch (...) {

	}



}