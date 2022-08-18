// 建立一个通用函数，其函数返回值类型和形参类型可以不具体确定，用一个虚拟的类型来代表

// 语法：template <typename T>  T为通用的数据类型

// 注意事项：
// 1.自动类型推导，必须推导出一致的数据类型T，才可以使用
// 2.模板必须要确定出T的数据类型，才可以使用


#include <iostream>
using namespace std;

template <typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void swapInt()
{
    int a = 1, b = 2;

    // 自动类型推导
    // mySwap(a, b);

    // 显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << " b = " << b << endl;
}

int main()
{
    swapInt();

    return 0;
}