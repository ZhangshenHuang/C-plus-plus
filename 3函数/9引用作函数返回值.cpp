#include<iostream>
using namespace std;

int& test1()
{
    int a = 10;
    return a; //局部变量存储在栈区，函数执行完释放
}

// 如果返回值是一个引用类型，则函数的调用可以作为左值
int& test2()
{
    int a = 10;
    return a;
}

int main()
{
    //可以不使用引用接收引用类型的返回值，这样打印输出结果永远不会出错
    //但如果使用引用接收引用类型的返回值，打印输出结果第二次即为乱码
    //不建议返回局部变量的引用
    int &b = test1();
    cout << "a's value is: " << b << endl;
    cout << "a's value is: " << b << endl;

    // 函数调用作为左值
    test2() = 1000;
    int &c = test2();
    cout << "a's value is: " << c << endl;
    cout << "a's value is: " << c << endl;

    return 0;
}