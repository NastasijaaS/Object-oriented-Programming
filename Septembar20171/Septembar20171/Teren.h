#pragma once
#include <iostream>
using namespace std;

class Teren
{
protected:
	int jedbroj;
	char* naziv;
	int brojmesta;
	int jeftinijekarte;// broj prodatih
	int skupljekarte;
public:
	Teren()
	{
		jedbroj = 0;
		naziv = nullptr;
		brojmesta = jeftinijekarte = skupljekarte = 0;
	}
	Teren(int j, char* n, int b, int jef, int sku)
	{
		jedbroj = j;
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);
		brojmesta = b;
		jeftinijekarte = jef;
		skupljekarte = sku;
	}
	virtual ~Teren()
	{
		delete[]naziv;
	}
	virtual void print()
	{
		cout << naziv << jedbroj << brojmesta;
	}
	int getbr()
	{
		return jedbroj;
	}
	int getBrmesta()
	{
		return brojmesta;
	}
	int getJef()
	{
		return jeftinijekarte;
	}
	int getSkup()
	{
		return skupljekarte;
	}
	void Setbrmesta()
	{
		brojmesta = brojmesta + 1;
	}
	void SetJef()
	{
		jeftinijekarte = jeftinijekarte + 1;
	}
	void SetSkup()
	{
		skupljekarte = skupljekarte + 1;
	}
	int ukupanBrojkarata()
	{
		return jeftinijekarte + skupljekarte;
	}
	double zarada(int cena)
	{
		return jeftinijekarte * cena;
	}
};
