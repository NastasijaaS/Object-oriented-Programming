#pragma once
#include <iostream>
#include "Putovanje.h"
#include <fstream>
using namespace std;
class ObilazakGrada :  public Putovanje
{
private:
	int brojatrakcija;
	int cenaprevoza;
public:
	ObilazakGrada() : Putovanje()
	{
		brojatrakcija = 0;
		cenaprevoza = 0;
	}
	ObilazakGrada(char* n, int b, int c, int bbr, int ccp) : Putovanje(n, b, c)
	{
		brojatrakcija = bbr;
		cenaprevoza = ccp;
	}
	~ObilazakGrada()
	{

	}
	int zanimljivosti()
	{
		return brojatrakcija;
	}
	
	int cena()
	{
		return ((brojnocenja * cenaponocenju) + cenaprevoza);
	}
	void print()
	{
		cout << nazivdestinacije << " " << brojnocenja << " " << cenaponocenju << " " << brojatrakcija << " " << cenaprevoza<< endl;
	}
	void print(ostream& out)
	{
		out << nazivdestinacije << " " << brojnocenja << " " << cenaponocenju << " " << brojatrakcija << " " << cenaprevoza  << endl;
	//}
	//int novacena()
	//{
	//	cout << "Unesite novu cenu za nocenje: " << endl;
	//	cin >> cenaponocenju;
	//	cout << "Unesite novu cenu za prevoz: " << endl;
	//	cin >> cenaprevoza;
	//	return ((brojnocenja * cenaponocenju) + cenaprevoza);

	//}
};

