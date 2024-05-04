#include <iostream>
#include <cmath>
using namespace std;

class CDiem {
private:
	double x;
	double y;

public:
	friend istream& operator>>(istream& is, CDiem& diem);
	friend ostream& operator<<(ostream& os, CDiem& diem);
	friend class CTamGiac;
	
};

class CTamGiac {
private:
	CDiem A;
	CDiem B;
	CDiem C;

public:
	friend istream& operator>>(istream& is, CTamGiac& tg);
	friend ostream& operator<<(ostream& os, CTamGiac& tg);
	void KiemTra();
	void TrongTam(CDiem&);
};

int main() {
	CTamGiac tg;
	cin >> tg;
	cout << tg;
	tg.KiemTra();
	CDiem P;
	tg.TrongTam(P);
	cout << "\nTrong tam P ";
	cout << P;
	
	return 1;
}

istream& operator>>(istream& is, CDiem& diem) {
	cout << "Nhap x: ";
	is >> diem.x;
	cout << "Nhap y: ";
	is >> diem.y;
	return is;
}

istream& operator>>(istream& is, CTamGiac& tg) {
	cout << "Nhap diem A:\n";
	is >> tg.A;
	cout << "Nhap diem B:\n";
	is >> tg.B;
	cout << "Nhap diem C:\n";
	is >> tg.C;
	return is;
}

ostream& operator<<(ostream& os, CDiem& diem) {
	os << "(" << diem.x << "," << diem.y << ")\n";
	return os;
}
ostream& operator<<(ostream& os, CTamGiac& tg) {
	os << "Diem A " << tg.A;
	os << "Diem B " << tg.B;
	os << "Diem C " << tg.C;
	return os;
}

void CTamGiac::KiemTra() {
	double ab = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	double bc = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
	double ac = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));

	if (ab + ac > bc && ab + bc > ac && ac + bc > ab) {
		cout << "\n3 diem A, B, C co the tao thanh tam giac";
	}
	else {
		cout << "\n3 diem A, B, C khong the tao thanh tam giac";
	}
}

void CTamGiac::TrongTam(CDiem& P) {
	double ab = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	double bc = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
	double ac = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));

	if (ab + ac > bc && ab + bc > ac && ac + bc > ab) {
		P.x = (A.x + B.x + C.x) / 3;
		P.y = (A.y + B.y + C.y) / 3;
	}
	else {
		return;
	}
}

