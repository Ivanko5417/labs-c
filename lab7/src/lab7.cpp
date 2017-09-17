#include <string.h>
#include <iostream>
using namespace std;
const long MAX_LONG = 2147483647;
const long MIN_LONG = -2147483648;

class MathException {
	char op_name[20];
	long val1;
	long val2;
public:
	MathException(char * name_op, long v1, long v2) {
		strcpy(this->op_name, name_op);
		this->val1 = v1;
		this->val2 = v2;
	}
	virtual char * Message() = 0;
};
class OverflowException : public MathException {
	public:
		OverflowException(char * name_op, long v1, long v2):MathException(name_op, v1, v2) {
		}
		char * Message() {
			cout << "Overflow" << endl;
		}
};
class UnderflowException : public MathException {
	public:
		UnderflowException(char * name_op, long v1, long v2):MathException(name_op, v1, v2) {
		}
		char * Message() {
			cout << "Underflow" << endl;
		}
};
class ZeroDivideException : public MathException {
	public:
		ZeroDivideException(char * name_op, long v1, long v2):MathException(name_op, v1, v2) {
		}
		char * Message() {
			cout << "Zero divided" << endl;
		}
};

class Math {
public:
	long abs(long number) {
		return number > 0 ? number: -number;
	}
	long Add(long a, long b) {
		if(a > 0 && b > 0 && b > MAX_LONG - a)
			throw OverflowException("add", a, b);
		else
		if(a < 0 && b < 0 && b < MIN_LONG - a)
			throw UnderflowException("add", a, b);
		else
			return a + b;
	}
	long Sub(long a, long b) {
		if(a > 0 && b < 0 && -b > MAX_LONG - a)
			throw OverflowException("sub", a, b);
		else
		if(a < 0 && b > 0 && -b < MIN_LONG - a)
			throw UnderflowException("sub", a, b);
		else
			return a - b;
	}
	long Mul(long a, long b) {
		if(((a > 0 && b > 0) || (a < 0 && b < 0)) && b > MAX_LONG/a)
			throw OverflowException("sub", a, b);
		else
		if(((a > 0 && b < 0) || (a < 0 && b > 0)) && abs(b) > abs(MIN_LONG/a))
			throw UnderflowException("sub", a, b);
		else
			return a * b;
	}
	long Div(long a, long b) {
		if(b == 0)
			throw ZeroDivideException("div", a, b);
		else
			return a/b;
	}
	long Mod(long a, long b) {
		if(b == 0)
			throw ZeroDivideException("div", a, b);
		else
			return a%b;
	}
};
int main() {
	long a, b;
	Math* math = new Math;
	try {
		a = 2147483645; b = 100;
		cout << math->Add(a,b);
	} catch (OverflowException e) {
		e.Message();
	}

	try {

		a = -2147483645; b = -100;
		cout << math->Add(a,b);
	} catch (UnderflowException e) {
		e.Message();
	}


	try {
		a = 2147483645; b = -100;
		cout << math->Sub(a,b);
	} catch (OverflowException e) {
		e.Message();
	}


	try {
		a = -2147483645; b = 100;
		cout << math->Sub(a,b);
	} catch (UnderflowException e) {
		e.Message();
	}


	try {
		a = 2147483645; b = 100;
		cout << math->Mul(a,b);
	} catch (OverflowException e) {
		e.Message();
	}

	try {
		a = -2147483645; b = 100;
		cout << math->Mul(a,b);
	} catch (UnderflowException e) {
		e.Message();
	}

	try {
		a = -2147483645; b = 0;
		cout << math->Div(a,b);
	} catch (ZeroDivideException e) {
		e.Message();
	}

	try {
		a = -2147483645; b = 0;
		cout << math->Mod(a,b);
	} catch (ZeroDivideException e) {
		e.Message();
	}

	return 0;
}
