#include <iostream>
#include <vector>

using namespace std;

const int MIN = -2147483647;

void solve()
{
    int n, maximum;
    vector <int> arr, ans;

    cin >> n;
    arr.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i - 1] + arr[i] < arr[i]) ans[i] = arr[i];
        else ans[i] = ans[i - 1] + arr[i];
    }

    maximum = MIN;
    for (int i = 1; i <= n; i++) {
        maximum = max(maximum, ans[i]);
    }

    cout << maximum << '\n';
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