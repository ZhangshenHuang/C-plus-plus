// 练习6.10 使用指针形参交换两个变量的值
#include<iostream>
using namespace std;

int change(int *x, int *y)
{
    // 这里必须使用*x *y 而不能使用x y
    // 此处的 *x *y 并不与a b变量本身的地址相同，而是在内存中重新开辟一片空间存放指向变量的指针
    // 因为x y只是指针得值，交换指向变量的指针，并不会交换变量本身！
    int z;
    z = *x;
    *x = *y;
    *y = z;
    return 0;
}

// 使用形参指针可以改变原来实参的值，但无法改变实参指针的值，只可改变形参指针的值
int main()
{
    cout << "Please input two number: " << endl;
    int a, b;
    cin >> a >> b;

    cout << "a's address is: " << &a << endl;
    cout << "b's address is: " << &b << endl;
    
    change(&a, &b);

    cout << "after change, a's address is: " << &a << endl;
    cout << "after change, b's address is: " << &b << endl;

    cout << "The change result is: " << a << " " << b <<endl;
    return 0;
}