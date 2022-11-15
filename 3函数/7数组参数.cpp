/* // 练习6.21 比较输入的数字大小，通过整型常量和指向整型常量的指针
#include<iostream>
using namespace std;

int compare(const int a, const int *b)
{
    if(a > *b)
    return a;
    else
    return *b;
}

int main()
{
    int x, y;
    cout << "Please input two number: " << endl;
    cin >> x >> y;
    cout << "The bigger one is: " << compare(x, &y) << endl;
    return 0;
} */








/* // 练习6.22 交换两个指针的函数  此题有启发意义！
#include<iostream>
using namespace std;

// * & 同一优先级，定义的是一个对于指针p的引用
int exchange(int *&x, int *&y)
{
    int *z;
    z = x;
    x = y;
    y = z;
    return 0;
}

int main()
{
    int a = 1, b = 2;
    int *p = &a, *q = &b;
    exchange(p, q);
    cout << &a << " " << &b << endl;
    cout << p << " " << q << endl;
    return 0;
} */




// 练习6.23 几种print函数输出数组元素
#include<iostream>
using namespace std;

// 不控制指针的边界
int print1(const int *p)
{
    cout << *p << endl;
    return 0;
}

// 利用数组的大小控制指针边界
int print2(const int *p, const int num)
{
    for(auto i = 0; i != num; ++i)
    {
        cout << *p++ << " ";
    }
    cout << endl;
    return 0;
}

// 利用begin和end函数限定数组边界
int print3(const int *p1, const int *p2)
{
    for ( ; p1 != p2; ++p1)
    {
        cout << *p1 << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    int i = 9, j[2] = {3,4};

    cout << "print1: " << endl;
    print1(&i);
    print1(j);

    cout << "print2: " << endl;
    print2(&i, 1);
    print2(j, sizeof(j) / sizeof(*j));

    // begin和end这两个函数在处理数组问题上只能直接作用于数组名，不能作用于形参！ 
    cout << "print3: " << endl;
    auto Beg = begin(j);
    auto End = end(j);
    print3(Beg, End);
}