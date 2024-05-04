#include <iostream>
#include <vector>

using namespace std;

class CChiTietPhuc:public CChiTiet{
protected:
	int n;
	vector <CChiTiet*>ds;
public:
	CChiTietPhuc();
	~CChiTietPhuc();
	void Nhap();
	void Xuat();
	double TinhTien();
	CChiTiet* TimKiem(string);
};

CChiTietPhuc::CChiTietPhuc() {
	n = 1;
	for (int i = 0; i < n; i++) {
		ds.push_back(new CChiTiet());
	}
}

CChiTietPhuc::~CChiTietPhuc() {
	for (CChiTiet* element : ds) {
		delete element;
	}
}

double CChiTietPhuc::TinhTien() {
	double total = 0;
	for (CChiTiet* element : ds) {
		total = total + element->TinhTien();
	}
	return total;
}

CChiTiet* CChiTietPhuc::TimKiem(string ma_so_can_tim) {
	if (maso == ma_so_can_tim) {
		return this;
	}
	else {
		for (CChiTiet* element : ds) {
			CChiTiet* temp = element->TimKiem(ma_so_can_tim);
			if (temp != NULL) {
				return temp;
			}
		}
	}
	return NULL;
}

void CChiTietPhuc::Xuat() {
	cout << "\n*Ma so cua chi tiet phuc: " << maso << endl;
	cout << "**So luong chi tiet thanh phan trong chi tiet phuc: " << n << endl;
	cout << "***Danh sach cac chi tiet thanh phan trong chi tiet phuc:" << endl;
	for (CChiTiet* element : ds) {
		element->Xuat();
	}
}

void CChiTietPhuc::Nhap() {

	cout << "\n*Nhap ma so cua chi tiet phuc: ";
	cin.ignore();
	getline(cin, maso);
	cout << "**Nhap so luong chi tiet thanh phan cua chi tiet phuc: ";
	cin >> n;
	cout << "***Nhap danh sach cac chi tiet thanh phan cua chi tiet phuc:" << endl;
	for (int i = 0; i < n; i++) {
		int choice;
		cout << "\nChi tiet thu " << i + 1 << " cua chi tiet phuc:";
		cout << "\nNhap 0 voi chi tiet don hoac 1 voi chi tiet phuc: ";
		cin >> choice;
		CChiTiet* element = new CChiTiet;
		switch (choice) {
		case 0:
			 element = new CChiTietDon;
			break;

		case 1:
			 element = new CChiTietPhuc;
			break;
		}
		element->Nhap();
		ds.push_back(element);
	}
}