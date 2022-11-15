/* 1.批量代码注释快捷键 alt + shift + a */
/* 2.光标由代码编译栏跳转至终端 ctrl + ` */
/* 3.视图窗口切换 alt + tab ,或者 alt + tab + 左右键*/
/* 4.代码选定 shift + 左右（单个字符选定） ctrl + shift + 左右（单词选中）*/
/* 5.设置断点 fn + f9, 开始调试 fn + f5, 单步执行fn + f11, 跳过执行fn + f10*/
#include<iostream>
using namespace std;
int main()
{
    char c1;
    unsigned count1 = 0, count2 = 0, count3 = 0;
    cout << "Please input your goal string: " << endl;
    while (cin >> c1)
    {
        switch (c1)
        {
        case 'a':
            ++count1;
            break;
        case 'b':
            ++count2;
            break;
        default:
            ++count3;
            break;
        }
    }
    cout << "The count of a is: " << count1 << endl;
    cout << "The count of b is: " << count2 << endl;
    cout << "The count of other alphabet is: " << count3 << endl;
    cout << "The size of int is: " << sizeof(int) << endl;
    cout << "The size of unsigned is: " << sizeof(unsigned) << endl;
}