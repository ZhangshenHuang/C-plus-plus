/**
 * 算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
 * 算法简介：
 * accumulate // 计算容器元素累计总和
 * fill // 向容器中添加元素
 */

/**
 * 功能描述：计算区间内 容器元素累计总和
 * 函数原型：accumulate(iterator beg, iterator end, value);
 * 计算容器元素累计总和
 * beg 开始迭代器
 * end 结束迭代器
 * value 起始值 一般设置为0
 */

// 此算法比较实用
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }

    int sum = accumulate(v.begin(), v.end(), 1000000);
    cout << "sum = " << sum << endl;

    return 0;
}