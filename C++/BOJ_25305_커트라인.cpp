#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    vector <int> arr;

    cin >> n >> k;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    cout << arr[n - k] << '\n';
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