// set不可以插入重复的数据，但是multiset可以
// set插入数据的同时会返回插入结果，表示插入是否成功
// multiset不会检测数据，因此可以插入重复的数据

#include <iostream>
#include <set>
using namespace std;

void setInsert()
{
    set<int> s;
    // 返回数据为一个对组
    pair<set<int>::iterator, bool> s_ret = s.insert(3);
    if (s_ret.second) {
        cout << "Successful insert!" << endl;
    } else {
        cout << "Insert defeat!" << endl;
    }

    s_ret = s.insert(3);
    if (s_ret.second) {
        cout << "Successful insert!" << endl;
    } else {
        cout << "Insert defeat!" << endl;
    }
}

void multisetInsert()
{
    multiset<int> ms;
    // 返回的仅仅是一个迭代器
    multiset<int>::iterator ms_ret = ms.insert(1);
    cout << *ms_ret << endl;
}

int main()
{
    setInsert();
    multisetInsert();

    return 0;
}