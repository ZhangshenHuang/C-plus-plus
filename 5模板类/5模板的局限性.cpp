// 模板的通用性不是万能的，在遇到一些自定义数据类型的时候可能无法工作
// C++提供了函数模板的重载

#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool myCompare(T& a, T& b)
{
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

class Person
{
public:
    Person(int age, string name)
    {
        mAge = age;
        mName = name;
    }

public:
    int mAge;
    string mName;
};

// template<> 告诉编译器这是一个模板的重载版本，利用具体化Person版本实现代码，具体化优先调用
template <> bool myCompare(Person& p1, Person& p2)
{
    if (p1.mAge == p2.mAge && p1.mName == p2.mName) {
        return true;
    } else {
        return false;
    }
}

void intCompare()
{
    int a = 10, b = 10;
    cout << myCompare(a, b) << endl;
}

void personCompare()
{
    Person p1(35, "James");
    Person p2(36, "Paul");
    cout << myCompare(p1, p2) << endl;
}

int main()
{
    intCompare();
    personCompare();

    return 0;
}