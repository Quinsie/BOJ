#include <iostream>
#include <string>

using namespace std;

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l1, l2;
    int dp[1002][1002];
    string s1, s2;

    cin >> s1 >> s2;
    l1 = s1.size();
    l2 = s2.size();

    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(i == 0 || j == 0){
               dp[i][j] = 0;
               continue; 
            }
            if (s1[i - 1] != s2[j - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else {
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }
    cout << dp[l1][l2] << "\n";

    return 0;
}