// 多态属于C++面向对象三大特性之一

// 多态分为两类：
// 静态多态：函数重载和运算符重载属于静态多态，复用函数名
// 动态多态：派生类和虚函数实现运行时多态

// 静态多态和动态多态的区别：
// 静态多态的函数地址早绑定：编译阶段确定函数地址
// 动态多态的函数地址晚绑定：运行阶段确定函数地址

/****************************************************************************************************/
// 三大条件：
// 1.有继承关系
// 2.子类中重写父类虚函数
// 3.父类指针或引用指向子类对象

// 要了解多态的内部原理：
// 父类中成员函数添加virtual关键字以后，Animal中存放有一个vfptr（虚函数表指针），指向的是&Animal::speak()
// 如果子类中只是继承父类，则同样继承vfptr 且指向&Animal::speak()
// 如果子类中重写了父类虚函数，则vfptr被替换为指向&Cat::speak()
// 在调用父类指针或引用指向子类对象的时候，在运行阶段才会确定函数的地址，根据实际传入的子类对象，执行相应类中的成员函数
/****************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    // 添加virtual关键字 成员函数变为虚函数
    void virtual speak()
    {
        cout << "Animal is speaking..." << endl;
    }
 };

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat is speaking..." << endl;
    }
 };

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog is speaking..." << endl;
    }
 };

void doSpeak(Animal& animal)
{
    animal.speak();
}

void test01()
{
    Cat cat1;
    Dog dog1;

    doSpeak(cat1);
    doSpeak(dog1);
}

int main()
{
    test01();

    return 0;
}