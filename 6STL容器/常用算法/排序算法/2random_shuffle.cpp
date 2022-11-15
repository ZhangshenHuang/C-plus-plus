/**
 * 洗牌 指定范围内的元素随机调整次序
 * 函数原型：
 * random_shuffle(iterator beg, iterator end);
 * 指定范围内的元素随机调整次序
 * beg 开始迭代器
 * end 结束迭代器
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

class myPrint
{
public:
    // 因为需要的不是一个谓词 所以函数的返回值类型可以不是bool
    void operator()(int val)
    {
        cout << val << " ";
    }
};

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;

    //打乱顺序
    random_shuffle(v.begin(), v.end());
    // 利用for_each()进行遍历  第三个形参需要的是一个func 而不是一个谓词
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;

    return 0;
}