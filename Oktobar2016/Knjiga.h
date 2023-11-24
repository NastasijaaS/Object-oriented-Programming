#pragma once
#include <iostream>
using namespace std;

class Knjiga
{
private:
	char* naslov;
	char* autor;
	int brojStr;
	int tiraz;
public:
	Knjiga()
	{
		naslov = nullptr;
		autor = nullptr;
		brojStr = tiraz = 0;
	}
	Knjiga(char* n, char* a, int broj, int t)
	{
		naslov = new char[strlen(n) + 1];
		strcpy(naslov, n);
		autor = new char[strlen(a) + 1];
		strcpy(autor, a);
		brojStr = broj;
		if (t < 200)
		{
			tiraz = 200;
		}
		else
		{
			tiraz = t;
		}
	}
	~Knjiga()
	{
		delete[] naslov;
		delete[] autor;
	}
	bool operator>(Knjiga& obj)
	{
		/*if (strcmp(this->naslov, obj.naslov) < 0)
		{
			return true;
		}
		else if (strcmp(this->naslov, obj.naslov) == 0 && strcmp(this->autor, obj.autor) < 0)
		{
			return true;
		}
		else if (strcmp(this->naslov, obj.naslov) == 0 && strcmp(this->autor, obj.autor) == 0 && this->brojStr > obj.brojStr)
		{
			return true;
		}
		else if (strcmp(this->naslov, obj.naslov) == 0 && strcmp(this->autor, obj.autor) == 0 && this->brojStr == obj.brojStr && this->tiraz > obj.tiraz)
			return true;
		else
			return false;*/
		if (strcmp(this->naslov, obj.naslov) > 0)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) > 0)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojStr > obj.brojStr)
			return true;
		else if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojStr == obj.brojStr && tiraz > obj.tiraz)
			return true;
		else
			return false;
	}
	bool operator==(Knjiga& obj)
	{
		if (strcmp(naslov, obj.naslov) == 0 && strcmp(autor, obj.autor) == 0 && brojStr == obj.brojStr && tiraz == obj.tiraz)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& izlaz, const Knjiga& obj)
	{
		izlaz << "Naslov:" << obj.naslov << " Autor:" << obj.autor << "  Broj strana:" << obj.brojStr << "  i tiraz:" << obj.tiraz << endl;
		return izlaz;
	}
};