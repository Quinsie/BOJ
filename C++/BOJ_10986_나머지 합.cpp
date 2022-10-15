#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, temp;
    long long res = 0;
    long long* MOD;
    vector <long long> arr;

    MOD = new long long[1000001];

    cin >> n >> m;
    arr.assign(m, 0);
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        MOD[i] = (MOD[i - 1] + temp) % m;
        if (!MOD[i]) res++;
        arr[MOD[i]]++;
    }

    for (int i = 0; i < m; i++) {
        res += arr[i] * (arr[i] - 1) / 2;
    }

    cout << res << '\n';

    delete[] MOD;
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