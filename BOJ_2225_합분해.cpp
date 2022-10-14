#include <iostream>
#include <vector>

using namespace std;

const int MAX = 201;
const int MOD = 10e8;

void solve()
{
    int n, k;
    vector <vector <long long>> dp;

    cin >> n >> k;

    dp.assign(MAX, vector <long long> (MAX, 0));
    for (int i = 0; i <= n; i++) dp[1][i] = 1;

    for (int  i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = dp[i][j] + dp[i - 1][k];
            }
            dp[i][j] %= MOD;
        }
    }

    cout << dp[k][n] << '\n';

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