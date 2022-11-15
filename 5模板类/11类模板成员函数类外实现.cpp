// 类模板成员函数类外实现
// 注意：类模板中成员函数类外实现时，需要加上模板参数列表

#include <iostream>
using namespace std;

template <class T>
class Parent
{
public:
    Parent();
    // Parent()
    // {
    //     cout << "constructor in template class" << endl;
    // }

    void func();
    // void func()
    // {
    //     cout << "member function in template class" << endl;
    // }
};

// 下面是类模板中构造函数类外实现
template <class T>
Parent<T>::Parent()
{
    cout << "constructor in template class" << endl;
}

// 注意这里函数的返回值类型要放到最前面
template <class T>
// 注意：类模板中成员函数类外实现时，需要加上模板参数列表
void Parent<T>::func()
{
    cout << "member function in template class" << endl;
}

int main()
{
    Parent<int> p1;
    p1.func();

    return 0;
}