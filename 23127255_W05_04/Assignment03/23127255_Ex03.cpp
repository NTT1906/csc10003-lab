#include <iostream>

using namespace std;
class Base {
private:
	int t;
public:
	Base() {
		cout << "Base constructor-0 param" << endl;
		t = 0;
	}

	Base(int u) {
		cout << "Base constructor-1 param" << endl;
		t = u;
	}

	Base(const Base &b) {
		t = b.t;
		cout << "Base copy constructor" << endl;
	}

	~Base() {
		cout << "Base destructor" << endl;
	}
};

class DerivedA : public Base {
public:
	DerivedA() {
		cout << "DerivedA constructor-0 param" << endl;
		a = 0;
	}

	DerivedA(int x) {
		cout << "DerivedA constructor-1 param" << endl;
		a = x;
	}

	DerivedA(int u, int x) {
		cout << "DerivedA constructor-2 params" << endl;
		a = x;
	}

	DerivedA(const DerivedA &da) {
		a = da.a;
	}

	~DerivedA() {
		cout << "DerivedA destructor" << endl;
	}

	void print() {
		cout << "DerivedA = " << a << endl;
	}

private:
	int a;
};
class DerivedB : public Base {
public:
	DerivedB() {
		cout << "DerivedB constructor-0 param" << endl;
		b = 0;
	}

	DerivedB(float x) {
		cout << "DerivedB constructor-1 param" << endl;
		b = x;
	}

	DerivedB(int u, float x) : Base(u) {
		cout << "DerivedB constructor-2 params" << endl;
		b = x;
	}

	DerivedB(const DerivedB &db) : Base(db) {
		cout << "DerivedB copy constructor" << endl;
		b = db.b;
	}

	~DerivedB() {
		cout << "DerivedB destructor" << endl;
	}

	void print() {
		cout << "DerivedB = " << b << endl;
	}

private:
	float b;
};

void f(Base b) {
	cout << "Function f" << endl;
}

int main() {
	cout << "L1\n";
	Base b1;
	cout << "L2\n";
	Base b2(3);
	cout << "L3\n";
	Base *pb = new Base(1);
	cout << "L4\n";
	DerivedA da1;
	cout << "L5\n";
	DerivedA da2(2);
	cout << "L6\n";
	DerivedA da3(2, 3);
	cout << "L7\n";
	DerivedA da4(da2);
	cout << "L8\n";
	pb = new DerivedA(4, 5);
	cout << "L9\n";
	DerivedB db1;
	cout << "L10\n";
	DerivedB db2(2.7);
	cout << "L11\n";
	DerivedB db3(3, 2.7);
	cout << "L12\n";
	DerivedB db4(db2);
	cout << "L13\n";
	pb = new DerivedB(4, 5);
	cout << "L14\n";
	f(b1);
	cout << "L15\n";
	f(da1);
	cout << "L16\n";
	f(db1);
	cout << "L17\n";
	delete pb;
	cout << "L18\n";
	return 0;
}