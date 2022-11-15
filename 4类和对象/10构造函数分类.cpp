#include<iostream>
using namespace std;

// 构造函数分类
// 按照参数类型分为  有参和无参构造  无参又称为默认构造函数
// 按照类型分为      普通构造和拷贝构造  拷贝构造之外均是普通构造

class person
{
public:
    
    // 无参（默认）构造函数
    person()
    {
        cout << "parameterless constructor" << endl;
    }

    // 有参构造函数
    person(int a)
    {
        age = a;
        cout << age << endl;
        cout << "parameter constructor" << endl;
    }

    // 拷贝构造函数
    person(const person &p)
    {
        age = p.age;
        cout << age << endl;
        cout << "copy constructor" << endl;
    }

    ~person()
    {
        cout << "deconstruct!" << endl;
    }



public:

    int age;
};

// 调用默认构造函数
void test1()
{
    // 调用无参构造函数不可以加括号，否则编译器认为这是一个函数声明
    person p1;
}

// 调用有参构造函数，以及拷贝函数
void test2()
{
    person p2(23);
    person p3(p2);
}

int main()
{
    test1();
    test2();

    return 0;
}