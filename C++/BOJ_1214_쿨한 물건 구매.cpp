#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int num, p, q, big, small, repeat, now, ans;

    cin >> num >> p >> q;

    if (num % p == 0 || num % q == 0) {
        cout << num << '\n';
        return;
    }

    big = max(p, q); small = min(p, q);

    repeat = 0;
    now = ((num / big) + 1) * big;
    ans = now;
    while (repeat <= small && now >= big) {
        repeat++;
        now -= big;
        
        if ((num - now) % small == 0) {
            cout << num << '\n';
            return;
        }

        ans = min(ans, num + (small - (num - now) % small));
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