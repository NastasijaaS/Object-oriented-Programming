#pragma once
#include<iostream>
using namespace std;
class Salon
{
protected:
	char* naziv;
	int br_zaposlenih;
	double x, y;
	int prodata_vozila;
	double efikasnost;

	virtual void setEfikasnost() = 0;
	

public:
	virtual void povecajProdaju(int br_kola, char tip) = 0;
	double rastojanje(double xx, double yy) {
		return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
	}
	virtual int getProdato() = 0;
	virtual void print() = 0;
	virtual int getZaposleni() = 0;
	double getEfikasnost() {
		return efikasnost;
	}

};
