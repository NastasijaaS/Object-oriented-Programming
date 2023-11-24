#pragma once
#include <iostream>
using namespace std;

template <class T>
class Skola {
private:
	T* sale;
	int n, zauzeto;

public:
	Skola() {
		n = 0; zauzeto = 0;
	}
	Skola(int nn) {
		n = nn;
		sale = new T[n];
		zauzeto = 0;
	}
	void dodajAktivnost(T* aktivnost) {
		if (zauzeto == n) throw exception("SVE SALE SU ZAUZETE!");
		else if (zauzeto == 0) {
			sale[zauzeto++] = aktivnost;
		}
		else {
			bool smesteno = false;
			int index = 0;
			for (int i = 0; i < zauzeto && !smesteno; i++) {
				if (sale[i] < aktivnost) {
					smesteno = true;
					index = i;
				}
			}if (smesteno == false) {
				sale[zauzeto++] = aktivnost;
			}
			else {
				for (int i = zauzeto-1; i >= index; i--) {
					sale[i + 1] = sale[i];
				}
				sale[index] = aktivnost;
				zauzeto++;
			}
		}
	}
	void izbaciAktivnost(int index) {
		int i = index;
		while (i < zauzeto) {
			sale[i] = sale[i++];
		}
		zauzeto--;
	}

	double prosecnaVrednost() {
		double p = 0; 
		for (int i = 0; i < zauzeto; i++) {
			p = sale[i] + p;
		}
		return p / zauzeto;
	}
	
	void print() {
		for (int i = 0; i < zauzeto; i++) {
			cout << sale[i];
		}
	}

	T& najvrednija() {
		return sale[0];

		/*T* max = new T(sale[0]);
		return *max;*/
		
	}
	T& najmanjevredna() {
		return sale[zauzeto - 1];
		/*T* max = new T(sale[zauzeto-1]);
		return *max;*/
	}

}; 