#pragma once
#include <iostream>
#include <fstream>
using namespace std;

 class Vozilo {
 protected:
     char* naziv;
     char* regoz;
     double maksbr;
     double potrosnja;
 public:
     Vozilo()
     {

     }
     virtual ~ Vozilo()
     {

     }
     virtual void upisi(ofstream &of)
     {
         of << naziv << regoz << maksbr << potrosnja;
     }

     virtual void procitaj(ifstream& i)
     {
         i >> maksbr >> potrosnja;
     }

     virtual int uporedi(Vozilo* v) = 0;

     virtual double getSpec() = 0;
     virtual void print()
     {
         cout << naziv << regoz << maksbr << potrosnja;
     }
};
