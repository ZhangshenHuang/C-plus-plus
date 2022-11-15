// 继承的基本语法：class 子类 ： 继承方式 父类
// 继承的作用意义：在很大程度上简化了代码的书写

#include <iostream>
#include <string>
using namespace std;

// 创建网页的头尾以及侧边项目栏 父类
class BasePage
{
public:
    void head()
    {
        cout << "Welcome to the home of Dark Horse programmer!" << endl;
    }

    void tail()
    {
        cout << "If you need any technical support, please send e-mail to Dark Horse." << endl;
    }

    void languages()
    {
        cout << "There are many languages you can choose, such as cpp, java, python..." << endl;
    }
};

// 各个子类的创建 在类名后包含父类
class Cpp : public BasePage
{
public:
    void cpp()
    {
        cout << "Click on cpp button, and you will enter the dedicated page." << endl;
    }
};

class Java : public BasePage
{
public:
    void java()
    {
        cout << "Please choose the reasons why you select java!" << endl;
    }
};

class Python : public BasePage
{
public:
    void python()
    {
        cout << "Join our python club, monthly salary easily more than ten thousand!!!" << endl;
    }
};

void test01()
{
    Cpp cpp1;
    Java java1;
    Python python1;

    cout << "**********************************" << endl;
    cout << "C++的页面如下: " << endl;
    cpp1.head();
    cpp1.languages();
    cpp1.cpp();
    cpp1.tail();

    cout << "**********************************" << endl;
    cout << "Java的页面如下: " << endl;
    java1.head();
    java1.languages();
    java1.java();
    java1.tail();

    cout << "**********************************" << endl;
    cout << "Python的页面如下: " << endl;
    python1.head();
    python1.languages();
    python1.python();
    python1.tail();
}

int main()
{
    test01();

    return 0;
}