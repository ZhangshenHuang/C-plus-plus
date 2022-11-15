// 1.重载  函数调用操作符  的类，其对象称为函数对象
// 2.函数对象使用重载的()时，行为类似函数调用，因此也叫仿函数

// 函数对象（仿函数）本质是一个类，而不是一个函数

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，也可以有返回值
// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
// 3.函数对象可以作为参数传递

#include <iostream>
#include <string>
using namespace std;

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，也可以有返回值
class MyAdd
{
public:
    string operator()(string s1, string s2)
    {
        return s1 + s2;
    } 
};

void stringAdd()
{
    // 显式重载
    MyAdd myAdd;
    cout << myAdd("Hello", " World") << endl; 
    // 隐式重载
    cout << MyAdd()("Ni", "Hao") << endl;
}

// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
// 可以利用成员变量计数，若是普通函数需要设置全局变量或者静态变量
class MyString
{
public:
    void operator()(string s)
    {
        cout << s << endl;
        ++mCount;
    }

    int mCount = 0;
};

void stringPrint()
{
    MyString myString;
    // 匿名函数对象  当前行执行完即被释放 count计数也会清除
    MyString()("Hello World!");
    myString("Hello World!");
    myString("Hello World!");
    myString("Hello World!");
    cout << myString.mCount << endl;
}

// 3.函数对象可以作为参数传递
void doPrint(MyString& ms, string s)
{
    ms(s);
}

void funcParameter()
{
    MyString myString;
    doPrint(myString, "Hello World!");
}


int main()
{
    stringAdd();
    stringPrint();
    funcParameter();

    return 0;
}