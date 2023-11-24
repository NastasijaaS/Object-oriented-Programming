#pragma once
class Predmet {

protected:
	int masa;
	double vrednost;
	
	virtual void setVrednost() = 0;

public:

	Predmet() {
		masa = 0;
		vrednost = 0;
	}
	~Predmet(){}
	double getVrednost() {
		return vrednost;
	}
	int getMasa() {
		return masa;
	}

	virtual void print() = 0;
};

