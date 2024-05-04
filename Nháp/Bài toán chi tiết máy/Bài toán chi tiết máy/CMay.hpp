#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CMay {
protected:
	int n;
	vector<CChiTiet*>ds;
public:
	CMay();
	~CMay();
	void Nhap();
	void Xuat();
	double TinhTien();
	CChiTiet* TimKiem(string);
	int countThanhPhan();
};

CMay::CMay() {
	n = 1;
	for (int i = 0; i < n; i++) {
		ds.push_back(new CChiTiet());
	}
}

CMay::~CMay() {
	for (CChiTiet* element : ds) {
		delete element;
	}
}

double CMay::TinhTien() {
	double total = 0;
	for (CChiTiet* element : ds) {
		total = total + element->TinhTien();
	}
	return total;
}

CChiTiet* CMay::TimKiem(string ma_so_can_tim) {
	for (CChiTiet* element : ds) {
		CChiTiet* temp = element->TimKiem(ma_so_can_tim);
		if (temp != NULL) {
			return temp;
		}
	}
	return NULL;

	
}

void CMay::Xuat() {
	cout << "\n**So luong chi tiet chinh cua may: " << n << endl;
	cout << "\n**Tong so luong chi tiet don cua may: " << countThanhPhan() << endl;
	cout << "***Danh sach cac chi tiet chinh va thanh phan cua may: " << endl;
	for (CChiTiet* element : ds) {
		element->Xuat();
	}
}

void CMay::Nhap() {

	cout << "\n**Nhap so luong chi tiet chinh cua may: ";
	cin >> n;
	cout << "***Nhap danh sach cac chi tiet chinh cua may:";
	for (int i = 0; i < n;i++) {
		int choice;
		cout << "\n\n\nChi tiet may thu " << i + 1;
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

int CMay::countThanhPhan() {
	int run = 0;
	for (CChiTiet* element : ds) {
		run++;
	}
	return run;
}

