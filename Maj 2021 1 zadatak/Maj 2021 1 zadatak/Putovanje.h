#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Putovanje
{
protected:
	char* nazivdestinacije;
	int brojnocenja;
	int cenaponocenju;
public:
	Putovanje()
	{
		nazivdestinacije = nullptr;
		brojnocenja = 0;
		cenaponocenju = 0;
	}
	Putovanje(char* n, int b, int c)
	{
		nazivdestinacije = new char[strlen(n) + 1];
		strcpy(nazivdestinacije, n);
		brojnocenja = b;
		cenaponocenju = c;
	}
	virtual ~Putovanje()
	{
		delete[] nazivdestinacije;
	}
	virtual void print() = 0;
	virtual int zanimljivosti() = 0;
	virtual int cena() = 0;
	virtual void print(ofstream& out) = 0;
	/*virtual int novacena() = 0;*/
	void SetCenaNocenja(int cenap)
	{
		cenaponocenju = cenap;
	}
};

