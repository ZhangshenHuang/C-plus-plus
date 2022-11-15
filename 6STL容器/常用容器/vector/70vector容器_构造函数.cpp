#include <iostream>
#include <vector>
using namespace std;
void myPrint(vector<int>& v);

void conStruct()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    myPrint(v1);

    // 拷贝构造使用较多
    vector<int> v2(v1);
    myPrint(v2);
}

void myPrint(vector<int>& v)
{
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    conStruct();

    return 0;
}