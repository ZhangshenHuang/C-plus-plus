// 内部所有元素均为pair
// pair中第一个元素为key（键值），起到索引作用，第二个为value（实值）
// 所有元素都会根据键值自动排序

// map/multimap属于关联式容器，底层结构使用二叉树实现

// 优点：可以根据key值快速找到value值

// map和multimap区别：
// 1.map不允许容器中有重复key值元素 但是value值允许重复
// 2.multimap允许容器中有重复key值出现

#include <iostream>
#include <string>
#include <map>
using namespace std;

void printMap(const map<int, string>& m)
{
    for (map<int, string>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
        cout << "Key:" << iter->first << "  name:" << iter->second << endl;
    }
}

void myMap()
{
    map<int, string> m;
    m.insert(pair<int, string> (1, "Tom"));
    m.insert(pair<int, string> (3, "Jerry"));
    m.insert(pair<int, string> (4, "Curry"));
    m.insert(pair<int, string> (2, "James"));
    printMap(m);
    cout << endl;

    map<int, string> m1(m);
    printMap(m1);
    cout << endl;

    map<int, string> m2 = m;
    printMap(m2);
    cout << endl;
}

int main()
{
    myMap();

    return 0;
}