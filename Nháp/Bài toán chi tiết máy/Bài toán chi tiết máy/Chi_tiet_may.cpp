#include <iostream>
#include <cstdlib>
#include "CChiTiet.hpp"
#include "CChiTietDon.hpp"
#include "CChiTietPhuc.hpp"
#include "CMay.hpp"

using namespace std;

int main() {
	
	CMay* may_tinh = new CMay;


    //Nhap thong tin cua may
	cout << "*****Phan nhap thong tin cho may******" << endl;
	may_tinh->Nhap();
	system("cls");

	//Xuat thong tin cua may
	cout << "\n*****Bang thong tin cua may******" << endl;
	may_tinh->Xuat();


	//Xuat tri gia cua may
	cout << "\n***************";
	cout << "\nTri gia cua may tinh la: " << may_tinh->TinhTien();
	

	//Tim kiem ma so tuong ung trong cac chi tiet cua may 
	string ma_so_can_tim;
	cout << "\n\nNhap ma so can tim trong may tinh: ";
	cin.ignore();
	getline(cin, ma_so_can_tim);
	

	CChiTiet* chi_tiet = may_tinh->TimKiem(ma_so_can_tim);
	if (chi_tiet) {
		cout << "\nMa so can tim tuong ung voi chi tiet co cac thong so sau: ";
		chi_tiet->Xuat();
	}
	else {
		cout << "Khong tim thay ma so can tim tuong ung trong may";
		chi_tiet->Xuat();
	}
	
	return 1;
}


