/**
 * find(iterator beg, iterator end, value);
 * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 * beg 开始迭代器
 * end 结束迭代器
 * value 查找的元素
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
public:
    Person(string name, int weight)
    {
        this->mName = name;
        this->mWeight = weight;
    }

    // 涉及到自定义数据类型的比较判断需要重载==运算符
    bool operator==(Person p)
    {
        if (this->mName == p.mName && this->mWeight == p.mWeight) {
            return true;
        } else {
            return false;
        }
    }

public:
    string mName;
    int mWeight;
};

void myFind()
{
    vector<Person> v;
    Person p1("ZhangSan", 160);
    Person p2("LiSi", 175);
    Person p3("WangWu", 167);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 返回值是一个迭代器
    vector<Person>::iterator iter = find(v.begin(), v.end(), p1);
    if (iter != v.end()) {
        cout << "found!" << " name = " << iter->mName << "  weight = " << iter->mWeight << endl;
    } else {
        cout << "not found!" << endl;
    }
}

int main()
{
    myFind();

    return 0;
}