#include <iostream>
using namespace std;

class A {
private:
	int m;
	int n;
public:

	A() {
		m = 1;
		n = 1;
	}
	int getm();
	int getn();

	void Xuat() {
		cout << m << " " << n;
	}
	A& operator=(const A& a);
};

class B : public A {
private:
	int k;
	int q;
public:
	B() {
		k = 2;
		q = 2;
	}
	int getk();
	int getq();

};


int main() {
	A a;
	B b;

	a = b;
	a.Xuat();
	

	return 1;
}

int A::getm() {
	return m;
}

int A::getn() {
	return n;
}

int B::getk() {
	return k;
}

int B::getq() {
	return q;
}

A& A::operator=(const A& a) {
	m = (B)a.getk();
	n = a.n;
	return (*this);
}