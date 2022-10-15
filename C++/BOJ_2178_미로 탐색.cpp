#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <vector <int>> vvi;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int bfs(int start_x, int start_y, int column, int row, vvi table)
{
    int x, y, nx, ny;
    queue <pair <int, int>> que;
    vvi check(column, vector <int> (row)); // use this vector as displaying blocks and check

    que.push({ start_x, start_y });
    check[start_x][start_y] = 1;

    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();

        if (x == column - 1 && y == row - 1) { // if now pos is destination
            return check[column - 1][row - 1];
        }

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < column && ny >= 0 && ny < row) {
                if (!check[nx][ny] && table[nx][ny]) {
                    check[nx][ny] = check[x][y] + 1;
                    que.push({ nx, ny });
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int column, row;
    string temp;
    vvi table;

    cin >> column >> row;
    table.assign(column, vector <int>(row));

    for (int i = 0; i < column; i++) {
        cin >> temp;
        for (int j = 0; j < row; j++) {
            table[i][j] = (int)temp[j] - 48;
        }
    }

    cout << bfs(0, 0, column, row, table) << "\n";

    return 0;
}