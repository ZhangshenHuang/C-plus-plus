/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;

#define YANFA    0
#define RENLI    1
#define XIAOSHOU 2

class Worker
{
public:
    string mName;
    int mSalary;
};

void createWorker(vector<Worker>& v, Worker& worker)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        worker.mName = "worker";
        worker.mName += nameSeed[i];

        worker.mSalary = rand() % 10001 + 10000;
        v.push_back(worker);
    }
}

void assignWorker(multimap<int, Worker>& m, vector<Worker>& v)
{
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        int key = rand() % 3;
        m.insert(pair<int, Worker> (key, *iter));
    }
}

void showWorker(const multimap<int, Worker>& m)
{
    cout << "******************************YanFa***********************************" << endl;
    multimap<int, Worker>::const_iterator iter = m.find(YANFA);
    int num = m.count(YANFA);
    for (int i = 0; iter != m.end() && i < num; ++iter, ++i) {
        cout << (iter->second).mName << " Salary is:" << (iter->second).mSalary << endl;  
    }
    cout << endl;

    cout << "******************************RenLi***********************************" << endl;
    iter = m.find(RENLI);
    num = m.count(RENLI);
    for (int i = 0; iter != m.end() && i < num; ++iter, ++i) {
        cout << (iter->second).mName << " Salary is:" << (iter->second).mSalary << endl;  
    }
    cout << endl;

    cout << "******************************XiaoShou***********************************" << endl;
    iter = m.find(XIAOSHOU);
    num = m.count(XIAOSHOU);
    for (int i = 0; iter != m.end() && i < num; ++iter, ++i) {
        cout << (iter->second).mName << " Salary is:" << (iter->second).mSalary << endl;  
    }
    cout << endl;
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Worker> v;
    Worker w;
    multimap<int, Worker> m;

    createWorker(v, w);
    assignWorker(m, v);
    showWorker(m);

    return 0;
}