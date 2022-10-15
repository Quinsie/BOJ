#include <iostream>

using namespace std;

void div_2(int num, int& save)
{
    while (num / 2 > 0) {
        num /= 2;
        save += num;
    }
}

void div_5(int num, int& save)
{
    while (num / 5 > 0) {
        num /= 5;
        save += num;
    }
}

void solve()
{
    int n, m, ans;
    int up_2, up_5, down_2, down_5;

    cin >> n >> m;
    up_2 = 0; up_5 = 0; down_2 = 0; down_5 = 0;

    div_2(n, up_2);
    div_2(m, down_2);
    div_2(n - m, down_2);
    div_5(n, up_5);
    div_5(m, down_5);
    div_5(n - m, down_5);

    up_2 -= down_2;
    up_5 -= down_5;
    ans = min(up_2, up_5);

    if (ans <= 0) cout << 0 << '\n';
    else cout << ans << '\n';
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