#pragma once
#include <iostream>
#include "Putovanje.h"
#include <fstream>
using namespace std;
class Letovanje : public Putovanje 
{
private:
	int prosecnatemperatura;
	int brojplaza;
	char* nazivmora;
public:
	Letovanje() : Putovanje()
	{
		prosecnatemperatura = 0;
		brojplaza = 0;
		nazivmora = nullptr;
	}
	Letovanje(char* n, int b, int c, int pt, int bp, char* nm) : Putovanje(n, b, c)
	{
		prosecnatemperatura = pt;
		brojplaza = bp;
		nazivmora = new char[strlen(nm) + 1];
		strcpy(nazivmora, nm);
	}
	~Letovanje() 
	{
		delete[] nazivmora;
	}

	int zanimljivosti()
	{
		if (prosecnatemperatura > 26)
			return (brojplaza * 0.8);
		else
			return(brojplaza * 0.6);
	}
	int cena()
	{
		return (brojnocenja * cenaponocenju);
	}
	void print()
	{
		cout << nazivdestinacije << " " << brojnocenja << " " << cenaponocenju << " " << prosecnatemperatura << " " << brojplaza << " " << nazivmora << endl;
	}
	void print(ofstream& out)
	{
		out << nazivdestinacije << " " << brojnocenja << " " << cenaponocenju << " " << prosecnatemperatura << " " << brojplaza << " " << nazivmora << endl;
	}
	/*int novacena()
	{
		cout << "Unesite novu cenu za nocenje: " << endl;
		cin >> cenaponocenju;
		return (brojnocenja * cenaponocenju);

	}*/

};

