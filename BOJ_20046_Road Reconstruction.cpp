#include <bits/stdc++.h>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

class point {
public:
    int x, y, val;
    point() { x = 0; y = 0; val = 0; }
    point(int a, int b, int c) { x = a; y = b; val = c; }
    ~point() {} 
};

struct cmp {
    bool operator() (point a, point b) {
        return a.val > b.val;
    }
};

int bfs(const int& row, const int& column, const vector <vector <int>>& table)
{
    int x, y, val, nx, ny;
    vector <vector <bool>> check;
    priority_queue <point, vector <point>, cmp> pque;

    check.assign(row, vector <bool> (column, false));
    check[0][0] = true;

    if (table[0][0] == -1) return -1;
    else if (table[0][0] == 0) pque.push(point(0, 0, 0));
    else if (table[0][0] == 1) pque.push(point(0, 0, 1));
    else pque.push(point(0, 0, 2));

    while (!pque.empty()) {
        x = pque.top().x; y = pque.top().y; val = pque.top().val;
        pque.pop();

        if (x == row - 1 && y == column - 1) return val;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
                if (!check[nx][ny] && table[nx][ny] != -1) {
                    check[nx][ny] = true;
                    if (table[nx][ny] == 0) pque.push(point(nx, ny, val));
                    else if (table[nx][ny] == 1) pque.push(point(nx, ny, val + 1));
                    else if (table[nx][ny] == 2) pque.push(point(nx, ny, val + 2));
                }
            }
        }
    }

    return -1;
}

void solve()
{
    int row, column;
    vector <vector <int>> table;

    cin >> row >> column;

    table.assign(row, vector <int> (column, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> table[i][j];
        }
    }

    cout << bfs(row, column, table) << '\n';
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