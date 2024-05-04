#include <iostream>

using namespace std;

class CChiTietDon : public CChiTiet{
protected:
	double giatien;
public:
	CChiTietDon();
	~CChiTietDon();
	void Nhap();
	void Xuat();
	double TinhTien();
	CChiTiet* TimKiem(string);
};

CChiTietDon::CChiTietDon() {
	giatien = 0;
}

CChiTietDon::~CChiTietDon() {
	return;
}

void CChiTietDon::Nhap() {
	cout << "\n*Nhap ID ma so cua chi tiet don: ";
	cin.ignore();
	getline(cin, maso);
	cout << "+Nhap gia tien cua chi tiet don: ";
	cin >> giatien;
}

void CChiTietDon::Xuat() {
	cout << "\n*ID cua chi tiet don: " << maso << endl;
	cout << "+Gia tien cua chi tiet don: " << giatien << endl;
}

double CChiTietDon::TinhTien() {
	return giatien;
}

CChiTiet* CChiTietDon::TimKiem(string ma_so_can_tim) {
	if (maso == ma_so_can_tim) {
		return this;
	}
	else {
		return NULL;
	}
}

