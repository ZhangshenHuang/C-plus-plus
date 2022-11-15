#include<iostream>
using namespace std;

int local_static()
{
    // 局部静态变量对象，直到程序终止才会被销毁，默认初始化值为0
    static int i = 0;
    return ++i;
}

int main()
{
    for (unsigned i = 0; i != 10; ++i)
    {
        cout << local_static() << " ";
    }
    cout << endl;
    return 0;
}