#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class point
{
public:

    void setX(int &x)
    {
        X = x;
    }

    void setY(int &y)
    {
        Y = y;
    }

    int getX()
    {
        return X;
    }

    int getY()
    {
        return Y;
    }

private:

    int X, Y;
};

class circle
{
public:

    void setR(int &r)
    {
        R = r;
    }

    int get_R()
    {
        return R;
    }

    // 这里要好好学习，使用已经存在的另一个类来定义成员函数
    void setCenter(point &center)
    {
        Center = center;
    }

    point getCenter()
    {
        return Center;
    }

private:

    int R;
    point Center;
};

void judge(point &p, circle &c)
{
    int dis_x = p.getX() - c.getCenter().getX();
    int dis_y = p.getY() - c.getCenter().getY();
    int powdis = pow(dis_x, 2) + pow(dis_y, 2);
    
    if(powdis == pow(c.get_R(), 2))
    {
        cout << "The point is already on the circle!" << endl;
    }
    else if(powdis < pow(c.get_R(), 2))
    {
        cout << "The point is in the circle!" << endl;
    }
    else
    {
        cout << "The point is out of the circle!" << endl;
    }
}

int main()
{
    point p1, center;
    circle c1;
    int x, y, c_x, c_y, r;

    cout << "Please input the axis of the point: " << endl;
    cin >> x >> y;
    cout << "Please input the axis of circle center and the radius: " << endl;
    cin >> c_x >> c_y >> r;

    // 创建点
    p1.setX(x);
    p1.setY(y);

    // 创建圆，这种设置方式要学习借鉴
    center.setX(c_x);
    center.setY(c_y);
    c1.setCenter(center);
    c1.setR(r);

    cout << "The space relationship of the point and circle is: " << endl;
    judge(p1, c1);
}