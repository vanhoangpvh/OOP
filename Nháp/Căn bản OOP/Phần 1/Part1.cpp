#include <iostream>
#include <string>

using namespace std;

//Nhap xuat thong tin cua hoc sinh
class HocSinh {
private:
	string hoten;
	double diemtoan;
	double diemvan;
	double dtb;

public:
	void Nhap();
	void Xuat();
	void XuLy();
};

int main() {

	HocSinh a;
	a.Nhap();
	a.XuLy();
	a.Xuat();

	return 1;

}

void HocSinh::Nhap() {
	cout << "Nhap ten hoc sinh: ";
	getline(cin, hoten);
	cout << "Nhap diem toan: ";
	cin >> diemtoan;
	cout << "Nhap diem van: ";
	cin >> diemvan;
}

void HocSinh::XuLy() {
	dtb = (diemtoan + diemvan) / 2;
}

void HocSinh::Xuat() {
	cout << "Ho ten: " << hoten;
	cout << "\nDiem toan: " << diemtoan;
	cout << "\nDiem van: " << diemvan;
	cout << "\nDiem tb: " << dtb;
}

