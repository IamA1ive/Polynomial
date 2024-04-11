#include <iostream>
#include <locale.h>
#include "TMonom.h"
#include "TPolynom.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	TPolynom M1, M2, M3;

	M1.InsertPolynom();
	M1.Print();
	M2.InsertPolynom();
	M2.Print();
	(M1 + M2).Print();
	M3 = M1 + M2;
	M1.Add(M2);
	M2.Print();
	M3.Print();

	return 0;
}