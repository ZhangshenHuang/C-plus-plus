// 运算符重载：对于已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型
// 加号运算符重载：实现两个自定义数据类型相加
// 本质上还是自己书写函数实现，调用函数，无任何特别之处
// 总结1.对于内置的数据类型的表达式的运算符是不可能改变的
// 总结2.不能滥用运算符重载，例如在operator+里面定义-的运算

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person operator+(const Person& p)
    {
        Person temp;
        temp.mAge = this->mAge + p.mAge;
        temp.mHeight = this->mHeight + p.mHeight;
        return temp;
    }

public:
    int mHeight, mAge;
};

Person operator-(const Person& p1, const Person& p2)
{
    Person temp;
    temp.mAge = p1.mAge - p2.mAge;
    temp.mHeight = p1.mHeight - p2.mHeight;
    return temp;
}

void test01()
{
    Person p1, p2;
    p1.mAge = 20;
    p1.mHeight = 160;
    p2.mAge = 10;
    p2.mHeight = 200;

    // 本质调用
    Person p3 = p2.operator+(p1);
    Person p4 = operator-(p1, p2);
    // 简化的调用方法
    // Person p3 = p1 + p2;
    // Person p4 = p2 - p1;

    cout << "p3.mAge = " << p3.mAge << endl;
    cout << "p3.mHeight = " << p3.mHeight << endl;

    cout << "p4.mAge = " << p4.mAge << endl;
    cout << "p4.mHeight = " << p4.mHeight << endl;
}

int main()
{
    test01();

    return 0;
}