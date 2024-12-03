#ifndef INC_23127255_W09_VECTOR_H
#define INC_23127255_W09_VECTOR_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

namespace Dummy{
	inline void validateSize(int index, int size) {
		if (index < 0 || index >= size) {
			throw std::invalid_argument("Error: Index is out of bound [0, " + std::to_string(size) + "), " + std::to_string(index) + " was given!");
		}
	}
}

template<class T>
class MyVector{
	T *arr;
	int size;
public:
	MyVector();
	MyVector(int n);
	MyVector(T *a, int n);
	MyVector(const MyVector &v);

	~MyVector();

	int getSize();
	T getItem(int index);
	void setItem(T value, int index);
	void add(T value);
	void addRange(T *a, int n);
	void clear();
	bool contains(T value);
	void toArray(T *arr, int &n);
	bool equals(const MyVector &v);
	int indexOf(T value);

	int lastIndexOf(T value);
	void insert(T value, int index);
	void remove(T value);
	void removeAt(int index);
	void reverse();
	string toString();

	void sortAsc();
	void sortDesc();
};

template<class T>
MyVector<T>::MyVector() : arr{nullptr}, size{0} {}

template<class T>
MyVector<T>::MyVector(int n) : arr{new T[n]}, size{n} {}

template<class T>
MyVector<T>::MyVector(T *a, int n) : arr{new T[n]}, size{n} {
	for (int i = 0; i < size; ++i) {
		arr[i] = a[i];
	}
}

template<class T>
MyVector<T>::MyVector(const MyVector &v) : arr{new T[v.size]}, size{v.size} {
	for (int i = 0; i < size; ++i) {
		arr[i] = v[i];
	}
}

template<class T>
MyVector<T>::~MyVector() {
	delete[] arr;
}


template<class T>
int MyVector<T>::getSize() { return size; }

template<class T>
T MyVector<T>::getItem(int index) {
	Dummy::validateSize(index, size);
	return arr[index];
}

template<class T>
void MyVector<T>::setItem(T value, int index) {
	Dummy::validateSize(index, size);
	arr[index] = value;
}


#include <sstream>

template<class T>
string MyVector<T>::toString() {
	std::ostringstream ss;
	ss << "MyVector<" << typeid(T).name() << ">(";
	for (int i = 0; i < size; ++i) {
		ss << arr[i];
		if (i != size - 1) ss << ", ";
	}
	ss << ")";
	return ss.str();
}

template<class T>
void MyVector<T>::add(T value) { MyVector<T>::add(value, 1); }

template<class T>
void MyVector<T>::addRange(T *a, int n) {
	T *newArr = new T[size + n];
	for (int i = 0; i < size; ++i) newArr[i] = arr[i];
	for (int i = 0; i < n; ++i) newArr[size + i] = a[i];
	size += n;
	delete[] arr;
	arr = newArr;
}

template<class T>
void MyVector<T>::clear() {
	delete[] arr;
	size = 0;
}

template<class T>
bool MyVector<T>::contains(T value) {
	for (auto &a : arr) {
		if (a == value) {
			return true;
		}
	}
	return false;
}

template<class T>
void MyVector<T>::toArray(T *_arr, int &n) {
	if (_arr == nullptr) {
		n = 0;
		return;
	}
	for (int i = 0; i < size; ++i) {
		_arr[i] = arr[i];
	}
	n = size;
}

template<class T>
bool MyVector<T>::equals(const MyVector &v) {
	if (v.size != size) return false;
	for (int i = 0; i < size; ++i) {
		if (arr[i] != v.arr[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
int MyVector<T>::indexOf(T value) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

template<class T>
int MyVector<T>::lastIndexOf(T value) {
	int found = -1;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			found = i;
		}
	}
	return found;
}

template<class T>
void MyVector<T>::insert(T value, int index) {
	Dummy::validateSize(index, size);
	arr[index] = value;
}

template<class T>
void MyVector<T>::remove(T value) {
	int c = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			++c;
		}
	}
	T *newArr = new T[size - c];
	int newSize = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] != value) {
			newArr[newSize++] = arr[i];
		}
	}
	delete[] arr;
	arr = newArr;
	size = newSize;
}

template<class T>
void MyVector<T>::removeAt(int index) {
	Dummy::validateSize(index, size);
	T *newArr = new T[size - 1];
	for (int i = 0; i < index; ++i) {
		newArr[i] = arr[i];
	}
	for (int i = index + 1; i < size; ++i) {
		newArr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newArr;
	--size;
}

template<class T>
void MyVector<T>::reverse() {
	int l = 0;
	int r = size - 1;
	while (l < r) {
		T *tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
		++l;
		--r;
	}
}

#include <algorithm>

template<class T>
void MyVector<T>::sortAsc() {
	std::sort(arr, arr + size, [](T a, T b) {
		return a < b;
	});
}

template<class T>
void MyVector<T>::sortDesc() {
	std::sort(arr, arr + size, [](T a, T b) {
		return a > b;
	});
}


#endif //INC_23127255_W09_VECTOR_H
