#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class point
{
public:

    void set(int x, int y)
    {
        X = x;
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

    void set(int c_x, int c_y, int r)
    {
        C_X = c_x;
        C_Y = c_y;
        R = r;
    }

    int getC_X()
    {
        return C_X;
    }

    int getC_Y()
    {
        return C_Y;
    }

    int get_R()
    {
        return R;
    }

private:

    int C_X, R, C_Y;
};

void judge(point &p, circle &c)
{
    int dis_x = p.getX() - c.getC_X();
    int dis_y = p.getY() - c.getC_Y();
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
    point p1;
    circle c1;
    int x, y, c_x, c_y, r;

    cout << "Please input the axis of the point: " << endl;
    cin >> x >> y;
    cout << "Please input the axis of circle center and the radius: " << endl;
    cin >> c_x >> c_y >> r;

    p1.set(x, y);
    c1.set(c_x, c_y, r);

    cout << "The space relationship of the point and circle is: " << endl;
    judge(p1, c1);
}