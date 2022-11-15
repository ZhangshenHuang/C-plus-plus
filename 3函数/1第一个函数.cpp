// 编写自己的第一个函数，实现输出输入数字的阶乘
#include<iostream>
#include"3_seperate.h"
using namespace std;

int main()
{
    int num = 0;
    cout << "Please input your dream number: " << endl;
    cin >> num;
    if (num > 0)
    {
        cout << num << "! " << "is: " << fact(num) << endl;
    }
    else
    {
        cout << "Error input! " << endl;
    }
    cout << "Num's absolute value is: " << abs(num) << endl;        
    return 0;
}

int fact(int v1)
{
    int v3 = 1;
    while (v1 > 0)
    {
        v3 *= v1--;
    }
    return v3;
}

int abs(int v2)
{
    if (v2 >= 0)
    {
        return v2;
    }
    else
    {
        return (-v2);
    }    
}