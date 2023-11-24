#include <iostream>
#include <fstream>
#include "NIZ.h"
#include "Roda.h"
#include "Zaba.h"

using namespace std;

void main() {

	NIZ<Roda> A(5);
	try {
		fstream rode("roda.txt");
		rode >> A;
		rode.close();
		cout << A;
		A.obrisiElement(2);
		A.obrisiElement(7);
	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
	catch (...) {
	}
	cout << "\n";
	cout << A;

	NIZ<Zaba> B(7);
	fstream zabe("zaba.txt");
	zabe >> B;
	zabe.close();
	cout << "\n";
	cout << B;
	try {
		B.obrisiElement(5);
		B.obrisiElement(-5);
	}catch (exception& ex)
	{
		cout << ex.what();
	}
	catch (...) {
	}
	cout << "\n";
 	cout << B;

	system("pause");
}