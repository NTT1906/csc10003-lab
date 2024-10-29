#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
	Triangle t1;
	cout << "---------------------\n";
	Triangle t2(1, 2);
	cout << "---------------------\n";
	Triangle t3(1, 2, 3, 4);
	cout << "---------------------\n";
	Triangle t4(1, 2, 3, 4, 5, 6);
	cout << "---------------------\n";
	Triangle t5 = t4.clone();
	cout << "---------------------\n";
	Triangle t6("1,2;3,4;5,6");
	cout << "---------------------\n";
	Triangle t7(Point2D{7, 12});
	Triangle t8({8, 12}, {3, 15});
	Triangle t9({9, 12}, {3, 15}, {8, 12});

	cout << "Clone T6 to T10\n";
	Triangle  t10(t6);

	cout << "T1:  " << t1.toString() << "\n";
	cout << "T2:  " << t2.toString() << "\n";
	cout << "T3:  " << t3.toString() << "\n";
	cout << "T4:  " << t4.toString() << "\n";
	cout << "T5:  " << t5.toString() << "\n";
	cout << "T6:  " << t6.toString() << "\n";
	cout << "T7:  " << t7.toString() << "\n";
	cout << "T8:  " << t8.toString() << "\n";
	cout << "T9:  " << t9.toString() << "\n";
	cout << "T10: " << t10.toString() << "\n";


	cout << "Move T2 to T11\n";
	Triangle t11 = std::move(t2);
	cout << "T11: " << t11.toString() << '\n';
	cout << "T2: " << t2.toString() << '\n';
}
