// 基本语法：template<class T, class Y, class Z,....>
// 后面紧跟类的书写

#include <iostream>
#include <string>
using namespace std;

template <class NameType, class AgeType>
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
    Person <string, int> p1("Jerry", 23);

    // 隐式类型初始化
    // Person p1("Jerry", 23);
    p1.showPerson();
}

int main()
{
    myShow();

    return 0;
}