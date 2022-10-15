#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector <vector <char>> vvc;
typedef vector <vector <bool>> vvb;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int bfs(vvc table, vvb& check, int column, int row, bool flag, int s_x, int s_y)
{
    int x, y, nx, ny, count = 0;
    queue <pair <int, int>> que;
    que.push({ s_x, s_y });
    check[s_x][s_y] = true;

    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < column && ny >= 0 && ny < row && !check[nx][ny]) {
                if (!flag) { // white
                    if (table[nx][ny] == 'W') {
                        check[nx][ny] = true;
                        que.push({ nx, ny });
                    }
                } else { // blue
                    if (table[nx][ny] == 'B') {
                        check[nx][ny] = true;
                        que.push({ nx, ny });
                    }
                }
            }
        }
    }
    return count * count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int column, row, white = 0, blue = 0;
    string temp;
    vvc table;
    vvb check;

    cin >> row >> column;
    table.assign(column, vector <char> (row));
    check.assign(column, vector <bool> (row, false));

    for (int i = 0; i < column; i++) {
        cin >> temp;
        for (int j = 0; j < row; j++) {
            table[i][j] = temp[j];
        }
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if (!check[i][j]) { // if not visited
                if (table[i][j] == 'W') { // if white
                    white += bfs(table, check, column, row, false, i, j);
                } else { // if blue
                    blue += bfs(table, check, column, row, true, i, j);
                }
            }
        }
    }

    cout << white << " " << blue << "\n";
    
    return 0;
}