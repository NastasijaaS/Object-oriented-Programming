#pragma once
#include <iostream>
#include "Teren.h"
using namespace std;

class OkruzenTeren : public Teren
{
private:
	int bocnatribina;
	double procenatskupoce;
public:
	OkruzenTeren() :Teren()
	{
		bocnatribina = 0;
		procenatskupoce = 0;
	}
	OkruzenTeren(int j, char* n, int b, int jef, int sku, int boc, double proc) :Teren(j, n, b, jef, sku)
	{
		bocnatribina = boc;
		procenatskupoce = proc;
	}
	~OkruzenTeren(){}
	void print()
	{
		Teren::print();
		cout << bocnatribina << procenatskupoce;
	}

};
