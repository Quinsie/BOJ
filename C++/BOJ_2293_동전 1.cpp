#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int coin_num, target, temp;
    vector <int> coin, dp;

    cin >> coin_num >> target;
    coin.emplace_back(0);
    for (int i = 0; i < coin_num; i++) {
        cin >> temp;
        coin.emplace_back(temp);
    }
    dp.assign(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= coin_num; i++) {
        for (int j = coin[i]; j <= target; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[target] << "\n";

    return 0;
}