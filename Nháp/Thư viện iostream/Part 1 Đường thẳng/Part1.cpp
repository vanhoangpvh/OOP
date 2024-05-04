#include <iostream>

using namespace std;

class CDuongThang {
private:
	double a;
	double b;
	double c;

public:
	friend istream& operator>>(istream& is, CDuongThang& x);
	friend ostream& operator<<(ostream& os, CDuongThang& x);
};

int main() {
	CDuongThang dt1,dt2,dt3;
	cin >> dt1 >> dt2 >> dt3;
	cout << dt1 << dt2 << dt3;

	return 1;
}

istream& operator>>(istream& is, CDuongThang& x) {
	cout << "Nhap he so a: ";
	is >> x.a;
	cout << "Nhap he so b: ";
	is >> x.b;
	cout << "Nhap he so c: ";
	is >> x.c;
	return is;
}

ostream& operator<<(ostream& os, CDuongThang& x) {
	os << "\nCac he so cua duong thang la:\n";
	os << "a = " << x.a;
	os << "\nb = " << x.b;
	os << "\nc = " << x.c;

	return os;
}