#include <iostream>
#include <string>
using namespace std;

class cube
{
public:
    void set_parameter(int s_high, int s_length, int s_wide)
    {
        high = s_high;
        length = s_length;
        wide = s_wide;
    }

    int get_high()
    {
        return high;
    }

    int get_length()
    {
        return length;
    }

    int get_wide()
    {
        return wide;
    }

    int get_area()
    {
        return 2 * (high * length + length * wide + wide * high);
    }

    int get_volume()
    {
        return high * length * wide;
    }

    // 成员函数判断两个立方体是否相同
    // 形参为另外一个类变量
    bool compare(cube& cube)
    {
        if (high == cube.get_high() && length == cube.get_length() && wide == cube.get_wide()) {
            return true;
        }
        return false;
    }

private:
    int high, length, wide;
};

// 这里使用引用，避免拷贝，提高了效率，不使用引用也可以，但需要值拷贝
bool Compare(cube& cube1, cube& cube2)
{
    if (cube1.get_high() == cube2.get_high() && cube1.get_length() == cube2.get_length() && cube1.get_wide() == cube2.get_wide()) {
        return true;
    }
    return false;
}

int main()
{
    int high1, length1, wide1, high2, length2, wide2;
    cube cube1, cube2;

    cout << "Please input the parameter of cube1: " << endl;
    cin >> high1 >> length1 >> wide1;

    cout << "Please input the parameter of cube2: " << endl;
    cin >> high2 >> length2 >> wide2;

    // 此处声明了两个类，所以set_parameter可以写在一起，前者并不会被后者覆盖
    cube1.set_parameter(high1, length1, wide1);
    cube2.set_parameter(high2, length2, wide2);

    cout << "The area and volume of cube1 is: " << cube1.get_area() << "  " << cube1.get_volume() << endl;
    cout << "The area and volume of cube2 is: " << cube2.get_area() << "  " << cube2.get_volume() << endl;

    if (cube1.compare(cube2)) {
        cout << "cube1 is same as cube2" << endl;
    } else {
        cout << "cube1 and cube2 are different" << endl;
    }

    if (Compare(cube1, cube2)) {
        cout << "cube1 is same as cube2" << endl;
    } else {
        cout << "cube1 and cube2 are different" << endl;
    }

    return 0;
}