#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, left, right, mid, count, ans = -1;

    cin >> n >> k;
    left = 1; right = k;
    while (left <= right) {
        count = 0;
        mid = (left + right) / 2;
        for (int i = 1; i <= n; i++) count += min(mid / i, n);

        if (count < k) left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}