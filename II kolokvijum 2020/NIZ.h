#include <istream>

using namespace std;

template <class T>
class NIZ {

	T* a;
	int n; 
	int zauzeto;

	bool proveriIspravnost(T& el) {

		if (zauzeto == n && zauzeto !=0) {
			throw exception("NIZ je pun!");
			return false;
		}

		int i = 0;
		for (; i < zauzeto && a[i] != el; i++);

		if (i == zauzeto) return true;

		throw exception("Element vec postoji!");
		return false;

	}

public:

	NIZ() {
		a = 0;
		n = 0;
	}
	NIZ(int brel) {
		n = brel;
		a = new T[n];
		zauzeto = 0;
	}
	~NIZ() {
		delete[] a;
	}


	void dodajElement(T& el) {

		bool p = proveriIspravnost(el);
		if (p)
		{
			int i = 0;
			for (; i<zauzeto && el > a[i]; i++); //trazenje pozicije
			
			for (int j = zauzeto; j > i; j--) { //pomeranje elemenata
				a[j] = a[j - 1];
			}
			a[i] = el;
			zauzeto++;
		}
	}

	void obrisiElement(int index) {

		if (zauzeto == 0) throw exception("NIZ je prazan!");
		else if (index >= zauzeto || index < 0) throw exception("Odabreni element ne postoji!");
		else
		{
			for (int i = index; i < zauzeto - 1; i++) 
				a[i] = a[i + 1];
			zauzeto = zauzeto-1;
		}
	}

	friend istream& operator >> <>(istream& in, NIZ<T>& niz);
	friend ostream& operator << <>(ostream& out, NIZ<T>& niz);
};

template <class T>
 istream& operator >> (istream& in, NIZ<T>& niz){

	T el;
	for (int i = 0; i < niz.n; i++) {
		in >> el;
		niz.dodajElement(el);
	}
	return in;

}

template <class T>
ostream& operator << (ostream& out, NIZ<T>& niz) {

	for (int i = 0; i < niz.zauzeto; i++) {
		out << niz.a[i] << endl;
	}
	return out;
}
