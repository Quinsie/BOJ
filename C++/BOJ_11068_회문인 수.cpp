#include <bits/stdc++.h>

using namespace std;

// ASCII 59 - 122

void solve()
{
    int num, tnum;
    string snum, rnum;
    bool flag;

    cin >> num;

    flag = false;
    for (int i = 2; i <= 64; i++) {
        snum = ""; rnum = "";
        if (flag) break;
        tnum = num;
        while (tnum >= i) {
            snum += (char)((tnum % i) + 59);
            rnum += (char)((tnum % i) + 59);
            tnum /= i;
        }
        snum += (char)(tnum + 59);
        rnum += (char)(tnum + 59);
        
        reverse(rnum.begin(), rnum.end());
        if (snum == rnum) flag = true;
    }

    if (flag) cout << 1 << '\n';
    else cout << 0 << '\n';
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
    int t; cin >> t; while (t--) solve();
    return 0;
}