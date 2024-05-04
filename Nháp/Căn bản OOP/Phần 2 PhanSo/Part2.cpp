#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
private:
	int tu;
	int mau;

public:
	void Nhap();
	void Xuat();
	void RutGon();
};

int main() {

	PhanSo ps;
	ps.Nhap();
	cout << "Phan So ban dau: ";
	ps.Xuat();

	ps.RutGon();
	cout << "\nPhan So sau khi rut gon: ";
	ps.Xuat();

	return 1;
}

void PhanSo::Nhap() {
	cout << "Nhap gia tri cua tu so: ";
	cin >> tu;
	cout << "Nhap gia tri cua mau so: ";
	cin >> mau;
}

void PhanSo::Xuat() {
	cout << tu << "/" << mau;
}

void PhanSo::RutGon() {
	int a = abs(tu);
	int b = abs(mau);

	if (a == 0) {
		tu = tu / b;
		mau = mau / b;
	}
	else {
		while (a != b) {
			if (a > b) {
				a = a - b;
			}
			else {
				b = b - a;
			}
		}
		tu = tu / a;
		mau = mau / a;
	}
}