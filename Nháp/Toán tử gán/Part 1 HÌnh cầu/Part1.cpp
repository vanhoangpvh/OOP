#include <iostream>

using namespace std;

class CDiem {
private:
	double x;
	double y;
	double z;

public:
	friend istream& operator>>(istream& is, CDiem& diem);
	friend ostream& operator<<(ostream& os, CDiem& diem);
	CDiem& operator=(const CDiem& diem);
	friend class CHinhCau;

	~CDiem();
};

class CHinhCau {
private:
	CDiem o;
	double r;

public:
	friend istream& operator>>(istream& is, CHinhCau& hc);
	friend ostream& operator<<(ostream& os, CHinhCau& hc);
	CHinhCau();
	CHinhCau& operator=(const CHinhCau&);

	~CHinhCau();
};

int main() {

	CHinhCau hc1;

	cin >> hc1;

	CHinhCau hc2;
	hc2 = hc1;
	cout << hc2;

	return 1;
}

istream& operator>>(istream& is, CDiem& diem) {
	cout << "Nhap x: ";
	cin >> diem.x;
	cout << "Nhap y: ";
	cin >> diem.y;
	cout << "Nhap z: ";
	cin >> diem.z;

	return is;
}

istream& operator>>(istream& is, CHinhCau& hc) {
	cout << "Nhap toa do diem:\n";
	cin >> hc.o;
	cout << "Nhap ban kinh hinh cau: ";
	cin >> hc.r;

	return is;
}

ostream& operator<<(ostream& os, CDiem& diem) {
	cout << "(" << diem.x << "," << diem.y << ","<<diem.z<<")";

	return os;
}

ostream& operator<<(ostream& os, CHinhCau& hc) {
	cout << "Hinh cau co toa do O " << hc.o << "; ban kinh R = " << hc.r;

	return os;
}

CDiem& CDiem::operator=(const CDiem& diem) {
	x = diem.x;
	y = diem.y;
	z = diem.z;

	return *this;
}

CHinhCau& CHinhCau::operator=(const CHinhCau& hc) {
	o = hc.o;
	r = hc.r;

	return *this;
}

CHinhCau::CHinhCau() {
	o.x = 0;
	o.y = 0;
	r = 0;
}

CDiem::~CDiem() {
	cout << "\nDa pha huy diem";
}

CHinhCau::~CHinhCau() {
	cout << "\nDa pha huy hinh cau";
}