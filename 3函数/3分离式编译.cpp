// 这里使用vscode进行分离式编译比较麻烦，暂先略过
#include<iostream>
#include"3_seperate.h"
using namespace std;
int main()
{
    int NUM;
    cout << "Please input your NUM: " << endl;
    cin >> NUM;
    cout << "5! = " << fact(NUM) << endl;
    cout << "abs(-9) = " << abs(NUM) << endl; 
    return 0;
}