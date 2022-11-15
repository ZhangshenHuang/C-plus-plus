// 返回bool类型的仿函数称为谓词
// 如果operator（）接受一个参数，那么叫做一元谓词
// 如果operator（）接受两个参数，那么叫做二元谓词

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Find
{
public:
    bool operator()(int v1)
    {
        return v1 > 6;
    }
};

void myFind()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 匿名函数对象做谓词
    vector<int>::iterator iter = find_if(v.begin(), v.end(), Find());
    if (iter != v.end()) {
        cout << "number = " << *iter << endl;
    } else {
        cout << "number is not found!" << endl;
    }
}

int main()
{
    myFind();

    return 0;
}