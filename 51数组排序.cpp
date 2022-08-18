#include <iostream>
#include <string>
using namespace std;

template <typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename Y>
void mySort(Y arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        mySwap(arr[max], arr[i]);
        cout << arr[i] << " ";
    }
    cout << endl;
}

void intArrSort()
{
    int arry[] = {2, 3, 6, 0, 8, 4, 90};
    int length = sizeof(arry) / sizeof(int);
    mySort(arry, length);
}

void charArrSort()
{
    // 字符数组的这种初始化方式要记得
    char arry[] = "acbdfguwzzz";
    int length = sizeof(arry) / sizeof(char);
    mySort(arry,length);
}

int main()
{
    intArrSort();
    charArrSort();

    return 0;
}