// STL内建了一些函数对象
// 用法和一些函数完全相同
// 使用内建函数对象，要引入头文件#include<functional>

#include <iostream>
// 注意要包含此头文件
#include <functional>
#include <string>
using namespace std;

int main()
{
    // 加法 plus
    plus<string> s1;
    cout << s1("Hello ", "World!") << endl;

    // 减法 minus
    minus<int> v1;
    cout << v1(7, 6) << endl;

    // 乘法 multiplies
    multiplies<float> f1;
    cout << f1(2.5, 4) << endl;

    // 除法 divides
    divides<float> f2;
    cout << f2(7, 6) << endl;

    // 取模/取余 modulus
    modulus<int> v2;
    cout << v2(8, 6) << endl;

    // 取反 negate
    negate<double> d1;
    cout << d1(7.89) << endl;

    return 0;
}