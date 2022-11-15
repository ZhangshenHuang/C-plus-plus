#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void printMap(map<int, string, MyCompare>& m)
{
    for (map<int, string, MyCompare>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void mapSort()
{
    map<int, string, MyCompare> m;

    // 这里不要加 pair<MyCompare>
    m.insert(pair<int, string> (1, "Tom"));
    m.insert(pair<int, string> (2, "Jerry"));
    m.insert(pair<int, string> (4, "Smith"));
    m.insert(pair<int, string> (3, "Lorry"));

    printMap(m);
}

int main()
{
    mapSort();

    return 0;
}