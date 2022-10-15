#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int a, b;

    cin >> a >> b;
    cout << min(a / 2, b) << '\n';
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