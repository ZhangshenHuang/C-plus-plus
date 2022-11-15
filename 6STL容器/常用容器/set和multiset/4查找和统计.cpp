// 对multimset容器进行查找数据以及统计数据
// find(key)  //查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回尾后迭代器
// count(key)  //统计key的元素个数

#include <iostream>
#include <set>
using namespace std;

void printMultiset(multiset<int>& ms)
{
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void myFind()
{
    multiset<int> ms;
    ms.insert(3);
    ms.insert(38);
    ms.insert(38);
    ms.insert(56);
    ms.insert(-6);
    ms.insert(38);
    ms.insert(38);

    printMultiset(ms);

    // 查找
    int key = 38;
    multiset<int>::iterator pos = ms.find(key);
    if (pos != ms.end()) {
        // 统计
        int num = ms.count(key);
        cout << "The element ims finded: " << *pos << endl;
        cout << "The whole num ims: " << num << endl;
    } else {
        cout << "The element ims ineximstence!" << endl;
    }
}

int main()
{
    myFind();

    return 0;
}