/**
 * transform(iterator beg1, iterator end1, iterator beg2, _func);
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int myTrans(int val)
{
    return val + 10;
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

    vector<int> vTarget;
    // vTarget需要开辟空间
    vTarget.resize(v.size());

    // 第四个参数为搬运过程中需要进行什么操作？
    transform(v.begin(), v.end(), vTarget.begin(),myTrans);
    // 第三个参数为遍历过程中需要进行什么操作？
    for_each(vTarget.begin(), vTarget.end(), MyPrint());

    return 0;
}