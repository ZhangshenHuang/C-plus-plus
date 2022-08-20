#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v)
{

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void judgeEmpty(vector<int>& v)
{
    if (v.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << "Not empty!" << endl;
        cout << "Capacity is: " << v.capacity() << endl;
        cout << "Size is: " << v.size() << endl;
    }
}

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);
    judgeEmpty(v1);

    // resize()接口函数，重新划定容器大小
    v1.resize(20, 100);
    printVector(v1);
    judgeEmpty(v1);

    v1.resize(5);
    printVector(v1);
    judgeEmpty(v1);

    return 0;
}