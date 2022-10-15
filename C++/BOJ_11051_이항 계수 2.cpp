#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

void solve()
{
    int n, k;
    vector <vector <int>> table(1001, vector <int> (1001, 0));

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                table[i][j] = 1;
                continue;
            }
            table[i][j] = (table[i - 1][j] + table[i - 1][j - 1]) % MOD;
        }
    }
    cout << table[n][k] << '\n';
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