#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int a, b, c;
int dp[101][101][101][27];

int f(int x, int y, int z, int cnt) {
    int& ret = dp[x][y][z][cnt];
    if (ret != -1) return ret;
    if (x == 0 && y == 0 && z == 0) return ret = 0;

    if (cnt & 1) {
        ret = 0;
        if (x > 0) ret = max(ret, min(x, cnt) + f(max(0, x - cnt), y, z, cnt + 1));
        if (y > 0) ret = max(ret, min(y, cnt) + f(x, max(0, y - cnt), z, cnt + 1));
        if (z > 0) ret = max(ret, min(z, cnt) + f(x, y, max(0, z - cnt), cnt + 1));
    }
    else {
        ret = INF;
        if (x > 0) ret = min(ret, f(max(0, x - cnt), y, z, cnt + 1));
        if (y > 0) ret = min(ret, f(x, max(0, y - cnt), z, cnt + 1));
        if (z > 0) ret = min(ret, f(x, y, max(0, z - cnt), cnt + 1));
    }

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                for (int p = 1; p <= 26; p++) {
                    dp[i][j][k][p] = -1;
                }
            } 
        }
    }

	cin >> a >> b >> c;

    int F = f(a, b, c, 1), S = (a + b + c) - F;
    if (F > S) cout << "F";
    else if (F < S) cout << "S";
    else cout << "D";

	return 0;
}