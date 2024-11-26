#include <iostream>
using namespace std;

#include "cstring"

class A{
	char *m_s;
public:
	A() { m_s = strdup("default"); }
	A(char *s) { m_s = strdup(s); }
	A(const A &other) { m_s = strdup(other.m_s); }
	virtual void prepare() { cout << "A "; }
	void display() {
		this->prepare();
		cout << m_s << endl;
	}
	virtual ~A() {
		cout << "Calling A from ";
		prepare();
		cout << "\n";
		delete m_s;
	}
	friend ostream &operator<<(ostream &os, const A &a) {
		return os << a.m_s;
	}

	friend istream &operator>>(istream &is, A &a) {
		char buffer[100];
		is.getline(buffer, 100);
		delete[] a.m_s;
		a.m_s = strdup(buffer);
		return is;
	}
};

class B : public A{
public:
	B(char *s) : A(s) {
		cout << "Input char * B got called\n";
	}
	B(const B &b) {
		cout << "Copy B got called\n";
	}
	void prepare() { cout << "B "; }
	~B() override {
		cout << "Bye from B\n";
	};
	friend ostream &operator<<(ostream &os, const B &b) {
		return os << static_cast<const A &>(b);
	}

	friend istream& operator>>(istream& is, B &b) {
		return is >> static_cast<A &>(b);
	}
};

void foo(A *obj1, A obj2) {
	obj1->display();
	obj2.display();
}

int main() {
	B obj1("text");
	A *obj2 = new B(obj1);
	foo(&obj1, *obj2);
	delete obj2;
	return 0;
}
