// 赋值运算符重载

// 如果有属性数据在堆区开辟，且有调用拷贝构造函数的操作，则会出错
// 防止此类浅拷贝带来的问题，重构拷贝构造函数或者赋值运算符

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        mAge = new int(age);
    }

    ~Person()
    {
        if (mAge != nullptr) {
            delete mAge;
            mAge = nullptr;
        }
    }

    // 编译器提供的赋值是浅拷贝
    // mAge = p.mAge;
    Person& operator=(Person& p)
    {
        // 先清空自身堆区数据
        if (mAge != nullptr) {
            delete mAge;
            mAge = nullptr;
        }
        mAge = new int(*p.mAge);
        return *this;
    }

public:
    int* mAge;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;

    cout << "p1.mAge = " << *p1.mAge << endl;
    cout << "p2.mAge = " << *p2.mAge << endl;
    cout << "p3.mAge = " << *p3.mAge << endl;
}

int main()
{
    test01();

    return 0;
}