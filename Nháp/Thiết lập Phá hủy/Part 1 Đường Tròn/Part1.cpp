#include <iostream>

using namespace std;

class CDiem {
private:
	double x;
	double y;

public:
	void Nhap();
	~CDiem();

	friend class CDuongTron;
};

class CDuongTron {
private:
	CDiem O;
	double R;

public:
	void Nhap();
	void Xuat();
	CDuongTron();
	CDuongTron(const CDuongTron&);
	CDuongTron(const CDiem&, double);
	~CDuongTron();
};

int main() {

	CDiem X;
	X.Nhap();
	CDuongTron dt(X,5);
	//dt.Nhap();
	dt.Xuat();

	return 1;
}

void CDiem::Nhap() {
	cout << "Nhap toa do diem:\n";
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

CDuongTron::CDuongTron() {
	R = 1;
	O.x = 0;
	O.y = 0;
}

CDuongTron::CDuongTron(const CDuongTron& dt1) {
	R = dt1.R;
	O.x = dt1.O.x;
	O.y = dt1.O.y;
}

CDuongTron::CDuongTron(const CDiem& diem, double r) {
	O.x = diem.x;
	O.y = diem.y;
	R = r;
}

void CDuongTron:: Nhap() {
	cout << "Nhap toa do diem:\n";
	cout << "Nhap x: ";
	cin >> O.x;
	cout << "Nhap y: ";
	cin >> O.y;
	cout << "Nhap ban kinh duong tron: ";
	cin >> R;
}

void CDuongTron::Xuat() {
	cout << "\nDuong tron da nhap co toa do O (" << O.x << "," << O.y << "); ban kinh R = " << R;
}

CDuongTron::~CDuongTron() {
	cout << "\nDa pha huy duong tron";
}

CDiem ::~CDiem() {
	cout << "\nDa pha huy diem";
}

