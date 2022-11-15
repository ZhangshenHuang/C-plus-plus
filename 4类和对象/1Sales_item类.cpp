#include<iostream>
#include"1_Sales_item.h"
using namespace std;

/* // Sales_item 读写
int main()
{
    // 读入ISBN号、售出的册数以及销售价格
    Sales_item book;
    cin >> book;
    // 写出IsBN号、售出的册数、总销售额和平均价格
    cout << book << endl;
    return 0;
} */

/* // Sale_item对象的加法
int main()
{
    Sales_item book1, book2, book3;
    // 这里的cin读取并不以空格键作为分隔，后续关注
    cin >> book1 >> book2 >> book3;
    cout << book1 + book2 + book3 << endl;
    return 0;
} */


// 相同ISBN 号书籍统计并且最后输出，不同ISBN号报错
int main()
{
    Sales_item total, trans;
    if(cin >> total)
    {
        while(cin >> trans)
        {
            if(total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else
    {
        cout << "Error input!" << endl;
        return -1;
    }
    return 0;
}