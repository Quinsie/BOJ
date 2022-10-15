#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long a, b, c, x, y;

    cin >> a >> b >> c;
    x = (double)(a * b) / c;
    y = ((double)a / b) * c;

    if (x > y) cout << x << '\n';
    else cout << y << '\n';
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