#include <iostream>
#include <unordered_map>

using namespace std;

void solve()
{
    int n, m, temp;
    unordered_map <int, bool> save;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        save[temp] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (save[temp]) cout << 1 << ' ';
        else cout << 0 << ' ';
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