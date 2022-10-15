#include <iostream>

using namespace std;

int dp(int n)
{
    if (n <= 2) return n;
    int memo[3] = { 1, 2, 3 };
    n -= 2;
    
    while (n) {
        memo[2] = ((memo[0] % 15746) + (memo[1] % 15746)) % 15746;
        memo[0] = memo[1];
        memo[1] = memo[2];
        n--;
    }
    return memo[2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    cout << dp(num);

    return 0;
}