// C++ 程序在执行时，将内存分为四个区域
// 意义：不同区域存放不同的数据，赋予不同的生命周期，灵活编程

// 代码区：存放函数体的二进制代码，由操作系统进行管理
// 全局区：存放全局变量和静态变量以及常量
// 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
// 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收





// 在exe程序运行前，分为代码区和全局区

// 代码区: 存放CPU执行的机器指令
// 1. 代码区是共享的，共享的目的是对于频繁被执行的程序，只需在内存中有一份代码就可以
// 2. 代码区是只读的，防止程序意外修改其指令



// 全局区：全局变量和静态变量以及常量（不含局部常量）存放在此
// 该区域数据在程序结束后由系统释放



// 栈区的数据由编译器管理开辟和释放
// 注意：不要返回局部变量的地址



#include<iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 100;

// const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;

// 静态全局变量
static int s_g_a = 10;
static int s_g_b = 100;

int main()
{
    // 局部变量
    int l_a = 10;
    int l_b = 100;

    // const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 100;

    // 静态局部变量
    static int s_a = 10;
    static int s_b = 100;
    
    // 全局变量和局部变量的存储不在一个内存块
    cout << "local a's addess is: " << &l_a << endl;
    cout << "local b's addess is: " << &l_b << endl;
    cout << "global a's addess is: " << &g_a << endl;
    cout << "global b's addess is: " << &g_b << endl;

    // 静态局部变量和静态全局变量在一个内存块
    cout << "static global a's addess is: " << &s_g_a << endl;
    cout << "static global b's addess is: " << &s_g_b << endl;
    cout << "static local a's addess is: " << &s_a << endl;
    cout << "static local b's addess is: " << &s_b << endl;

    // 常量  全局变量、静态变量、常量(字符串常量，const修饰的全局变量)三者处于一个内存块中，地址相差不大

    // 字符串常量
    cout << "string const's address is: " << &"Hello World!" << endl;

    // const修饰的全局变量
    cout << "c_g_a's address is: " << &c_g_a << endl;
    cout << "c_g_b's address is: " << &c_g_b << endl;

    // const修饰的局部变量  存在的内存区域和局部变量相近，处于同一内存块中
    cout << "c_l_a's address is: " << &c_l_a << endl;
    cout << "c_l_b's address is: " << &c_l_b << endl;

    return 0;
}