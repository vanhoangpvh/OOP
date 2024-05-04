#include <iostream>

using namespace std;

class CDaThuc {
private:
	int n; // bac cua da thuc
	int a[100];

public:
	friend istream& operator>>(istream& is, CDaThuc& sp);
	friend ostream& operator<<(ostream& os, CDaThuc& sp);
	CDaThuc();
	CDaThuc operator+(CDaThuc sp);
	CDaThuc operator-(CDaThuc sp);
	CDaThuc operator*(CDaThuc sp);
	CDaThuc operator+=(CDaThuc sp);
	CDaThuc operator-=(CDaThuc sp);
	CDaThuc operator*=(CDaThuc sp);
};

int main() {

	CDaThuc sp1, sp2;
	cout << "Nhap 2 da thuc:\n";
	cin >> sp1 >> sp2;

	CDaThuc tong, hieu, tich;
	tong = sp1 + sp2;
	hieu = sp1 - sp2;
	tich = sp1 * sp2;
	
	cout << "Da Thuc Tong:\n" << tong;
	cout << "Da Thuc Hieu:\n" << hieu;
	cout << "Da Thuc Tich:\n" << tich;
	
	sp1 += sp2;
	cout << sp1;
	sp1 -= sp2;
	cout << sp1;
	sp1 *= sp2;
	cout << sp1;

	return 1;
}

istream& operator>>(istream& is, CDaThuc& dt) {
	cout << "Nhap da thuc:\n";
	cout << "Nhap bac cua da thuc: ";
	cin >> dt.n;
	cout << "Nhap cac he so cua da thuc tu bac cao nhat den bac thap nhat: ";
	for (int i = dt.n; i >= 0; i--) {
		cin >> dt.a[i];
	}
	return is;
}

ostream& operator<<(ostream& os, CDaThuc& dt) {
	cout << "Bac cua da thuc la: " << dt.n << "\nCac bac cua da thuc tu bac cao nhat den bac thap nhat la: ";
	for (int i = dt.n; i >= 0; i--) {
		cout << dt.a[i] << " ";
	}
	cout << "\n\n";
	return os;
}

CDaThuc::CDaThuc() {
	n = 100;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
}

CDaThuc CDaThuc::operator+(CDaThuc dt) {
	CDaThuc temp;
	if (n >= dt.n) {
		temp.n = n;
	}
	else {
		temp.n = dt.n;
	}

	for (int i = temp.n; i >= 0; i--) {
		temp.a[i] = a[i] + dt.a[i];
	}

	return temp;
}

CDaThuc CDaThuc::operator-(CDaThuc dt) {
	CDaThuc temp;
	if (n > dt.n) {
		temp.n = n;
	}
	else if (n < dt.n) {
		temp.n = dt.n;
	}
	else {
		temp.n = n;
	}

	int b = n;

	for (int i = temp.n; i >= 0; i--) {
		temp.a[i] = a[i] - dt.a[i];
		if (temp.a[i] == 0) {
			b--;
		}
	}
	temp.n = b + 1;

	return temp;
}

CDaThuc CDaThuc::operator*(CDaThuc dt) {
	CDaThuc temp;
	temp.n = n + dt.n;
	for (int k = temp.n; k >= 0; k--) {
		for (int i = n; i >= 0; i--) {
			for (int j = dt.n; j >= 0; j--) {
				if (i + j == k) {
					temp.a[k] += a[i] * dt.a[j];
				}
			}
		}
	}

	return temp;
}

CDaThuc CDaThuc::operator+=(CDaThuc dt) {
	*this = *this + dt;
	return *this;
}

CDaThuc CDaThuc::operator-=(CDaThuc dt) {
	*this = *this - dt;
	return *this;
}

CDaThuc CDaThuc::operator*=(CDaThuc dt) {
	*this = *this * dt;
	return *this;
}