#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, ans, table[21][21][21];
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                if (i == 0 or j == 0 or k == 0) table[i][j][k] = 1;
                else table[i][j][k] = 2;
            }
        }
    }

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            for (int k = 1; k < 21; k++) {
                table[i][j][k] = table[i - 1][j][k] + table[i - 1][j - 1][k] + table[i - 1][j][k - 1] - table[i - 1][j - 1][k - 1];
                if (i < j && j < k) {
                    table[i][j][k] = table[i][j][k - 1] + table[i][j - 1][k - 1] - table[i][j - 1][k];
                }
            }
        }
    }

    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        if (a <= 0 || b <= 0 || c <= 0) ans = 1;
        else if (a > 20 || b > 20 || c > 20) ans = table[20][20][20];
        else ans = table[a][b][c];

        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
    }

    return 0;
}