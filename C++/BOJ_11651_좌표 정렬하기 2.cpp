#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair <int, int> a, pair <int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, x, y;
    vector <pair<int, int>> arr;
    pair <int, int> cd;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> cd.first >> cd.second;
        arr.push_back(cd);
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < num; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}