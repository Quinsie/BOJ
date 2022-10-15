#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, c, left, right, mid, ans, now, count;
    vector <int> arr;

    cin >> n >> c;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    
    left = 0; right = arr[n - 1];
    ans = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        now = 0; count = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] - arr[now] >= mid) {
                now = i;
                count++;
            }
        }

        if (count >= c) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
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