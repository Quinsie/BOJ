#include <iostream>

using namespace std;

void solve()
{
    int total, n, sum, price, num;

    cin >> total >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> price >> num;
        sum += price * num;
    }

    if (sum == total) cout << "Yes\n";
    else cout << "No\n";
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