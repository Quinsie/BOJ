#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

string s;
int n;

bool func(int k, int lev, int l, int r)
{
    if (lev == k) {
        while (s[l] == s[r]) {
            l++; r--;
        }
        if (l >= r) return true;
        else return false;
    }

    while (s[l] == s[r]) {
        if (l >= r) return true;
        l++; r--;
    }
    
    return (func(k, lev + 1, l + 1, r) | func(k, lev + 1, l, r - 1));
}

void solve()
{
    cin >> s;
    n = s.size();

    for (int k = 0; k <= 3; k++) {
        if (func(k, 0, 0, n - 1)) {
            cout << k << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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