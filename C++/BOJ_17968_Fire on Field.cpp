#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;

void solve()
{
    int n, k, val;
    vector <int> arr;

    cin >> n;
    arr.assign(n + 1, 0);
    arr[0] = 1; arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        val = 1;
        while (true) {
            arr[i] = val; k = 1;

            while (true) {
                if (i - 2 * k < 0) break;
                if (arr[i] - arr[i - k] == arr[i - k] - arr[i - 2 * k]) break;
                k++;
            }

            if (i - 2 * k < 0) break;
            else val++;
        }
    }

    cout << arr[n] << '\n';
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