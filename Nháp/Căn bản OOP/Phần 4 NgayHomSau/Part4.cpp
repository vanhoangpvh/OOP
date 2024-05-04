#include <iostream>

using namespace std;

class Ngay {
private:
	int ngay;
	int thang;
	int nam;

public:
	void Nhap();
	void Xuat();
	void NgayHomSau(Ngay&);
	void NgayHomTruoc(Ngay&);
};

int main() {
	Ngay A;
	A.Nhap();

	Ngay B;
	A.NgayHomSau(B);
	cout << "Ngay hom sau se la:\n";
	B.Xuat();

	Ngay C;
	A.NgayHomTruoc(C);
	cout << "\nNgay hom truoc se la:\n";
	C.Xuat();

	return 1;
}

void Ngay::Nhap() {
	cout << "Nhap ngay: ";
	cin >> ngay;
	cout << "Nhap thang: ";
	cin >> thang;
	cout << "Nhap nam: ";
	cin >> nam;
}

void Ngay::Xuat() {
	cout << "Ngay: " << ngay;
	cout << "\nThang: " << thang;
	cout << "\nNam: " << nam;
}

void Ngay::NgayHomSau(Ngay& P) {
	P.ngay = ngay;
	P.thang = thang;
	P.nam = nam;

	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10) {
		if (ngay == 31) {
			P.ngay = 1;
			P.thang = P.thang + 1;
		}
		else {
			P.ngay = P.ngay + 1;
		}
	}
	else if (thang == 12) {
		if (ngay == 31) {
			P.ngay = 1;
			P.thang = 1;
			P.nam = P.nam + 1;
		}
		else {
			P.ngay = P.ngay + 1;
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		if (ngay == 30) {
			P.ngay = 1;
			P.thang = P.thang + 1;
		}
		else {
			P.ngay = P.ngay + 1;
		}
	}
	else if (thang == 2) {
		if (nam % 4 == 0) {
			if (ngay == 29) {
				P.thang = P.thang + 1;
				P.ngay = 1;
			}
			else {
				P.ngay = P.ngay + 1;
			}
		}
		else {
			if (ngay == 28) {
				P.thang = P.thang + 1;
				P.ngay = 1;
			}
			else {
				P.ngay = P.ngay + 1;
			}
		}
	}

}

void Ngay::NgayHomTruoc(Ngay& P) {
	P.ngay = ngay;
	P.thang = thang;
	P.nam = nam;

	if (thang == 2 || thang == 4 || thang == 6 || thang == 8 || thang == 9 || thang == 11) {
		if (ngay == 1) {
			P.ngay = 31;
			P.thang = P.thang - 1;
		}
		else {
			P.ngay = P.ngay - 1;
		}
	}
	else if (thang == 5 || thang == 7 || thang == 10 || thang == 12) {
		if (ngay == 1) {
			P.ngay = 30;
			P.thang = P.thang - 1;
		}
		else {
			P.ngay = P.ngay - 1;
		}
	}
	else if (thang == 1) {
		if (ngay == 1) {
			if (nam == 1) {
				cout << "Khong co ngay hom truoc";
			}
			else {
				P.ngay == 31;
				P.thang = 12;
				P.nam = P.nam - 1;
			}
		}
		else {
			P.ngay = P.ngay - 1;
		}
	}
	else if (thang == 3) {
		if (ngay == 1) {
			if (nam % 4 == 0) {
				P.ngay = 29;
				P.thang = P.thang - 1;
			}
			else {
				P.ngay = 28;
				P.thang = P.thang - 1;
			}
		}
		else {
			P.ngay = P.ngay - 1;
		}
	}
}

