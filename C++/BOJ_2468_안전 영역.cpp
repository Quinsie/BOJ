#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

void bfs(vector <vector <bool>>& check, int size, int start_x, int start_y)
{
    int x, y, nx, ny;
    queue <pair <int, int>> que;

    check[start_x][start_y] = true;
    que.push({ start_x, start_y });
    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                if (!check[nx][ny]) {
                    check[nx][ny] = true;
                    que.push({ nx, ny });
                }
            }
        }
    }
}

int find(vector <vector <bool>> check, int size) // check call by value
{
    int area;

    area = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!check[i][j]) {
                area++;
                bfs(check, size, i, j);
            }
        }
    }

    return area;
}

void solve()
{
    int n, temp, ans;
    vector <vector <int>> graph;
    vector <vector <bool>> check;

    cin >> n;
    graph.assign(n, vector <int> (n, 0));
    check.assign(n, vector <bool> (n, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    ans = 0;
    for (int level = 0; level < 101; level++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == level) {
                    check[i][j] = true;
                }
            }
        }

        ans = max(ans, find(check, n));
    }

    cout << ans << '\n';
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