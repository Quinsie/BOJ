#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long ans;
    string a, b;

    ans = 0;
    for (int i = 0; i < 2; i++) {
        cin >> a >> b;
        ans += stoll(a + b);
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