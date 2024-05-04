#include <iostream>
#include <cmath>
using namespace std;

class CSoPhuc {
private:
	double a;
	double b;

public:
	friend istream& operator>>(istream& is, CSoPhuc& sp);
	friend ostream& operator<<(ostream& os, CSoPhuc& sp);
	CSoPhuc operator+(CSoPhuc sp);
	CSoPhuc operator-(CSoPhuc sp);
	CSoPhuc operator*(CSoPhuc sp);
	CSoPhuc operator/(CSoPhuc sp);
	CSoPhuc operator+=(CSoPhuc sp);
	CSoPhuc operator-=(CSoPhuc sp);
	CSoPhuc operator*=(CSoPhuc sp);
	CSoPhuc operator/=(CSoPhuc sp);
};

int main() {

	CSoPhuc sp1, sp2;

	cout << "Nhap 2 so phuc:\n";
	cin >> sp1 >> sp2;

	CSoPhuc tong, hieu, tich, thuong;
	tong = sp1 + sp2;
	hieu = sp1 - sp2;
	tich = sp1 * sp2;
	thuong = sp1 / sp2;

	cout << "Tong = " << tong;
	cout << "Hieu = " << hieu;
	cout << "Tich = " << tich;
	cout << "Thuong = " << thuong;

	sp1 += sp2;
	cout << sp1;
	sp1 -= sp2;
	cout << sp1;
	sp1 *= sp2;
	cout << sp1;
	sp1 /= sp2;
	cout << sp1;

	return 1;
}

istream& operator>>(istream& is, CSoPhuc& sp) {
	cout << "Nhap so phuc:\n";
	cout << "Nhap a: ";
	cin >> sp.a;
	cout << "Nhap b: ";
	cin >> sp.b;
	return is;
}

ostream& operator<<(ostream& os, CSoPhuc& sp) {
	cout << sp.a << " + " << sp.b << "i\n";
	return os;
}

CSoPhuc CSoPhuc::operator+(CSoPhuc sp) {
	CSoPhuc temp;
	temp.a = a + sp.a;
	temp.b = b + sp.b;
	return temp;
}

CSoPhuc CSoPhuc::operator-(CSoPhuc sp) {
	CSoPhuc temp;
	temp.a = a - sp.a;
	temp.b = b - sp.b;
	return temp;
}

CSoPhuc CSoPhuc::operator*(CSoPhuc sp) {
	CSoPhuc temp;
	temp.a = a * sp.a - b * sp.b;
	temp.b = a * sp.b + b * sp.a;
	return temp;
}

CSoPhuc CSoPhuc::operator/(CSoPhuc sp) {
	CSoPhuc temp;
	temp.a = (a * sp.a + b * sp.b) / (sp.a * sp.a + sp.b * sp.b);
	temp.b = (-a * sp.b + b * sp.a) / (sp.a * sp.a + sp.b * sp.b);
	return temp;
}

CSoPhuc CSoPhuc::operator+=(CSoPhuc ps) {
	*this = *this + ps;
	return *this;
}

CSoPhuc CSoPhuc::operator-=(CSoPhuc ps) {
	*this = *this - ps;
	return *this;
}

CSoPhuc CSoPhuc::operator*=(CSoPhuc ps) {
	*this = *this * ps;
	return*this;
}

CSoPhuc CSoPhuc::operator/= (CSoPhuc ps) {
	*this = *this / ps;
	return *this;
}