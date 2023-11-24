#pragma once
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
	int brojindeksa;
	char* licnipodaci;
	double prosocena;
	void kopiraj(const Student& s)
	{
		brojindeksa = s.brojindeksa;
		licnipodaci = new char[strlen(s.licnipodaci) + 1];
		strcpy(licnipodaci, s.licnipodaci);
		prosocena = s.prosocena;
	}
public:
	Student() {}
	Student(int b, char* l, double p)
	{
		brojindeksa = b;
		prosocena = p;
		licnipodaci = new char[strlen(l) + 1];
		strcpy(licnipodaci, l);
	}
	~Student()
	{
		delete licnipodaci;
	}
	Student(const Student& s)
	{
		kopiraj(s);
	}
	Student &operator=(Student& s)
	{
		if (this != &s)
		{
			kopiraj(s);
		}
		else
			return *this;
	}

	bool operator>(Student& s) //nisam sigurna za ovo sta bi bilo da stavim s.brojindeksa>this->brojindeksa ne znam u funkciji koji mi je levi koji desni
	{
		if (this->brojindeksa > s.brojindeksa) return true;
		else
			return false;
	}
	bool operator<(Student& s)
	{
		if (this->brojindeksa < s.brojindeksa) return true;
		else
			return false;
	}
	void print()
	{
		cout << licnipodaci << brojindeksa;
	}

	friend istream& operator>>(istream& in, Student& s)
	{
		int b; double p; char l[20];
		in >> b >> p >> l;
		s.brojindeksa = b;
		s.licnipodaci = new char[strlen(l) + 1];
		strcpy(s.licnipodaci, l);
		s.prosocena = p;
		return in;
	}
	friend ostream& operator <<(ostream& out, Student& s)
	{
		out << s.brojindeksa << s.licnipodaci << s.prosocena;
		return out;
	}

};