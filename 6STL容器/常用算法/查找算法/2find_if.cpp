/**
 * find_if(iterator beg, iterator end, _Pred);
 * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 * beg 开始迭代器
 * end 结束迭代器
 * _Pred 函数或者谓词(返回bool类型的仿函数)
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

public:
    string mName;
    int mWeight;
};

class myCompare
{
public:
    // 重载函数调用运算符() 即仿函数
    bool operator()(Person& p)
    {
        return p.mWeight > 160;
    }
};

void myFindIf()
{
    vector<Person> v;
    Person p1("ZhangSan", 160);
    Person p2("LiSi", 175);
    Person p3("WangWu", 167);
    Person p4("WangLiu", 180);
    Person p5("WangBa", 159);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator iter = find_if(v.begin(), v.end(), myCompare());
    // if (iter != v.end()) {
    //     cout << "found!" << " name = " << iter->mName << "  weight = " << iter->mWeight << endl;
    // } else {
    //     cout << "not found!" << endl;
    // }

    // 改进版本，打印出所有身高在160以上的
    if (iter != v.end()) {
        cout << "found! detail informations are as follow:" << endl;
        while (iter != v.end()) {
            cout << "name = " << iter->mName << "  weight = " << iter->mWeight << endl;
            iter = find_if(++iter, v.end(), myCompare());
        }
    } else {
        cout << "not found!" << endl;
    }
}

int main()
{
    myFindIf();

    return 0;
}