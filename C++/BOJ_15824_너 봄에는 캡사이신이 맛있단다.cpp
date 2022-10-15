#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 10e8 + 7;

long long power(long long n, long long k) // pow(n, k)
{
    long long temp;
    temp = 1;
    while (k) {
        if (k & 1) temp = temp * n % MOD;
        n = n * n % MOD;
        k >>= 1;
    }
    return temp;
}

void solve()
{
    int n, temp;
    long long ans;
    vector <int> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }
    sort(arr.begin(), arr.end());

    ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i] * (power(2, i) - power(2, n - i - 1));
        ans %= MOD;
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