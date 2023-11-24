#include <iostream>
#include <fstream>
#include "LabVezbe.h"
#include "Student.h"
using namespace std;

void main()
{
	Student s1, s2, s3, s4, s5;
	int k1, k2, k3, k4, k5;
	LabVezbe <Student> spisak1;
	LabVezbe <int> spisak2;
	try
	{
		fstream ulaz("spisak.txt");
		if (ulaz.good())
		{
			ulaz >> s1;
			ulaz >> s2;
			ulaz >> s3;
			ulaz >> s4;
			ulaz >> s5;
			spisak1.dodaj(s1);
			spisak1.dodaj(s2);
			spisak1.dodaj(s3);
			spisak1.dodaj(s4);
			spisak1.dodaj(s5);
		}
		else
			throw exception("nije moguce ucitavanje"); //nisam sig za ovo
		spisak1.obrisi(2);
		Student pom;
		pom = spisak1.vratipodatak(17955);
		spisak1.razlika(s3, s5);
		spisak1.zamenamesta();
		Student pom1;
		Student pom2;
		spisak1.minmax(&pom1, &pom2); //i za ovo
		cout << pom1;
		cout << pom2;
		fstream izlaz("spisak1.txt");
		if (izlaz.good())
		{
			//kako izlaz kad sam obrisala 1 i njega sad ne upisujem ne moze
			// izlaz<<s1; 
			//izlaz<<s2;
		}


	}
	catch (exception e) {
		cout << e.what();
	}
	catch (...) {

	}
}


