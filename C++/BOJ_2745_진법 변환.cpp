#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int len, now, ans, b;
    string s;

    cin >> s >> b;
    len = s.size();
    now = 1;
    ans = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] >= 48 && s[i] <= 57) {
            ans += now * ((int)s[i] - 48);
        } else {
            ans += now * ((int)s[i] - 55);
        }
        now *= b;
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