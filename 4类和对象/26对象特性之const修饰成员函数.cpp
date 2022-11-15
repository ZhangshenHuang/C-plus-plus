// const修饰成员函数

// 常函数：
// 1.成员函数后加const即成为常函数
// 2.常函数不可以修改成员属性
// 3.成员属性前加关键字mutable后，在常函数和常对象中就都可以修改了

// 常对象：
// 1.声明对象前加const关键字即称该对象为常对象
// 2.常对象只能调用常函数

#include <iostream>
using namespace std;

class Person
{
public:
    // this指针的本质是一个指针常量，指针的指向不可修改，但指针的值可以修改
    // 常函数即将指针指向的值也设置为const 即const type *const pointer
    void showAge() const
    {
        // mAge = 12;  // 常函数不可以修改成员属性
        this->mHeight = 160; //加了mutable关键字，可以修改
    }

    void showHeight()
    {
        ;
    }

public:
    int mAge = 20;
    mutable int mHeight;
};

void test01()
{
    Person p;
    const Person p1 = p;
    // p1.mHeight();  // 常对象不可以调用普通成员函数

    // 常对象不能修改成员变量的值，但可以访问
    cout << p1.mAge << endl;

    // 常对象可以修改mutable关键字修饰的成员变量的值
    p1.mHeight = 160;

    // 常对象只能调用常函数
    p1.showAge();
}

int main()
{
    test01();

    return 0;
}