#include <iostream>
using namespace std;

template <class T>
class Array
{
	T * arr;	//непосредственно массив
	unsigned size;	//размер массива

	public:
		Array() {
			arr = new T[100];
			size = 0;
		}

		Array(int size) {
			arr = new T[size];
			this->size = size;
		}

		T operator[](int i) {
			return this->arr[i];
		}

		Array& operator+=(const T& t) {
			this->arr[size] = t;
			this->size++;
			return *this;
		}
};

int main() {
	Array <int> a;
	int i = 10;
	a+= i;
	a+= i;
	cout << a[1];
	return 0;
}
