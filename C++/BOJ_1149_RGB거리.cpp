#include <iostream>
#include <vector>

using namespace std;

int min_3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int main()
{
    int n;
    vector <vector <int>> fee, dp;
    
    cin >> n;
    
    fee.assign(n, vector <int> (3, 0));
    dp.assign(n, vector <int> (3, 0));
    
    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> fee[i][j];
        }
    }
    
    // base case 설정
    dp[0][0] = fee[0][0];
    dp[0][1] = fee[0][1];
    dp[0][2] = fee[0][2];
    
    // 점화식
    // i번째 집을 R로 칠하는 비용
    // -> i-1 집을 G, B로 칠하는 비용의 최적 중 최소
    // G, B도 똑같음.
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + fee[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + fee[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + fee[i][2];
    }
    
    // 마지막 줄에서 가장 작은 값 출력
    cout << min_3(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << '\n';

    return 0;
}
