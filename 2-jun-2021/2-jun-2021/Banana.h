#pragma once




class Banana {

private:
	int tezina;
	bool zrela;
	bool trula;

public:
	Banana() {

	}
	Banana(int t, bool z, bool tr) {
		 trula = tr;
		 zrela = z;
		 tezina = t;
		 if (tr) tezina = -1;
	}
	~Banana(){}
	friend int operator+ (int a, Banana b) {
		return a + b.tezina;
	}
	friend double operator*(double a, Banana b) {
		return a * b.tezina;
	}

};

