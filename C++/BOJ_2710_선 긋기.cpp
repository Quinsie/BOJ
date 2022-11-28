#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair <int, int> a, pair <int, int> b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve()
{
    int n, left, right;
    long long sum;
    vector <pair <int, int>> arr;

    cin >> n;
    arr.assign(n, pair <int, int> ());
    
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), compare);

    sum = 0;
    left = arr[0].first; right = arr[0].second;

    for (int i = 1; i < n; i++) {
        if (arr[i].first > right) {
            sum += right - left;
            left = arr[i].first; right = arr[i].second;
        } else {
            left = min(left, arr[i].first);
            right = max(right, arr[i].second);
        }
    }
    sum += right - left;

    cout << sum << '\n';
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}