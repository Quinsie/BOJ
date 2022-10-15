#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length, row, maximum, now;
    vector <int> arr;

    cin >> length >> row;
    arr.assign(length, 0);
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    now = 0;
    for (int i = 0; i < row; i++) {
        now += arr[i];
    }
    maximum = now;
    for (int i = row; i < length; i++) {
        now += arr[i];
        now -= arr[i - row];
        maximum = max(maximum, now);
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