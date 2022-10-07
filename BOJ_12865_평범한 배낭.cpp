#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    vector <pair <int, int>> knapsack;
    vector <int> dp;

    cin >> n >> k;
    knapsack.assign(n, pair <int, int> ());
    dp.assign(k + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> knapsack[i].first >> knapsack[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j >= knapsack[i].first) {
                dp[j] = max(dp[j], dp[j - knapsack[i].first] + knapsack[i].second);
            }
        }
    }

    cout << dp[k] << '\n';
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