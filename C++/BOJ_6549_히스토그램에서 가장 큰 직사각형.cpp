#include <bits/stdc++.h>

using namespace std;

long long divide_conquer(long long left, long long right,
                         const int& size, vector <long long>& arr)
{
    long long mid, midArea, height, l, r, width;
    
    mid = (left + right) / 2;
    midArea = arr[mid], height = arr[mid];
    l = mid - 1, r = mid + 1;
 
    if (left + 1 >= right) { return midArea; }
    while (l > left || r < right) {
        if (l <= left || (r < right && arr[l] <= arr[r])) {
            height = min(arr[r], height);
            r++;
        } else {
            height = min(height, arr[l]);
            l--;
        }
        width = r -1 - l; 
        midArea = max(midArea, width * height);
    }
    return max(midArea, max(divide_conquer(left, mid, size, arr), divide_conquer(mid, right, size, arr)));
}

void solve()
{
    int n;
    vector <long long> arr;

    while (true) {
        cin >> n; if (!n) return;

        arr.assign(n + 2, 0);

        for (int i = 1; i <= n; i++) cin >> arr[i];

        cout << divide_conquer(0, n + 1, n, arr) << "\n";

        arr.clear();
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