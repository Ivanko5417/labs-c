#include <iostream>
#include <string.h>
using namespace std;

class Person {
	protected:
		char name[100];
		char date_of_birth[12];
		char sex[6];
		Person * next;
	public:
		void setName(char* name) {
			strcpy(this->name, name);
		}

		char* getName() {
			return this->name;
		}

		void setDateOfBirth(char* date_of_birth) {
			strcpy(this->date_of_birth, date_of_birth);
		}

		char* getDateOfBirth() {
			return this->date_of_birth;
		}

		void setSex(char* sex) {
			strcpy(this->sex, sex);
		}

		char* getSex() {
			return this->sex;
		}

		Person* getNext() {
			return this->next;
		}

		Person(char* name, char* date_of_bitth, char* sex) {
			strcpy(this->date_of_birth, date_of_birth);
			strcpy(this->name, name);
			strcpy(this->sex, sex);
			this->next = NULL;
		}

		Person() {
			strcpy(this->date_of_birth, "None");
			strcpy(this->name, "None");
			strcpy(this->sex, "None");
			this->next = NULL;
		}

		~Person() {
			delete this->next;
		}

		void SetPersonInfo(char* name, char* date_of_bitth, char* sex) {
			strcpy(this->date_of_birth, date_of_birth);
			strcpy(this->name, name);
			strcpy(this->sex, sex);
		}

		void AddNextPerson(Person *person) {
			Person* sp = this;
			while(sp->getNext() != NULL) {
				sp = sp->getNext();
			}
			sp->next = person;
		}
		virtual void PersonInfo() {
			cout << "Person: " << endl;
			cout << "	Name: " << this->name << endl;
			cout << "	Date of birth: " << this->date_of_birth << endl;
			cout << "	Sex: " << this->sex << endl;
		}
};

class Employee : public Person
{
	protected:
		char role[100];
	public:
		virtual void PersonInfo() {
			cout << "Emploee: " << endl;
			cout << "	Name: " << this->name << endl;
			cout << "	Date of birth: " << this->date_of_birth << endl;
			cout << "	Sex: " << this->sex << endl;
			cout << "	Role: " << this->role << endl;
		}
		void setRole(char* role) {
			strcpy(this->role, role);
		}

		char* getRole() {
			return this->role;
		}
};

class Manager : public Employee
{
	char department[100];
	Person * employers;
	public:
		Manager(char* department) {
			strcpy(this->department, department);
		}
		void setDepartment(char* department) {
			strcpy(this->department, department);
		}

		char* getDepartment() {
			return this->department;
		}
		void AddEmployee(Employee * employee) {
			if(employers)
				employee->AddNextPerson(employee);
			else
				employers = employee;
		}
		void PrintEmployers() {
			Person* sp = employers;
			if(sp) {
				sp->PersonInfo();
				sp = sp->getNext();
			}
		}
		void PersonInfo() {
			cout << "Manager: " << endl;
			cout << "	Name: " << this->name << endl;
			cout << "	Date of birth: " << this->date_of_birth << endl;
			cout << "	Sex: " << this->sex << endl;
			cout << "	Role: " << this->role << endl;
			cout << "	Department: " << this->department << endl;
		}

};

class Chief : public Employee
{
	char company[100];
	Person * managers;
	public:
		Chief(char * company) {
			strcpy(this->company, company);
		}
		void setCompany(char* company) {
			strcpy(this->company, company);
		}

		char* getCompany() {
			return this->company;
		}

		void AddManager(Manager* manager) {
			if(managers)
				managers->AddNextPerson(manager);
			else
				this->managers = manager;

		}
		void PrintManagers() {
			Person* sp = managers;
			if(sp) {
				sp->PersonInfo();
				sp = sp->getNext();
			}
		}
		void PersonInfo() {
			cout << "Manager: " << endl;
			cout << "	Name: " << this->name << endl;
			cout << "	Date of birth: " << this->date_of_birth << endl;
			cout << "	Sex: " << this->sex << endl;
			cout << "	Role: " << this->role << endl;
			cout << "	Company: " << this->company<< endl;
		}

};


int main() {
	Chief * ch = new Chief("Рога ");
	ch->SetPersonInfo("Остап Бендер", "12.12.1212", "м");
	Manager * m1 = new Manager("Рога");
	m1->SetPersonInfo("Шура", "01.01.0101", "м");
	Manager * m2 = new Manager("Копыта");
	m1->SetPersonInfo("Паниковский", "10.10.1010", "м");
	ch->AddManager(m1);
	ch->AddManager(m2);
	ch->PersonInfo();
	ch->PrintManagers();

	return 0;
}
