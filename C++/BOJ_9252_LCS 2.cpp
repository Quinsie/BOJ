#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len1, len2, length;
    int dp[1001][1001] = { 0, };
    string s1, s2, ans;

    cin >> s1 >> s2;
    len1 = s1.size();
    len2 = s2.size();

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[len1][len2] << "\n";

    ans = "";
    while (len1 && len2) {
        if (dp[len1][len2] == dp[len1 - 1][len2]) {
            len1--;
        }
        else if (dp[len1][len2] == dp[len1][len2 - 1]) {
            len2--;
        }
        else {
            ans.push_back(s1[len1 - 1]);
            len1--;
            len2--;
        }
    }

    length = ans.size();
    for (int i = length - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}