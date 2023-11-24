#include <iostream>
using namespace std;

class Roda
{
	int masa;
	int visina;
	int raspon_krila;
	int brzaba;

public:
	Roda() {
		masa = visina = raspon_krila = brzaba = 0;
	}
	Roda(int m, int v, int r, int z) {
		if (m <= 0 || v <= 0 || r <= 0 || z <= 0) throw exception("ULAZ NIJE VALIDAN!");
		else {
			masa = m; visina = v; raspon_krila = r; brzaba = z;
		}
	}
	~Roda() {}

	bool operator>(Roda& r) {

		if (masa > r.masa) return true;
		else if( masa == r.masa){
			if (brzaba > r.brzaba) return true;
			else if (brzaba == r.brzaba) {
				if (visina > r.visina) return true;
				else if (visina == r.visina) {
					if (raspon_krila > r.raspon_krila) return true;
				}
			}
		}
		return false;
	}
	
	bool operator == (Roda& r) {
		if (masa == r.masa && brzaba == r.brzaba && visina == r.visina && raspon_krila == r.raspon_krila) return true;
		return false;
	}
	bool operator != (Roda& r) {
		if (masa == r.masa && brzaba == r.brzaba && visina == r.visina && raspon_krila == r.raspon_krila) return false;
		return true;
	}

	Roda& operator= (const Roda& r) {
		if (this != &r) {
			masa = r.masa;
			brzaba = r.brzaba;
			visina = r.visina;
			raspon_krila = r.raspon_krila;
		}
		return *this;

	}

	friend istream& operator >>(istream& in, Roda& r) {
		// fali provera da li su veci od 0
		in >> r.masa >> r.visina >> r.raspon_krila >> r.brzaba;
		return in;
	}
	friend ostream& operator << (ostream& out, Roda& r) {
		out << r.masa << " " << r.visina << " " << r.raspon_krila << " " << r.brzaba;
		return out;
	}
};
