#include <bits/stdc++.h>

using namespace std;

const long long MOD = 10e8 + 7;

long long func(int n, const long long& up, const long long& down)
{
    long long half;

    if (n == 0) return 1;
    if (n % 2 == 1) return down * func(n - 1, up, down) % MOD;
    else {
        half = func(n / 2, up, down);
        return (half * half) % MOD;
    }
}

void solve()
{
    int n, k;
    long long up, down;

    cin >> n >> k;
    up = 1; down = 1;

    for (int i = n; i >= n - k + 1; i--) up = (up * i) % MOD;
    for (int i = 1; i <= k; i++) down = (down * i) % MOD;

    down = func(MOD - 2, up, down);

    cout << up * down % MOD << '\n';
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