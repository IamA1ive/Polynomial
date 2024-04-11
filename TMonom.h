#pragma once
#include <iostream>
using namespace std;

class TMonom {
	double koef;
	int deg;
	TMonom* next;
public:
	TMonom(double _koef, int _deg, TMonom* _next);
	friend class TPolynom;
};

