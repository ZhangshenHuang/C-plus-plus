// 问题引出：非静态函数只有一份，当有多个同类的对象调用同一非静态函数的时候，如何区分是哪个对象调用的非静态函数呢？
// C++提供内置的this指针，指向调用该成员函数的对象
// this指针是隐藏在每一个非静态成员函数内的指针，无须定义，直接使用即可

// 当形参和成员变量同名时，使用this指针区分
// 在类的非静态成员函数中返回对象本身，使用return *this


#include<iostream>
using namespace std;

class person
{
public:
    person(int age)
    {
        this->age = age;
    }

    // 此处返回值类型要为对象引用，返回的才是对象本身
    // 如果没有& 返回值为对象，编译器会创建一个临时对象，相当于
    // person temp; temp = *this; return temp;
    // 后续分别创建temp1, temp2,temp3... p2.age只会实现一次递增

    // 本质的原因个人认为此处调用了拷贝构造函数，执行的是浅拷贝
    person& AddAge(const person &p)
    {
        this->age += p.age;
        return *this;
    }


public:
    int age;
};

void test01()
{
    person p1(23);
    cout << "the age of p1 is: " << p1.age << endl;
}

void test02()
{
    person p2(20);
    person p3(20);

    // 链式编程思想 要使用对象引用作为函数的返回值
    p3.AddAge(p2).AddAge(p2);
    cout << p3.age << endl;

    // 如果AddAge()返回的不是对象引用，而是对象，此代码可以很好说明age确实在递增
    // 但是在另外的对象上递增，而不是p3
    cout << p3.AddAge(p2).AddAge(p2).age << endl; 
}

int main()
{
    // test01();
    test02();

    return 0;
}