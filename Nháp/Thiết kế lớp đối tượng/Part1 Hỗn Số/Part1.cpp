#include <iostream>

using namespace std;
class CHonSo {
private:
	int nguyen;
	int tu;
	int mau;

public:

	friend class CPhanSo;

	//Phương thức khởi tạo
	void KhoiTao();
	void KhoiTao(CHonSo);
	void KhoiTao(int, int, int);
	CHonSo();
	CHonSo(const CHonSo& hs);
	CHonSo(int, int, int);
	void Nhap();
	friend istream& operator>>(istream& is, CHonSo& hs);

	//Phương Thức cung cấp
	friend ostream& operator<<(ostream& os, CHonSo& hs);
	void Xuat();
	int getNguyen();
	int getTu();
	int getMau();

	//Phương thức cập nhật
	CHonSo& operator=(const CHonSo&);
	void setNguyen(int);
	void setTu(int);
	void setMau(int);

	//Phương thức kiểm tra
	bool isDuong();
	int isAm();
	int isHonSo();
	int operator>(const CHonSo&);
	int operator<(const CHonSo&);
	int operator>=(const CHonSo&);
	int operator<=(const CHonSo&);
	int operator==(const CHonSo&);
	int operator!=(const CHonSo&);

	//Phương thức xử lý
	CPhanSo ChuyenPhanSo();
	CHonSo operator+(CHonSo);
	CHonSo operator-(CHonSo);
	CHonSo operator*(CHonSo);
	CHonSo operator/(CHonSo);
	CHonSo operator++(int);
	CHonSo operator--(int);
	CHonSo operator+=(CHonSo);
	CHonSo operator-=(CHonSo);
	CHonSo operator*=(CHonSo);
	CHonSo operator/=(CHonSo);
	~CHonSo();
};

class CPhanSo {
private:
	int tu;
	int mau;

public:
	
	CPhanSo();
	CPhanSo operator+(CPhanSo);
	CPhanSo operator-(CPhanSo);
	CPhanSo operator*(CPhanSo);
	CPhanSo operator/(CPhanSo);
	int operator>(const CPhanSo&);
	int operator<(const CPhanSo&);
	int operator>=(const CPhanSo&);
	int operator<=(const CPhanSo&);
	int operator==(const CPhanSo&);
	int operator!=(const CPhanSo&);
	CHonSo ChuyenHonSo();

	friend class CHonSo;

	
};



int main() {
	CHonSo hs1, hs2;
	cout << "Nhap 2 hon so:\n";
	cin >> hs1 >> hs2;

	CHonSo tong, hieu, tich, thuong;
	tong = hs1 + hs2;
	hieu = hs1 - hs2;
	tich = hs1 * hs2;
	thuong = hs1 / hs2;

	cout << "Tong = " << tong;
	cout << "Hieu = " << hieu;
	cout << "Tich = " << tich;
	cout << "Thuong = " << thuong;

	CHonSo hs3(3, 3, 5);
	cout << "Hon So hs3 = " << hs3;
	if (hs3.isHonSo()) {
		cout << "La hon so" << endl;
	}
	else {
		cout << "Khong la hon so" << endl;
	}

	CHonSo hs4(5, -7,10);
	cout << "Hon So hs4 = " << hs4;
	if (hs4.isDuong()) {
		cout << "La so duong" << endl;
	}
	else {
		cout << "Khong la so duong" << endl;
	}
	return 1;
}

void CHonSo:: KhoiTao() {
	nguyen = 1;
	tu = 1;
	mau = 1;
}

void CHonSo::KhoiTao(CHonSo hs) {
	nguyen = hs.nguyen;
	tu = hs.tu;
	mau = hs.mau;
}

void CHonSo::KhoiTao(int n, int t, int m) {
	nguyen = n;
	tu = t;
	mau = m;
}

CHonSo::CHonSo() {
	nguyen = 1;
	tu = 1;
	mau = 1;
}

CHonSo::CHonSo(const CHonSo& hs) {
	nguyen = hs.nguyen;
	tu = hs.tu;
	mau = hs.mau;
	
}

CHonSo::CHonSo(int n, int t, int m) {
	nguyen = n;
	tu = t;
	mau = m;
}

void CHonSo::Nhap() {
	cout << "Nhap hon so:\n";
	cout << "Nhap phan nguyen: ";
	cin >> nguyen;
	cout << "Nhap tu: ";
	cin >> tu;
	cout << "Nhap mau: ";
	cin >> mau;
}

istream& operator>>(istream& is, CHonSo& hs) {
	cout << "Nhap hon so:\n";
	cout << "Nhap phan nguyen: ";
	cin >> hs.nguyen;
	cout << "Nhap tu: ";
	cin >> hs.tu;
	cout << "Nhap mau: ";
	cin >> hs.mau;
	return is;
}

ostream& operator<<(ostream& os, CHonSo& hs) {
	cout << hs.nguyen << " " << hs.tu << "/" << hs.mau << endl;
	return os;
}

void CHonSo::Xuat() {
	cout << nguyen << " " << tu << "/" << mau << endl;
}

int CHonSo::getNguyen() {
	return nguyen;
}

int CHonSo::getMau() {
	return mau;
}

int CHonSo::getTu() {
	return tu;
}

CHonSo& CHonSo:: operator=(const CHonSo& hs) {
	tu = hs.tu;
	mau = hs.mau;
	nguyen = hs.nguyen;
	return *this;
}

