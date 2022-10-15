#include <bits/stdc++.h>

using namespace std;

const int MAX = 10e5;

void solve()
{
    int sum_b, n, ans, temp;

    vector <int> work;
    vector <pair <int, int>> machine;
    
    cin >> n;

    work.assign(MAX, 0);
    machine.assign(n + 1, pair <int, int> ());
    
    sum_b = 0;
    for (int i = 1;i <= n;i++) {
        cin >> machine[i].first >> machine[i].second;
        sum_b += machine[i].second;
    }

    for (int i = 0; i <= sum_b; i++) {
        work[i] = sum_b;
    }

    for (int i = 1;i <= n;i++) {
        for (int j = sum_b; j >= 0; j--) {
            work[j + machine[i].first] = min(work[j + machine[i].first], work[j] - machine[i].second);
        }
    }

    ans = sum_b;
    for (int i = 0;i <= sum_b;i++) {
        temp = max(i, work[i]);
        if (ans > temp) ans = temp;
    }

    cout << ans << '\n';
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