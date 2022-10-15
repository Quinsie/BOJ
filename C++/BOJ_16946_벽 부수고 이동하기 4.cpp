#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

const int dx[4]={ 0 , 0 , 1 , -1 };
const int dy[4]={ 1 , -1 , 0 , 0 };

int bfs(vvi& table, vvi& check, int row, int column, int s_x, int s_y, int check_count)
{
    int x, y, nx, ny, count;
    queue <pair <int, int>> que;
    check[s_x][s_y] = check_count;
    que.push({ s_x, s_y });

    count = 0;
    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
                if (!check[nx][ny] && !table[nx][ny]) { // if not checked and not wall
                    check[nx][ny] = check_count;
                    que.push({ nx, ny });
                }
            }
        }
    }
    return count;
}

int find(unordered_map <int, int>& connected, vvi& check, int row, int column, int x, int y)
{
    int nx, ny, count, temp;
    set <int> plus;

    count = 1;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i]; ny = y + dy[i];
        if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
            if (check[nx][ny]) {
                plus.insert(check[nx][ny]);
            }
        }
    }

    for (auto i : plus) {
        count += connected[i];
    }

    return count % 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, column, check_count;
    string temp;
    vvi table, check;
    unordered_map <int, int> connected;

    cin >> row >> column;
    table.assign(row, vi(column, 0));
    check.assign(row, vi(column, 0));

    for (int i = 0; i < row; i++) { // map(table) input
        cin >> temp;
        for (int j = 0; j < column; j++) {
            table[i][j] = (int)temp[j] - 48;
        }
    }

    check_count = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (!table[i][j] && !check[i][j]) { // if not wall and not checked
                connected[check_count] = bfs(table, check, row, column, i, j, check_count);
                check_count++;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (table[i][j]) { // if wall
                cout << find(connected, check, row, column, i, j);
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }

    return 0;
}