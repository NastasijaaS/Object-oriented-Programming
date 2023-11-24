#include "Distributer.h"
#include "SalonPiDVh.h"
#include "SalonPV.h"
int main() {
    Distributer* d = new Distributer(10);
    char* naziv = new char[30];
    SalonPV* ps1 = new SalonPV(20, 32, 33, 18);
    SalonPiDV* pd1 = new SalonPiDV(37, 33, 80, 14, 12, 13);
    SalonPiDV* pd2 = new SalonPiDV(27, 43, 90, 24, 20, 33);
   
    SalonPV* ps2 = new SalonPV( 22, 28, 39, 20);
   // SalonPV* ps3 = new SalonPV( 27, 14, 38, 14);
    d->dodaj(*ps1);
    d->dodaj(*ps2);
    d->dodaj(*pd1);
    d->dodaj(*pd2);
   // d->dodaj(*ps3);
    d->printALL();
    cout << "---------------------------" << endl;
    strcpy(naziv, "Salon putnickih i dostavnih vozila");
    d->uvecaj(2,naziv, 50);
    d->printALL();
    cout << "---------------------------" << endl;
    strcpy(naziv, "Salon putnickih vozila");
    d->uvecaj(2, naziv, 100);
    cout <<endl<< "---------------------------" << endl;
    cout<<d->brojObjekata(25);
    cout << endl<<"---------------------------" << endl;
    cout <<endl<< "Ukupan broj prodatih vozila " << d->ukupanBrojProdatih() << endl;
    cout << endl<<"---------------------------" << endl;
    d->izbrisi(2);
    d->printALL();
    
   // cout << d->rastojanje(42, 20);
    delete d;
    return 0;
}