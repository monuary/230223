//복사 생성자는 자동 생성된다.
//SoSimple(const SoSimple&copy);가 디폴트
//복사 생성자에 &선언은 필수다. 없으면 무한루프에 빠진다.

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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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
	Person man2 = man1;		//얕은 복사. 같은 포인터를 참조하므로 소멸 시에 문제가 된다.
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

//man2를 지우고 man1을 지우려 했지만, man1의 name이 이마 지워져 있다.
//따라서 디폴트 복사인 얕은 복사가 아닌, 깊은 복사가 필요하다.