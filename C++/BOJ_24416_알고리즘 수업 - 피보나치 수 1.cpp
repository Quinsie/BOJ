#include <iostream>
#include <vector>

using namespace std;

int fibo(int n)
{
    vector <int> arr(3, 1);

    if (n < 3) return 1;
    n -= 2;
    while (n--) {
        arr[2] = arr[1] + arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
    }
    return arr[2];
}

int dp(int n)
{
    if (n < 3) return 0;
    else return n - 2;
}

void solve()
{
    int n;

    cin >> n;
    cout << fibo(n) << ' ' << dp(n) << '\n';
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
