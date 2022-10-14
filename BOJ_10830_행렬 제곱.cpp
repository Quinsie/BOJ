#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

vector <vector <int>> matrix_multiply_normal(
    const vector <vector <int>>& m,
    const vector <vector <int>>& normal,
    const int& size
)
{
    vector <vector <int>> ret(size, vector <int>(size, 0));

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            for (int c = 0; c < size; c++) ret[a][b] += (m[a][c] * normal[c][b]) % MOD;
            ret[a][b] %= MOD;
        }
    }

    return ret;
}

vector <vector <int>> matrix_multiply_self(
    const vector <vector <int>>& m,
    const int& size
)
{
    vector <vector <int>> ret(size, vector <int>(size, 0));

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            for (int c = 0; c < size; c++) ret[a][b] += (m[a][c] * m[c][b]) % MOD;
            ret[a][b] %= MOD;
        }
    }

    return ret;
}

vector <vector <int>> matrix_power(
    const vector <vector <int>>& normal,
    const int& size,
    long long power
)
{
    if (power == 1) return normal;

    if (power % 2 == 0) {
        return matrix_multiply_self(
            matrix_power(normal, size, power / 2), size);
    }
    else {
        return matrix_multiply_normal(
            matrix_multiply_self(matrix_power(normal, size, power / 2), size),
            normal, size
        );
    }
}

void solve()
{
    int n;
    long long b;
    vector <vector <int>> matrix, ans;

    cin >> n >> b;
    matrix.assign(n, vector <int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    ans = matrix_power(matrix, n, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] % 1000 << ' ';
        }
        cout << '\n';
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