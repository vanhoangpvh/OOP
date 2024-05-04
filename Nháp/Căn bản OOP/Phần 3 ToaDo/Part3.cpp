#include <iostream>
#include <cmath>

using namespace std;

class ToaDo {
private:
	double x;
	double y;

public:
	void NhapA();
	void NhapB();
	void XuatA();
	void XuatB();
	double KhoangCach(ToaDo);
};

int main() {
	ToaDo A;
	ToaDo B;
	A.NhapA();
	B.NhapB();
	A.XuatA();
	B.XuatB();
	double kq = A.KhoangCach(B);
	cout << "\nKhoang cach giua 2 diem la: " << kq;

	return 1;
}

void ToaDo::NhapA() {
	cout << "Nhap toa do cua xA: ";
	cin >> x;
	cout << "Nhap toa do cua yA: ";
	cin >> y;
}

void ToaDo::NhapB() {
	cout << "Nhap toa do cua xB: ";
	cin >> x;
	cout << "Nhap toa do cua yB: ";
	cin >> y;
}

void ToaDo::XuatA() {
	cout << "\nxA = " << x;
	cout << "\nyA = " << y;
}

void ToaDo::XuatB() {
	cout << "\nxB = " << x;
	cout << "\nyB = " << y;
}

double ToaDo::KhoangCach(ToaDo P) {
	return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
}