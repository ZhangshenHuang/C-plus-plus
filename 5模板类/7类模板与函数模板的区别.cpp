// 类模板与函数模板的区别主要有以下两点：
// 1.类模板没有自动类型推导的使用方式，使用只能使用显示指定类型方式，但我目前用的C++标准支持自动类型推导
// 2.类模板在模板参数列表中可以有默认参数，函数模板没有这种语法


#include <iostream>
#include <string>
using namespace std;

// 在模板的参数列表中可以具有默认参数
template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        mName = name;
        mAge = age;
    }

    void showPerson()
    {
        cout << mName << "'s age is: " << mAge << endl;
    }

public:
    NameType mName;
    AgeType mAge;
};

void myShow()
{
    // template <string, int> Person p1("Jerry", 23); 错误
    // 显式类型初始化
    // Person <string, int> p1("Jerry", 23);

    // 隐式类型初始化
    Person p1("Jerry", 23);
    p1.showPerson();

    // 因为模板参数列表具有了默认参数int 因此可以只写一个string
    Person <string> p2("Curry", 32);
    p2.showPerson();
}

int main()
{
    myShow();

    return 0;
}