#include <iostream>
using namespace std;

class Zaba {

	int pege;
	int masa;
	int muva;

public:
	Zaba() {
		pege = 0; masa = 0; muva = 0;
	}
	Zaba(int p, int m, int mu) {
		if (p <= 0 || m <= 0 || mu <= 0) throw exception("ULAZ NIJE VALIDAN!");
		else
		{
			pege = p; masa = m; muva = mu;
		}
	}
	~Zaba() {}

	bool operator > (Zaba& z) {
		if (masa > z.masa) return true;
		else if (masa == z.masa)
			if (muva > z.muva)return true;
			else if (muva ==  z.muva)
				if (pege > z.pege) return true;
		return false;
	}

	bool operator != (Zaba & z) {
		if (masa == z.masa && muva == z.muva && pege == z.pege) return false;
		return true;
	}

	Zaba& operator = (Zaba& z) {
		masa = z.masa;
		muva = z.muva;
		pege = z.pege;
		return *this;
	}

	friend istream& operator >>(istream& in, Zaba& z) {
		// fali provera da li su veci od 0
		in >> z.masa >> z.muva >>z.pege;
		return in;
	}
	friend ostream& operator << (ostream& out, Zaba& z) {
		out << z.masa << " " << z.muva << " " << z.pege;
		return out;
	}
};