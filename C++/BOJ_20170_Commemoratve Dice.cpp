#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;

int gcd(int x, int y)
{
    int temp;
    if (y > x) {
        temp = x;
        x = y;
        y = temp;
    }

    while (y != 0) {
        temp = x;
        x = y;
        y = temp % y;
    }

    return x;
}

void solve()
{
    int res, gcd_num;
    vector <int> arr_a, arr_b;

    arr_a.assign(6, 0); arr_b.assign(6, 0);

    for (int i = 0; i < 6; i++) cin >> arr_a[i];
    for (int i = 0; i < 6; i++) cin >> arr_b[i];

    res = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr_a[i] > arr_b[j]) res++;
        }
    }

    gcd_num = gcd(res, 36);

    cout << (int)res / gcd_num << "/" << (int)36 / gcd_num << "\n";
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