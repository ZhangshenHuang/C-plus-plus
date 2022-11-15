// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量！

// 普通成员变量的初始化必须通过对象，而静态成员变量以及静态成员函数的初始化
// 有两种初始化方式，1.通过类的对象初始化 2.通过类名初始化

// 若静态成员函数也可以访问普通成员变量，那么对于两个不同的对象，因为他们对应的同一普通成员变量可以不相同
// 若均调用了静态成员函数，那如果做到不同对象的同一普通变量拥有不同的值呢？显然不可以！

#include<iostream>
#include<string>
using namespace std;

class person
{
public:
    static void fun()
    {
        // number = 234;
        cout << "person's age is: " << age << endl;
    }


private:
    static int age;
    int number;
};

int person::age = 100;

int main()
{
    person p1;
    p1.fun();
    // person::fun();
    
    return 0;
}