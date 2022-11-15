#include<iostream>
using namespace std;

int* func()
{
    int a = 10;
    return &a;
}

int main()
{
    int *p = func();
    cout << *p << endl;  //VS中第一次会保留数据，正常输出，code中直接发出警告
    cout << *p << endl;
    return 0;
}