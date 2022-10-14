#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int a, b, n, w, sum, ans_a, ans_b, flag;

    cin >> a >> b >> n >> w;
    
    sum = b * n;
    flag = 0;
    for (int i = 1; i <= n - 1; i++) {
        sum -= b;
        sum += a;

        if (sum == w) {
            flag++;
            ans_a = i; ans_b = n - i;
        }
    }

    if (!flag) cout << -1 << '\n';
    else if (flag == 1) cout << ans_a << ' ' << ans_b << '\n';
    else cout << -1 << '\n';

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