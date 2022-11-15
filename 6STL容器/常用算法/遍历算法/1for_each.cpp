/**
 * 算法主要是由头文件<algorithm> <functional> <numeric>组成。
 * <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
 * <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
 * <functional>定义了一些模板类,用以声明函数对象。
 */

/**
 * for_each(iterator beg, iterator end, _func);
 * 遍历算法 遍历容器元素
 * beg 开始迭代器
 * end 结束迭代器
 * _func 函数或者函数对象
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 普通函数 放入函数名即可
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 仿函数 需要放入函数对象
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    return 0;
}