#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct compare { // true -> change
    bool operator()(const pair<int, int> a, const pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        if (temp != 0) {
            que.push(make_pair(temp, abs(temp)));
        }
        else {
            if (que.empty()) {
                cout << 0 << "\n";
                continue;
            }
            else {
                cout << que.top().first << "\n";
                que.pop();
            }
        }
    }

    return 0;
}