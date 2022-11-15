// 子类继承父类后，当创建子类对象时，也会调用父类的构造函数

// 问题：父类和子类的构造和析构顺序谁先谁后？
// 结论：先构造父类，再构造子类；析构与之相反


#include <iostream>
#include <string>
using namespace std;

class Base 
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son()
	{
		cout << "Son析构函数!" << endl;
	}

};


void test01()
{
	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
	Son s;
}

int main() {

	test01();

	// system("pause");

	return 0;
}