// 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
// 语法：new 数据类型
// 利用new创建的数据，会返回该数据对应的类型的指针

#include<iostream>
using namespace std;

void test1()
{
    int *arr = new int [10];
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i + 100;
        cout << arr[i] << endl;
    }
    // 释放数组的时候，加入中括号，编译器才可成功识别
    delete [] arr;
}

int main()
{
    test1();
    return 0;
}