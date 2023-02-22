//���� �����ڴ� �ڵ� �����ȴ�.
//SoSimple(const SoSimple&copy);�� ����Ʈ
//���� �����ڿ� &������ �ʼ���. ������ ���ѷ����� ������.

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo()const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("LEE", 29);
	Person man2 = man1;		//���� ����. ���� �����͸� �����ϹǷ� �Ҹ� �ÿ� ������ �ȴ�.
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

//man2�� ����� man1�� ����� ������, man1�� name�� �̸� ������ �ִ�.
//���� ����Ʈ ������ ���� ���簡 �ƴ�, ���� ���簡 �ʿ��ϴ�.