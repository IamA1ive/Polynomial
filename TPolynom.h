#pragma once
#include <iostream>
#include "TMonom.h"
class TPolynom {
	TMonom* pFirst;
	void InsertMonom(double _koef, int _deg);
public:
	TPolynom();
	~TPolynom();
	void InsertPolynom();
	void Print();
	TPolynom(const TPolynom& poly);
	TPolynom operator+(const TPolynom& poly);
	TPolynom& operator=(const TPolynom& poly);
	void Add(TPolynom& poly);
};
