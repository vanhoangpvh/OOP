#include <iostream>
#include <string>

using namespace std;

class CChiTiet {
protected:
	string maso;
public:
	CChiTiet();
	~CChiTiet();
	virtual void Nhap();
	virtual void Xuat();
	virtual double TinhTien();
	virtual CChiTiet* TimKiem(string);
};

CChiTiet::CChiTiet() {
	maso = "AAAAA";
}

CChiTiet::~CChiTiet() {
	return;
}

void CChiTiet::Nhap() {
	return;
}

void CChiTiet::Xuat() {
	return;
}

double CChiTiet::TinhTien() {
	return 0;
}

CChiTiet* CChiTiet::TimKiem(string ma_so_can_tim) {
	if (maso == ma_so_can_tim) {
		return this;
	}
	else {
		return NULL;
	}
}

