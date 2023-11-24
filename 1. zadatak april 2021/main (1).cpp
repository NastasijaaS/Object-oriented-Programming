#include "Kondenzator.h"
#include "Otpornik.h"
#include "Proizvod.h"
#include "Traka.h"

void main() {

	Kondenzator* k1 = new Kondenzator((char*)"10000", 10);
	Kondenzator* k2 = new Kondenzator((char*)"10001", 1);
	Kondenzator* k3 = new Kondenzator((char*)"10002", 0);
	Kondenzator* k4 = new Kondenzator((char*)"10003", 3);
	Otpornik* o1 = new Otpornik((char*)"20000", 1, -20, 35);
	Otpornik* o2 = new Otpornik((char*)"20001", 10, -20, 35);
	Otpornik* o3 = new Otpornik((char*)"20002", 21, -20, 35);
	Otpornik* o4 = new Otpornik((char*)"20003", 0, -20, 35);
	Traka t(5);
	t.dodaj(k1);
	t.dodaj(k2);
	t.dodaj(k3);
	t.dodaj(k4);
	t.dodaj(o1);
	t.dodaj(o4);
	t.print();
	cout << t.brojDefektnih()<< endl;
	cout << t.brojPraznihMesta() << endl;
	t.ukloni();
	t.print();
	t.ukloni();
	cout << endl;
	t.print();
	t.zameniILIukloni((char*)"10002", o3);
	t.print();
	cout << endl;
	t.zameniILIukloni((char*)"20003", o2);
	t.print();
	system("pause");
}
