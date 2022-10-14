#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, max;
    long long temp, max_val;
    vector <long long> arr;
    unordered_map <long long, int> m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (!m[temp]) arr.emplace_back(temp);
        m[temp]++;
    }

    sort(arr.begin(), arr.end());
    max = 0; max_val = 0;
    for (auto i : arr) {
        if (m[i] > max) {
            max = m[i];
            max_val = i;
        }
    }

    cout << max_val << '\n';
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