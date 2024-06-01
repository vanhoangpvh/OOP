#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInCharacterArray(int num, vector<char>A) {
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == num) {
			return true;
		}
	}
	return false;
}

void KiTuDau(int k, string S) {
	vector<char>character;
	vector<int>num;
	bool check = 1;

	//For the first character
	character.push_back(S[0]);
	num.push_back(1);

	for (int i = 1; i < S.length(); i++) {
		for (int j = 0; j < character.size(); j++) {
			if (character[j] == S[i]) {
				num[j] = num[j] + 1;
				check = 0;
			}
		}
		if (check == 1) {
			character.push_back(S[i]);
			num.push_back(1);
		}
	}

	for (int i = 0; i < character.size(); i++) {
		cout << character[i] << " " << num[i] << endl;
	}
}
int main() {

	int k = 0;
	string S;
	cout << "Nhap k: ";
	cin >> k;
	cout << "Nhap chuoi ki tu: ";
	cin.ignore();
	getline(cin, S);

	KiTuDau(k, S);

	return 0;

}