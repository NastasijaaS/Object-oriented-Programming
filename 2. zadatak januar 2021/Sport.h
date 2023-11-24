#pragma once
#include <iostream>

using namespace std;

class Sport {
private:
	int igraci;
	int rezerve;
	char* obuca;
	double budzet;
	double koefp;

	void kopiraj(const Sport& s) {
		igraci = s.igraci;
		rezerve = s.rezerve;
		budzet = s.budzet;
		koefp = s.koefp;
		obuca = new char[strlen(s.obuca + 1)];
		strcpy(obuca, s.obuca);
	}
public:
	Sport() { obuca = NULL; }
	Sport(int i, int r, char* o, double b, double k) {
		if (i > 20 || r > 20 || b > 50000 || k < 0 || k>1) throw exception("POGRESAN UNOS!");
		else {
			igraci = i; rezerve = r; budzet = b; koefp = k;
			obuca = new char[strlen(o) + 1];
			strcpy(obuca, o);
		}
	}
	Sport(const Sport& s) {
		kopiraj(s);
	}
	~Sport() {
		delete obuca;
	}

	double getVrednost() {
		return (igraci + rezerve) * budzet * koefp;
	}
	bool operator<(Sport& s) {
		if (this->getVrednost() < s.getVrednost()) return true;
		return false;
	}
	bool operator>(Sport& s) {
		if (this->getVrednost() > s.getVrednost()) return true;
		return false;
	}

	Sport& operator=(Sport& s) {
		if (this != &s) {
			kopiraj(s);
		}
		return *this;
	}

	friend istream&  operator>>(istream& in , Sport& s) {
		int i, r; double b, k; char o[20];
		in >> i >> r >> o>> b >> k;
		if (i > 20 || r > 20 || b > 50000 || k < 0 || k>1) throw exception("POGRESAN UNOS!");
		else {
			s.igraci = i; s.rezerve = r; s.budzet = b; s.koefp = k;
			s.obuca = new char[strlen(o) + 1];
			strcpy(s.obuca, o);
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Sport& s) {
		out << s.igraci << " " << s.rezerve << " " << s.obuca << " "<<s.budzet << " " << s.koefp <<endl;
		return out;
	}

	friend double operator+(Sport& s, double p) {
		return s.getVrednost() + p;
	}
};