#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void printMap(const map<int, string>& m)
{
    for (map<int, string>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
        cout << "Key:" << iter->first << "  name:" << iter->second << endl;
    }
    cout << endl;
}

void myMap()
{
    map<int, string> m;
    m.insert(pair<int, string> (1, "Tom"));
    m.insert(pair<int, string> (3, "Jerry"));
    m.insert(pair<int, string> (4, "Curry"));
    m.insert(pair<int, string> (2, "James"));
    printMap(m);

    // 判断是否为空，不为空返回大小    
    if (m.empty()) {
        cout << "This map is empty." << endl;
    } else {
        cout << "Map size is: " << m.size() << endl;
    }
}

void mapSwap()
{
    map<int, string> m1, m2;
    m1.insert(pair<int, string> (1, "Tom"));
    m1.insert(pair<int, string> (3, "Jerry"));
    m1.insert(pair<int, string> (4, "Curry"));
    m1.insert(pair<int, string> (2, "James"));

    m2.insert(pair<int, string> (4, "LiuBei"));
    m2.insert(pair<int, string> (6, "ZhangFei"));
    m2.insert(pair<int, string> (8, "GuanYu"));
    m2.insert(pair<int, string> (3, "MaChao"));

    cout << "Before swap: " << endl;
    printMap(m1);
    printMap(m2);

    cout << "After swap: " << endl;
    // 可以使用此种全局函数方式
    // swap(m1, m2);

    // 成员函数交换也可以
    m1.swap(m2);

    printMap(m1);
    printMap(m2);
}

int main()
{
    myMap();
    mapSwap();

    return 0;
}