#include <iostream>
#include <cmath>

using namespace std;

class CPhanSo {
private:
	double tu;
	double mau;

public:
	friend istream& operator>>(istream& is, CPhanSo& ps);
	friend ostream& operator<<(ostream& os, CPhanSo& ps);
	void RutGon();
	CPhanSo& operator+ (const CPhanSo&);
	CPhanSo& operator- (const CPhanSo&);
	CPhanSo& operator* (const CPhanSo&);
	CPhanSo& operator/ (const CPhanSo&);
	CPhanSo& operator++(int);
	CPhanSo& operator--(int);
	CPhanSo& operator+=(const CPhanSo&);
	CPhanSo& operator-=(const CPhanSo&);
	CPhanSo& operator*=(const CPhanSo&);
	CPhanSo& operator/=(const CPhanSo&);

	//~CPhanSo();
};

int main() {

	CPhanSo ps1,ps2;
	cout << "Nhap 2 phan so:\n";
	cin >> ps1 >> ps2;

	CPhanSo tong, hieu, tich, thuong;
	tong = ps1 + ps2;
	hieu = ps1 - ps2;
	tich = ps1 * ps2;
	thuong = ps1 / ps2;

	cout << "Tong = " << tong;
	cout << "Hieu = " << hieu;
	cout << "Tich = " << tich;
	cout << "Thuong = " << thuong;

	ps1++;
	ps1.RutGon();
	cout << ps1;
	ps1--;
	ps1.RutGon();
	cout << ps1;
	ps1+=ps2;
	ps1.RutGon();
	cout << ps1;
	ps1-=ps2;
	ps1.RutGon();
	cout << ps1;
	ps1*=ps2;
	ps1.RutGon();
	cout << ps1;
	ps1/=ps2;
	ps1.RutGon();
	cout << ps1;
	return 1;
}

istream& operator>>(istream& is, CPhanSo& ps) {
	cout << "Nhap phan so:\n";
	cout << "Nhap tu: ";
	cin >> ps.tu;
	cout << "Nhap mau: ";
	cin >> ps.mau;

	return is;
}

ostream& operator<<(ostream& os, CPhanSo& ps) {
	cout << ps.tu << "/" << ps.mau << "\n";
	return os;
}

CPhanSo& CPhanSo::operator+(const CPhanSo& ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau + ps.tu * mau;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo& CPhanSo::operator-(const CPhanSo& ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau - mau * ps.tu;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo& CPhanSo::operator*(const CPhanSo& ps) {
	CPhanSo temp;
	temp.tu = tu * ps.tu;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo& CPhanSo::operator/(const CPhanSo& ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau;
	temp.mau = mau * ps.tu;
	return temp;
}

CPhanSo& CPhanSo:: operator++(int) {
	CPhanSo temp;
	temp.tu = tu * mau + mau * mau;
	temp.mau = mau * mau;
	*this = temp;
	return *this;
}

CPhanSo& CPhanSo::operator--(int) {
	CPhanSo temp;
	temp.tu = tu * mau - mau * mau;
	temp.mau = mau * mau;
	*this = temp;
	return *this;
}

CPhanSo& CPhanSo:: operator+=(const CPhanSo& ps) {
	*this = *this + ps;
	return *this;
}

CPhanSo& CPhanSo::operator-=(const CPhanSo& ps) {
	tu = tu * ps.mau - mau * ps.tu;
	mau = mau * ps.mau;
	return *this;
}

CPhanSo& CPhanSo::operator*=(const CPhanSo& ps) {
	*this = *this * ps;
	return *this;
}

CPhanSo& CPhanSo::operator/=(const CPhanSo& ps) {
	*this = *this / ps;
	return *this;
}

void CPhanSo::RutGon() {
	int a = abs(tu);
	int b = abs(mau);

	if (a == 0) {
		mau = 1;
		return;
	}

	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else if (a < b) {
			b = b - a;
		}
	}

	tu = tu / a;
	mau = mau / a;

}