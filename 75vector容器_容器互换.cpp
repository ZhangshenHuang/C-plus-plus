// swap接口函数可以使两个容器互换，达到实用的收缩内存的效果

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

void mySwap()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int> v2;
    for (int i = 10; i > 0; --i) {
        v2.push_back(i);
    }

    // 交换前
    cout << "Before swap: " << endl;
    printVector(v1);
    printVector(v2);

    // 交换后
    cout << "After swap: " << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void shrinkMemory()
{
    vector<int> v3;
    for (int i = 0; i < 10000; i++) {
        v3.push_back(i);
    }
    cout << "*************Before swap******************" << endl;
    v3.resize(1);
    cout << "v3's size is: " << v3.size() << endl;
    cout << "v3's capacity is: " << v3.capacity() << endl;

    cout << "*************After swap******************" << endl;
    // vector<int>(v3)为一个匿名对象 相当于依v3重新划定了一片匿名对象的内存大小
    vector<int>(v3).swap(v3);
    cout << "v3's size is: " << v3.size() << endl;
    cout << "v3's capacity is: " << v3.capacity() << endl;

    cout << "vector<int>(v3)'s size is: " << vector<int>(v3).size() << endl;
    cout << "vector<int>(v3)'s capacity is: " << vector<int>(v3).capacity() << endl;   
}


int main()
{
    // mySwap();
    shrinkMemory();

    return 0;
}