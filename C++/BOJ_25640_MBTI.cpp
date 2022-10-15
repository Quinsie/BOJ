#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, ans;
    string m, temp;

    cin >> m >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == m) ans++;
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