#include <iostream>
#include <string.h>

using namespace std;

class String
{
	char * str;	//строка
	int length;	//длина строки
	public:
		void Init(char* str) {
			this->str = new char[100];
			strcpy(this->str, str);
			length = strlen(this->str);
		}

		void Concat(char* str) {
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


};

int main() {
	String* string = new String;
	string->Init("111");
	string->Concat("s");
	Print(string);
	cout << string->Char(2) << " " << string->Length() << endl;
	delete string;
	return 0;
}
