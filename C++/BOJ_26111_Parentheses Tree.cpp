#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int now, length;
    long long sum;
    string s;

    cin >> s;

    sum = 0; now = 0;

    length = s.size();
    for (int i = 1; i < length - 1; i++) {
        if (s[i] == '(') now++;
        else {
            if (s[i - 1] == '(') sum += now;
            now--;
        }
    }

    cout << sum << '\n';
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