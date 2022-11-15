/**
 * 功能描述：将容器内元素进行反转
 * 函数原型：
 * reverse(iterator beg, iterator end);
 * 
 * 反转指定范围的元素
 * beg 开始迭代器
 * end 结束迭代器
 */

#include <iostream>
#include <algorithm>
#include <vector>
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
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);

	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	cout << "反转后： " << endl;

	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

    return 0;
}