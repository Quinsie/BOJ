#include <bits/stdc++.h>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

class pos {
public:
    int x, y, key;

    pos(int a, int b, int c) {
        x = a; y = b; key = c;
    }
    ~pos() {}
};

int power(int n)
{
    return pow(2, n);
}

int bfs(const vector <string>& graph, const int& row, const int& column,
        const int& start_x, const int& start_y)
{
    int x, y, key, nx, ny, nkey, door;
    queue <pos> que;
    vector <vector <vector <int>>> check;

    check.assign(row, vector <vector <int>> (column, vector <int> (64, 0)));

    check[start_x][start_y][0] = 1;
    que.push(pos(start_x, start_y, 0));

    while (!que.empty()) {
        x = que.front().x; y = que.front().y; key = que.front().key;
        que.pop();

        if (graph[x][y] == '1') return check[x][y][key] - 1;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column && !check[nx][ny][key]) {
                if (graph[nx][ny] == '#') continue;
                else if (graph[nx][ny] == '.' || graph[nx][ny] == '1') {
                    check[nx][ny][key] = check[x][y][key] + 1;
                    que.push(pos(nx, ny, key));
                }
                else if (graph[nx][ny] >= 97) {
                    nkey = key | power((int)graph[nx][ny] - 97);
                    check[nx][ny][nkey] = check[x][y][key] + 1;
                    que.push(pos(nx, ny, nkey));
                }
                else if (graph[nx][ny] >= 65) {
                    door = power((int)graph[nx][ny] - 65);
                    if (key & door) {
                        check[nx][ny][key] = check[x][y][key] + 1;
                        que.push(pos(nx, ny, key));
                    }
                }
            }
        }
    }

    return -1;
}

void solve()
{
    int row, column, start_x, start_y;
    string temp;
    vector <string> graph;

    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        cin >> temp;
        for (int j = 0; j < column; j++) {
            if (temp[j] == '0') {
                temp[j] = '.';
                start_x = i; start_y = j;
            }
        }
        graph.emplace_back(temp);
    }

    cout << bfs(graph, row, column, start_x, start_y) << '\n';
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