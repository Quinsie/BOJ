#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(const vector <vector <int>>& graph, const int& n, const int& start, const int& end)
{
    int pos, npos, len;
    queue <int> que;
    vector <int> check;

    check.assign(n + 1, 0);
    que.push(start);
    check[start] = 1;

    while (!que.empty()) {
        pos = que.front(); que.pop();

        if (pos == end) return check[pos] - 1;

        len = graph[pos].size();
        for (int i = 0; i < len; i++) {
            npos = graph[pos][i];
            if (!check[npos]) {
                que.push(npos);
                check[npos] = check[pos] + 1;
            }
        }
    }

    return -1;
}

void solve()
{
    int n, a, b, rel, x, y;
    vector <vector <int>> graph;

    cin >> n >> a >> b >> rel;
    
    graph.assign(n + 1, vector <int> ());

    for (int i = 0; i < rel; i++) {
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    cout << bfs(graph, n, a, b) << '\n';
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