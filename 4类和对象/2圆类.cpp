// 设计一个圆类，求圆的周长和面积
#include<iostream>
using namespace std;
const double PI = 3.1415826;

class circle
{
    // 权限
    public:

    // 属性
    int radius;

    // 行为
    double perimeter()
    {
        return 2 * PI * radius;
    }

    double area()
    {
        return PI * radius * radius;
    }
};

int main()
{
    // 实例化，通过一个圆类，创建一个具体的圆对象的过程
    circle c1, c2;
    // 这里不需要加int 类中已经对radius的类型进行了声明
    c1.radius = 1, c2.radius = 5;
    cout << "The perimeter and area of c1 is: " << c1.perimeter() << " " << c1.area() << endl;
    cout << "The perimeter and area of c2 is: " << c2.perimeter() << " " << c2.area() << endl;
    return 0;
}