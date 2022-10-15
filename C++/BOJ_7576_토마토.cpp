#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int bfs(vvi& table, queue <pair <int, int>>& que, int row, int column)
{
    int x, y, nx, ny, count = 0;

    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();
        count = max(table[x][y], count);

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
                if (!table[nx][ny]) {
                    table[nx][ny] = table[x][y] + 1;
                    que.push({ nx, ny });
                }
            }
        }
    }

    return count - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, column, day;
    bool flag = false;
    vvi table;
    queue <pair <int, int>> que;

    cin >> column >> row;
    table.assign(row, vi(column, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> table[i][j];
            if (table[i][j] == 1) {
                que.push({ i, j });
            }
        }
    }

    day = bfs(table, que, row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (!table[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (flag) cout << -1 << "\n";
    else cout << day << "\n";

    return 0;
}