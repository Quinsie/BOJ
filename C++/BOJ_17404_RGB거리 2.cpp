#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2147483647;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, ans;
    vector <vector <int>> cost, dp;

    cin >> num;
    cost.assign(num, vector <int> (3, 0));
    dp.assign(num, vector <int> (3, 0));
    for (int i = 0; i < num; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    ans = MAX;
    for (int i = 0; i < 3; i++) {
        dp[0][i] = cost[0][i];
        for (int j = 0; j < 3; j++) { // first line
            if (i == j) continue;
            else dp[0][j] = MAX;
        }
        for (int j = 0; j < 3; j++) { // second line
            if (i == j) dp[1][j] = MAX;
            else dp[1][j] = dp[0][i] + cost[1][j];
        }
        
        for (int j = 2; j < num; j++) { // fill dp vector
            dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }

        for (int j = 0; j < 3; j++) { // judge
            if (i == j) continue;
            else ans = min(ans, dp[num - 1][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}