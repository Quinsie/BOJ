#include <iostream>

using namespace std;

void solve()
{
    int n, arr[6] = { 1, 1, 2, 2, 2, 8 };

    for (int i = 0; i < 6; i++) {
        cin >> n;
        cout << arr[i] - n << ' ';
    }
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