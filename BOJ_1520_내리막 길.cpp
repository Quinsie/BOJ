#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y, const vvi& graph, vvi& check, const int& row, const int& column)
{
    int nx, ny;
    if (x == row - 1 && y == column - 1) return 1;
    if (check[x][y] != -1) return check[x][y];

    check[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i]; ny = y + dy[i];
        if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
            if (graph[nx][ny] < graph[x][y]) {
                check[x][y] += dfs(nx, ny, graph, check, row, column);
            }
        }
    }
    
    return check[x][y];
}

void solve()
{
    int row, column;
    vvi graph, check;

    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        graph.emplace_back(vi (column, 0));
        check.emplace_back(vi (column, -1));
        for (int j = 0; j < column; j++) {
            cin >> graph[i][j];
        }
    }

    cout << dfs(0, 0, graph, check, row, column) << '\n';
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