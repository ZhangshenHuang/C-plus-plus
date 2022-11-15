// 练习6.54 定义四则运算，在创建的vector对象中保存函数指针并输出结果
#include<iostream>
#include<vector>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int output(decltype(add) *p, int a, int b)
{
    cout << p(a, b) << endl;
    return 0;
}

int main()
{
    int i = 10, j = 2;
    decltype(add) *p1 = add, *p2 = subtract, *p3 = multiply, *p4 = divide;
    vector<decltype(add)* > club = {p1, p2, p3, p4};

    for(auto iter : club)
    {
        output(iter, i ,j);
    }
    
    return 0;
}