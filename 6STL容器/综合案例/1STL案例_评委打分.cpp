#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

class Player
{
public:
    Player(string name, int score)
    {
        mName = name;
        mScore = score;
    }

public:
    string mName;
    int mScore;
};

void createPlayer(vector<Player>& v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        // 这里string name = "Player" + "***" 不对
        string name = "Player ";
        // 要注意这种用法
        name += nameSeed[i];
        int score = 0;
        Player p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Player>& v, deque<int>& d)
{
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();
        int sum = 0, average = 0;
        for (auto iter = d.begin(); iter != d.end(); ++iter) {
            sum += *iter;
        }
        average = sum / d.size();
        iter->mScore = average;
    }
}

void showScore(vector<Player>& v)
{
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        cout << iter->mName << "'s score is: " << iter->mScore << endl;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    vector<Player> v;
    deque<int> d;
    
    createPlayer(v);
    setScore(v, d);
    showScore(v);

    return 0;
}