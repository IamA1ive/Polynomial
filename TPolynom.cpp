#include "TPolynom.h"

TPolynom::TPolynom() {
	pFirst = new TMonom(0, -1, nullptr);
	pFirst->next = pFirst;
}
TPolynom::~TPolynom() {
	TMonom* prev = pFirst;
	TMonom* cur = prev->next;
	while (cur != pFirst) {
		prev->next = cur->next;
		delete cur;
		cur = prev->next;
	}
	delete pFirst;
}
void TPolynom::InsertMonom(double _koef, int _deg) {
	while (_deg < 0 || _deg > 999) {
		cout << "¬ведите корректное значение степени" << endl;
		cin >> _deg;
	}
	TMonom* prev;
	TMonom* cur;
	prev = pFirst;
	cur = prev->next;
	while (1) {
		if (_deg > cur->deg) {
			prev->next = new TMonom(_koef, _deg, cur);
			break;
		}
		else if (_deg < cur->deg) {
			prev = cur;
			cur = cur->next;
		}
		else {
			cur->koef += _koef;
			break;
		}
	}
}
void TPolynom::InsertPolynom() {
	TMonom* prev = pFirst;
	TMonom* cur = prev->next;
	while (cur != pFirst) {
		prev->next = cur->next;
		delete cur;
		cur = prev->next;
	}
	double _koef;
	int _deg;
	int i = 1;
	int res;
	cout << endl;
	do {
		res = 0;
		cout << "¬ведите коэффициент " << i << "-го монома " << "(0, чтобы завершить)" << endl;
		cin >> _koef;
		if (_koef == 0) break;
		do {
			cout << "¬ведите степень переменной X" << endl;
			cin >> _deg;
		} while (_deg < 0 || _deg > 9);
		res += _deg * 100;
		do {
			cout << "¬ведите степень переменной Y" << endl;
			cin >> _deg;
		} while (_deg < 0 || _deg > 9);
		res += _deg * 10;
		do {
			cout << "¬ведите степень переменной Z" << endl;
			cin >> _deg;
		} while (_deg < 0 || _deg > 9);
		res += _deg;
		InsertMonom(_koef, res);
		i++;
	} while (1);
}
void TPolynom::Print() {
	TMonom* cur;
	cur = pFirst->next;
	cout << endl;
	if (cur == pFirst) cout << '0' << endl;
	while (cur != pFirst) {
		cout << cur->koef;
		if (cur->deg / 100 != 0) {
			if (cur->deg / 100 != 1) cout << "*x^" << cur->deg / 100;
			else cout << "*x";
		}
		if ((cur->deg / 10) % 10 != 0) {
			if ((cur->deg / 10) % 10 != 1) cout << "*y^" << (cur->deg / 10) % 10;
			else cout << "*y";
		}
		if (cur->deg % 10 != 0) {
			if (cur->deg % 10 != 1) cout << "*z^" << cur->deg % 10;
			else cout << "*z";
		}
		cur = cur->next;
		if (cur != pFirst) {
			if (cur->koef > 0) cout << "+";
		}
	}
	cout << endl;
}
TPolynom::TPolynom(const TPolynom& poly) {
	TMonom* cur = poly.pFirst->next;
	pFirst = new TMonom(0, -1, nullptr);
	pFirst->next = pFirst;
	while (cur != poly.pFirst) {
		InsertMonom(cur->koef, cur->deg);
		cur = cur->next;
	}
}
TPolynom TPolynom::operator+(const TPolynom& poly) {
	TPolynom res;
	TMonom* cur1 = pFirst->next;
	TMonom* cur2 = poly.pFirst->next;
	while (cur1 != pFirst || cur2 != poly.pFirst) {
		if (cur1->deg < cur2->deg) {
			res.InsertMonom(cur2->koef, cur2->deg);
			cur2 = cur2->next;
		}
		else if (cur1->deg > cur2->deg) {
			res.InsertMonom(cur1->koef, cur1->deg);
			cur1 = cur1->next;
		}
		else {
			if (cur1->koef + cur2->koef != 0) {
				res.InsertMonom(cur1->koef + cur2->koef, cur1->deg);
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	return res;
}
TPolynom& TPolynom::operator=(const TPolynom& poly) {
	if (this == &poly) return *this;
	else {
		TMonom* cur = poly.pFirst->next;
		delete pFirst;
		pFirst = new TMonom(0, -1, nullptr);
		pFirst->next = pFirst;
		while (cur != poly.pFirst) {
			InsertMonom(cur->koef, cur->deg);
			cur = cur->next;
		}
	}
	return *this;
}
void TPolynom::Add(TPolynom& poly) {
	TMonom* prev1 = pFirst;
	TMonom* prev2 = poly.pFirst;
	TMonom* cur1 = prev1->next;
	TMonom* cur2 = prev2->next;
	while (cur2 != poly.pFirst) {
		if (cur2->deg > cur1->deg) {
			prev1->next = cur2;
			prev2->next = cur2->next;
			cur2->next = cur1;
			prev1 = cur2;
			cur2 = prev2->next;
		}
		else if (cur2->deg < cur1->deg) {
			prev1 = cur1;
			cur1 = cur1->next;
		}
		else {
			if (cur1->koef + cur2->koef != 0) {
				cur1->koef = cur1->koef + cur2->koef;
				prev1 = cur1;
				cur1 = cur1->next;
				prev2 = cur2;
				cur2 = cur2->next;
			}
			else {
				prev1->next = cur1->next;
				delete cur1;
				cur1 = prev1->next;
				prev2->next = cur2->next;
				cur2 = prev2->next;
			}
		}
	}
}