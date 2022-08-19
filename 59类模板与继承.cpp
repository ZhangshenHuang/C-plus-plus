// 类模板与继承
// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// 如果不指定，编译器无法给子类分配内存
// 如果想灵活指定出父类中T的类型，子类也需变为类模板


#include <iostream>
#include <string>
using namespace std;

template <class T>
class Parent
{
public:
    T mVar1;
};

// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
class Son1 : public Parent <int>
{
public:
    // mVar2;
};

// 如果想灵活指定出父类中T的类型，子类也需变为类模板
template <class T1, class T2>
class Son2 : public Parent <T1>
{
public:
    T2 mVar2;
};