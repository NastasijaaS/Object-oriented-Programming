#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Knjiga
{
private:
	char* naslov;
	char* autor;
	int tiraz;
	int brojstrana;
	void kopiraj(const Knjiga& k)
	{
		naslov = new char[strlen(k.naslov) + 1];
		strcpy(naslov, k.naslov);
		autor = new char[strlen(k.autor) + 1];
		strcpy(autor, k.autor);
		tiraz = k.tiraz;
		brojstrana = k.brojstrana;
	}
public:
	Knjiga()
	{
		naslov = nullptr;
		autor = nullptr;
		brojstrana = tiraz = 0;
	}
	Knjiga(char *n,char *a,int t,int b)
	{
		naslov = new char[strlen(n) + 1];
		strcpy(naslov, n);
		autor = new char[strlen(a) + 1];
		strcpy(autor, a);
		if (t < 200)
		{
			tiraz = 200;
		}
		else
		{
			tiraz = t;
		}
		
		if (b < 0)
		{
			throw "pogresan unos";
		}
		else
			brojstrana = b;
	}
	~Knjiga()
	{
		delete[] naslov;
		delete[] autor;
	}
	Knjiga(const Knjiga& k)
	{
		kopiraj(k);
	}
	Knjiga& operator=(const Knjiga& k)
	{
		if (this != &k)
		{
			kopiraj(k);
		}
		return *this;
	}
	bool operator>(Knjiga& obj)
	{
		if (strcmp(naslov, obj.naslov) > 0)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) > 0)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojstrana > obj.brojstrana)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojstrana == obj.brojstrana && tiraz > obj.tiraz)
			return true;
		else
			return false;
	}
	bool operator==(Knjiga& obj)
	{
		if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojstrana == obj.brojstrana && tiraz == obj.tiraz)
			return true;
		else
			return false;
	}
	friend istream& operator >> (istream& in, Knjiga& k)
	{
		int b, t; 
		char a[20];
		char n[20];
		in >> b >> t >> a >> n;
		k.naslov = new char[strlen(n) + 1];
		strcpy(k.naslov, n);
		k.autor = new char[strlen(a) + 1];
		strcpy(k.autor, a);
		if (t < 200)
		{
			k.tiraz = 200;
		}
		else
		{
			k.tiraz = t;
		}

		if (b < 0)
		{
			throw "pogresan unos";
		}
		else
			k.brojstrana = b;
		return in;
	}
	friend ostream& operator << (ostream& out, Knjiga& k)
	{
		out << k.autor << k.brojstrana << k.naslov;
		return out;
	}
};