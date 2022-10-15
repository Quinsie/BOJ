#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, len, dec, temp;
    bool flag = true;
    vector <int> arr;

    cin >> a >> b >> len;
    dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        cin >> temp;
        dec += pow(a, i) * temp;
    }

    if (dec == 0) {
        cout << 0 << '\n';
        return;
    }

    while (dec != 0) {
        arr.push_back(dec % b);
        dec /= b;
    }

    while (!arr.empty()) {
        cout << arr.back() << ' ';
        arr.pop_back();
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