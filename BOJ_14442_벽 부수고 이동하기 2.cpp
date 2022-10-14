#include <bits/stdc++.h>

using namespace std;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

int bfs(const vector <vector <int>>& table, const int& n, const int& m, const int& k)
{
    int x, y, nx, ny, wall;
    queue <tuple<int, int, int>> q;
    vector <vector <vector <int>>> check(k + 1, vector <vector <int>> (n, vector <int> (m, 0)));

    q.push({ 0, 0, 0 });
    check[0][0][0] = 1;

    while (!q.empty()) {
        tie(x, y, wall) = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) return check[wall][x][y];

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!table[nx][ny] && !check[wall][nx][ny]) { // 길인 경우
                    check[wall][nx][ny] = check[wall][x][y] + 1;
                    q.push({ nx, ny, wall });
                }
                else if (table[nx][ny] && !check[wall][nx][ny] && wall < k) { // 벽인 경우
                    check[wall][nx][ny] = check[wall][x][y] + 1;
                    check[wall + 1][nx][ny] = check[wall][x][y] + 1;
                    q.push({ nx, ny, wall + 1 });
                }
            }
        }
    }
    return -1;
}

void solve()
{
    int n, m, k;
    string temp;
    vector <vector <int>> table;

    cin >> n >> m >> k;
    table.assign(n, vector <int>(m, 0));

    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            table[i][j] = temp[j] - '0';
        }
    }

    cout << bfs(table, n, m, k) << '\n';
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