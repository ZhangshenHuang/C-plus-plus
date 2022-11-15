/**
 * 功能描述：向容器中填充指定的元素
 * 函数原型：fill(iterator beg, iterator end, value);
 * 向容器中填充元素
 * beg 开始迭代器
 * end 结束迭代器
 * value 填充的值
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

int main()
{

	vector<int> v;
	v.resize(10);

    for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//填充
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}