void CHonSo::setMau(int m) {
	mau = m;
}

void CHonSo::setNguyen(int n) {
	nguyen = n;
}

void CHonSo::setTu(int t) {
	tu = t;
}

bool CHonSo::isDuong() {
	if (nguyen >= 0) {
		if ((tu > 0 && mau > 0) || (tu < 0 && mau < 0)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int CHonSo::isAm() {
	if (nguyen >= 0) {
		if ((tu > 0 && mau > 0) || (tu < 0 && mau < 0)) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}

int CHonSo::isHonSo() {
	if (mau != 0 && tu<mau && nguyen !=0) {
		return 1;
	}
	else {
		return 0;
	}
}

CPhanSo::CPhanSo() {
	tu = 1;
	mau = 1;
}

CPhanSo CPhanSo::operator+(CPhanSo ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau + mau * ps.tu;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo CPhanSo::operator-(CPhanSo ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau - mau * ps.tu;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo CPhanSo::operator*(CPhanSo ps) {
	CPhanSo temp;
	temp.tu = tu * ps.tu;
	temp.mau = mau * ps.mau;
	return temp;
}

CPhanSo CPhanSo::operator/(CPhanSo ps) {
	CPhanSo temp;
	temp.tu = tu * ps.mau;
	temp.mau = mau * ps.tu;
	return temp;
}

int CPhanSo::operator>(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if ((temp.tu > 0 && temp.mau > 0) || (temp.tu < 0 && temp.mau < 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int CPhanSo::operator<(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if ((temp.tu > 0 && temp.mau < 0) || (temp.tu < 0 && temp.mau > 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int CPhanSo::operator>=(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if ((temp.tu >= 0 && temp.mau > 0) || (temp.tu <= 0 && temp.mau < 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int CPhanSo::operator<=(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if ((temp.tu >= 0 && temp.mau < 0) || (temp.tu <= 0 && temp.mau > 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int CPhanSo::operator==(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if (temp.tu!=0) {
		return 1;
	}
	else {
		return 0;
	}
}

int CPhanSo::operator!=(const CPhanSo& ps) {
	CPhanSo temp = (*this) - ps;
	if (temp.tu == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int CHonSo::operator>(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen > hs.nguyen) {
		return 1;
	}
	else if (nguyen == hs.nguyen) {
		if (ps1 > ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	
}

int CHonSo::operator<(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen < hs.nguyen) {
		return 1;
	}
	else if (nguyen == hs.nguyen) {
		if (ps1 < ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

int CHonSo::operator>=(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen > hs.nguyen) {
		return 1;
	}
	else if (nguyen == hs.nguyen) {
		if (ps1 >= ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

int CHonSo::operator<=(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen <hs.nguyen) {
		return 1;
	}
	else if (nguyen == hs.nguyen) {
		if (ps1 <= ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

int CHonSo::operator==(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen == hs.nguyen) {
		if (ps1 == ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

int CHonSo::operator!=(const CHonSo& hs) {
	CPhanSo ps1, ps2;
	ps1.tu = tu;
	ps2.tu = hs.tu;
	ps1.mau = mau;
	ps2.mau = hs.mau;

	if (nguyen != hs.nguyen) {
		return 1;
	}
	else {
		if (ps1 != ps2) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

CPhanSo CHonSo::ChuyenPhanSo() {
	CPhanSo temp;
	temp.tu = mau * nguyen + tu;
	temp.mau = mau;
	return temp;
}

CHonSo CPhanSo::ChuyenHonSo() {
	CHonSo temp;
	temp.nguyen = tu / mau;
	temp.tu = tu % mau;
	temp.mau = mau;

	if (temp.tu == temp.mau) {
		temp.nguyen++;
		temp.tu = 0;
		temp.mau = 1;
	}
	
	return temp;
}

CHonSo CHonSo::operator+(CHonSo hs) {
	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2 = hs.ChuyenPhanSo();
	CPhanSo temp = ps1 + ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}


CHonSo CHonSo ::operator-(CHonSo hs) {
	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2 = hs.ChuyenPhanSo();
	CPhanSo temp = ps1 - ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}

CHonSo CHonSo::operator*(CHonSo hs) {
	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2 = hs.ChuyenPhanSo();
	CPhanSo temp = ps1 * ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}

CHonSo CHonSo::operator/(CHonSo hs) {
	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2 = hs.ChuyenPhanSo();
	CPhanSo temp = ps1 / ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}

CHonSo CHonSo::operator++(int) {

	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2;
	CPhanSo temp = ps1 + ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}

CHonSo CHonSo::operator--(int) {
	CPhanSo ps1 = (*this).ChuyenPhanSo();
	CPhanSo ps2;
	CPhanSo temp = ps1 - ps2;
	CHonSo temp1 = temp.ChuyenHonSo();
	return temp1;
}

CHonSo CHonSo::operator+=(CHonSo hs) {
	(*this) = (*this) + hs;
	return (*this);
}

CHonSo CHonSo::operator-=(CHonSo hs) {
	(*this) = (*this) - hs;
	return (*this);
}

CHonSo CHonSo::operator*=(CHonSo hs) {
	(*this) = (*this) * hs;
	return (*this);
}

CHonSo CHonSo::operator/=(CHonSo hs) {
	(*this) = (*this) / hs;
	return (*this);
}

CHonSo::~CHonSo() {
	cout<<"Da pha huy hon so"<<endl;
}