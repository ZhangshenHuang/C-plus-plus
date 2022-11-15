// 重载关系运算符，可以让两个自定义对象进行对比操作
// 没有特别的新意，无非就是自己自定义函数，函数名编译器内部已经规定，在普通的运算符前加operator修饰

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

    bool operator==(Person& p)
    {
        if (this->mName == p.mName && this->mAge == p.mAge) {
            return true;
        } else {
            return false;
        }
    }

public:
    string mName;
    int mAge;
};

void test01()
{
    Person p1("James", 35);
    Person p2("Paul", 36);
    Person p3("Paul", 36);

    if (p2.operator==(p1)) {
        cout << "p1 and p2 are same" << endl;
    } else {
        cout << "p1 and p2 are different" << endl;
    }

    if (p2.operator==(p3)) {
        cout << "p3 and p2 are same" << endl;
    } else {
        cout << "p3 and p2 are different" << endl;
    }
}

int main()
{
    test01();

    return 0;
}