#include "Sablon.h"
#include "Roda.h"
#include "Zaba.h"
#include <iostream>	
using namespace std;

void main()
{
	try
	{
		Sablon<Zaba>* s1 = new Sablon<Zaba>(6);
		Zaba* z1 = new Zaba(10, 80, 15);
		Zaba* z2 = new Zaba(12, 100, 36);
		Zaba* z3 = new Zaba(5, 40, 10);
		Zaba* z4 = new Zaba(80, 10, 60);
		
		s1->dodaj(*z4);
		s1->dodaj(*z1);
		s1->dodaj(*z2);
		s1->dodaj(*z3);
		// 10,80,100,40
		s1->printALL();

		cout <<endl<< "========================" << endl;
		s1->izbrisi(1);
		s1->printALL();
		cout << endl << "========================" << endl;
		cout << s1->ukupnaMasa();
		delete s1;
	}
	catch (const char* eror)
	{
		cout << eror;
	}
}