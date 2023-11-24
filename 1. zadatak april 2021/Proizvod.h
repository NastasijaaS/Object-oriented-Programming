#pragma once
#include <iostream>
using namespace std;

class Proizvod
{
protected:
	char* tip;
	char* barkod;
public:
	Proizvod() {};
	~Proizvod() {};
	char* getKod() { return barkod; }
	char* getTip() { return tip; }
	virtual bool ispravan() = 0;
	virtual void print() = 0;
	virtual void print(ofstream& out) = 0; //upis u fajl
};
