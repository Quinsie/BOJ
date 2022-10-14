#include <bits/stdc++.h>

using namespace std;

void solve()
{
    char temp;
    int n, b;
    string ans;

    cin >> n >> b;
    ans = "";
    while (n / b != 0) {
        if (n % b < 10) {temp = n % b + 48; ans = temp + ans;}
        else {temp = n % b + 55; ans = temp + ans;}
        n /= b;
    }

    if (n < 10) {temp = n + 48; ans = temp + ans;}
    else {temp = n + 55; ans = temp + ans;}

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