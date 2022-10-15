#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int bfs(const int& size, queue <pair <int, int>>& que,
         const vector <vector <int>>& graph, vector <vector <bool>>& check,
         vector <vector <int>>& pointed, vector <vector <int>>& value)
{
    int x, y, nx, ny, ans;

    ans = 0;
    while (!que.empty()) {
        x = que.front().first; y = que.front().second;
        que.pop();

        ans = max(ans, value[x][y]);

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) { // 범위
                if (graph[nx][ny] > graph[x][y]) { // 증가
                    value[nx][ny] = max(value[nx][ny], value[x][y] + 1);
                    pointed[nx][ny]--;
                    if (!pointed[nx][ny] && !check[nx][ny]) { // 안 가리킬 때
                        check[nx][ny] = true;
                        que.push({ nx, ny });
                    }
                }
            }
        }
    }

    return ans;
}

void solve()
{
    int n, ni, nj;
    queue <pair <int, int>> que;
    vector <vector <int>> graph, pointed, value;
    vector <vector <bool>> check;

    cin >> n;
    graph.assign(n, vector <int> (n, 0));
    pointed.assign(n, vector <int> (n, 0));
    value.assign(n, vector <int> (n, 0));
    check.assign(n, vector <bool> (n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) { // pointed 만들어주기
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                ni = i + dx[k]; nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (graph[ni][nj] < graph[i][j]) pointed[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) { // 0 pointed que에 삽입
        for (int j = 0; j < n; j++) {
            if (!pointed[i][j]) {
                que.push({ i, j });
                check[i][j] = true;
                value[i][j] = 1;
            }
        }
    }

    cout << bfs(n, que, graph, check, pointed, value) << '\n';
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