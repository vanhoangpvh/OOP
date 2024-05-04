#include <iostream>
#include <cmath>

using namespace std;

class CDiem {
private:
	double x;
	double y;

public:
	CDiem();
	friend istream& operator>>(istream& is, CDiem& diem);
	friend ostream& operator<<(ostream& os, CDiem& diem);
	double KhoangCach(CDiem);
	bool operator>(const CDiem&);
	bool operator<(const CDiem&);
	bool operator=(const CDiem&);
};

int main() {
	CDiem diem1, diem2;
	cout << "Nhap 2 diem can so sanh:\n";
	cin >> diem1 >> diem2;

	if (diem1 > diem2) {
		cout << "Diem co toa do " << diem1 << " lon hon diem co toa do " << diem2;
	}
	else if (diem1 < diem2) {
		cout<< "Diem co toa do " << diem2 << " lon hon diem co toa do " << diem1;
	}
	else {
		cout << "2 diem co toa do bang nhau";
	}

	return 1;
}

CDiem::CDiem() {
	x = 0;
	y = 0;
}

istream& operator>>(istream& is, CDiem& diem) {
	cout << "Nhap diem:\n";
	cout << "Nhap x: ";
	cin >> diem.x;
	cout << "Nhap y: ";
	cin >> diem.y;
	return is;
}

ostream& operator<<(ostream& os, CDiem& diem) {
	cout << "(" << diem.x << ";" << diem.y << ")";
	return os;
}

double CDiem::KhoangCach(CDiem diem) {
	double kq = sqrt((x - diem.x) * (x - diem.x) + (y - diem.y) * (y - diem.y));
	return kq;
}

bool CDiem::operator>(const CDiem& diem) {
	CDiem toado;
	if (toado.KhoangCach(*this) > toado.KhoangCach(diem)) {
		return true;
	}
	else {
		return false;
	}
}

bool CDiem::operator<(const CDiem& diem) {
	CDiem toado;
	if (toado.KhoangCach(*this) < toado.KhoangCach(diem)) {
		return true;
	}
	else {
		return false;
	}
}

bool CDiem::operator=(const CDiem& diem) {
	CDiem toado;
	if (toado.KhoangCach(*this) == toado.KhoangCach(diem)) {
		return true;
	}
	else {
		return false;
	}
}