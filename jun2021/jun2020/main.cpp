#pragma once
#include "Automobil.h"
#include "Vozilo.h"
#include "VozniPark.h"
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	VozniPark v1;
	VozniPark v2;
	v1.procitaj( (char*)"automobil.txt");
	v2.procitaj((char*)"kamion.txt");

	v1.sort();
	v2.sort();

	v1.upisi((char*)"automobil2.txt");
	v2.upisi((char*)"kamion2.txt");

	Automobil* a = new Automobil();
	a = v1.najveci;
	a->print();


	


}