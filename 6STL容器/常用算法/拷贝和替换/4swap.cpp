/**
 * 功能描述：互换两个相同类型容器的元素
 * 函数原型：swap(container c1, container c2);
 * 互换两个容器的元素
 * c1容器1
 * c2容器2
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

int main()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 100);
    }

    cout << "交换前： " << endl;
    for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint());
    cout << endl;

    cout << "交换后： " << endl;

    // 掌握好函数接口就好
    swap(v1, v2);
    
    for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint());
    cout << endl;
}