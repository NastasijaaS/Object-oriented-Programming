#pragma once
#include <iostream>
#include "Teren.h"
using namespace std;

class BocniTeren :public Teren
{
private:
	int brojmestauredu;
	int brredskuplji;
	int reddokogskup;
	int procskuplja;
public:
	BocniTeren() :Teren()
	{
		brojmestauredu = 0;
		brredskuplji = 0;
		reddokogskup = 0;
		procskuplja = 0;
	}
	BocniTeren(int j, char* n, int b, int jef, int sku, int bmu, int brs, int rs, int ps) :Teren(j, n, b, jef, sku)
	{
		brojmestauredu = bmu;
		brredskuplji = brs;
		reddokogskup = rs;
		procskuplja = ps;
	}
	~BocniTeren()
	{
	}
	void print()
	{
		Teren::print();
		cout << brojmestauredu << brredskuplji << reddokogskup;
	}
};
