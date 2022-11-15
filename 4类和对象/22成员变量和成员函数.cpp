// C++中类的成员变量和成员函数分开存储

// 结论：只有非静态的成员变量位于类的对象上，其他三种都不在类的对象上！

// 一个空类的对象占用内存大小为一字节，为了便于区分对象在内存中的位置



#include<iostream>
using namespace std;

class person
{

};

class phone
{
    // 静态成员变量不在类的对象上，非静态成员变量在类的对象上
    static int type;
};
int phone::type = 100;

class function
{
    // 静态成员函数和非静态成员函数都不在类的对象上
    static void fun()
    {
        ;
    }
};

void test1()
{
    // 空类对象占有字节1
    person p1;
    cout << "The size of p1 is: " << sizeof(p1) << endl;
}

void test2()
{
    // 非静态成员变量在类的对象上
    phone p2;
    cout << "The size of p2 is: " << sizeof(p2) << endl;
}

void test3()
{
    function f3;
    cout << "The size of f3 is: " << sizeof(f3) << endl;
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}