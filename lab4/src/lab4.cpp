#include <iostream>
#include <string.h>

using namespace std;

class String
{
	char * str;	//строка
	int length;	//длина строки
	public:
		String() {
			str = new char[100];
			length = 0;
		}

		String(const char* str) {
			Init(str);
		}

		String(const String& string) {
			Init(string.str);
		}

		~String() {
			delete str;
		}
	public:
		void Init(const char* str) {
			this->str = new char[100];
			strcpy(this->str, str);
			length = strlen(this->str);
		}

		void Concat(const char* str) {
			strcat(this->str, str);
			this->length += strlen(str);
		}

		int Length() {
			return this->length;
		}

		char Char(int i) {
			return this->str[i];
		}

		friend void Print(String* a) {
			cout << a->str << endl;
		}
		String& operator=(const char* str) {
			this->Init(str);
		}
		String& operator=(const String& string) {
			this->Init(string.str);
		}
		String& operator+=(const char* str) {
			this->Concat(str);
			return *this;
		}
		String& operator+=(const String& string) {
			this->Concat(string.str);
			return *this;
		}
		char operator[](int i) {
			return this->Char(i);
		}
		friend ostream& operator<<(ostream& os, const String& string) {
			os << string.str;
			return os;
		}
		friend istream& operator>>(istream& is, String& string) {
			is >> string.str;
			return is;
		}


};

int main() {
	String str1;
	str1 = "123";
	str1+= "4";
	String str2 = str1;
	cout << str1 << " " << str2 << endl;
	cin >> str1;
	str1+= str2;
	cout << str1;
	return 0;
}
