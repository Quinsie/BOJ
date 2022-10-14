#include <iostream>
#include <vector>

using namespace std;

const long long MAX = 10e14;

void solve()
{
    int n, c, ans_button;
    long long l, r, temp, ans_click;
    vector <long long> arr, left, right;

    cin >> n >> c;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    left.emplace_back(0);
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            left.emplace_back(arr[i] - arr[i + 1]);
            right.emplace_back(arr[i + 1] + c - arr[i]);
        } else if (arr[i] < arr[i + 1]) {
            left.emplace_back(arr[i] + c - arr[i + 1]);
            right.emplace_back(arr[i + 1] - arr[i]);
        } else {
            left.emplace_back(0);
            right.emplace_back(0);
        }
    }
    right.emplace_back(0);

    l = 0; r = 0;
    for (int i = 0; i < n; i++) {
        r += right[i];
    }

    ans_click = MAX;
    for (int i = 0; i < n; i++) {
        l += left[i];
        temp = max(l, r);
        if (temp < ans_click) {
            ans_button = i;
            ans_click = temp;
        }
        r -= right[i];
    }

    cout << ans_button + 1 << '\n' << ans_click << '\n';
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