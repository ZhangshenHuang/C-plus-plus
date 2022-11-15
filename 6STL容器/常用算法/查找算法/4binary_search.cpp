/**
 * 二分查找法，就是用于查找有序序列的！！效率十分高！！
 * bool binary_search(iterator beg, iterator end, value);
 * 查找指定的元素，查到 返回true 否则false
 * 注意: 在无序序列中不可用
 * beg 开始迭代器
 * end 结束迭代器
 * value 查找的元素
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    //二分查找  且只能用于  有序且为升序  序列的查找
    bool ret = binary_search(v.begin(), v.end(), 2);
    if (ret) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}