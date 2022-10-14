#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int bfs(vector <vector <bool>>& graph, const int& row, const int& column,
         const int& start_x, const int& start_y)
{
    int x, y, nx, ny, count;
    queue <pair <int, int>> que;

    count = 0;
    que.push({ start_x, start_y });
    graph[start_x][start_y] = true;

    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();

        count++;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column && !graph[nx][ny]) {
                graph[nx][ny] = true;
                que.push({ nx, ny });
            }
        }
    }

    return count;
}

void solve()
{
    int row, column, rec, s_x, s_y, e_x, e_y;
    vector <int> ans;
    vector <vector <bool>> graph;

    cin >> column >> row >> rec;
    graph.assign(row, vector <bool> (row, false));

    for (int i = 0; i < rec; i++) {
        cin >> s_x >> s_y >> e_x >> e_y;
        for (int j = s_x; j < e_x; j++) {
            for (int k = s_y; k < e_y; k++) {
                graph[j][k] = true;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (!graph[i][j]) {
                ans.emplace_back(bfs(graph, row, column, i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
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