#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, x, y;
    vector <pair<int, int>> arr;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < num; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}