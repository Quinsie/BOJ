#include <iostream>
#include <vector>

using namespace std;

const int INF = (int)10e7;

void solve()
{
    int vertex, edge, start, end, mid, dist, len;
    vector <vector <int>> dist_table;
    vector <vector <vector <int>>> path;

    cin >> vertex >> edge;
    dist_table.assign(vertex, vector <int> (vertex, INF));
    path.assign(vertex, vector <vector <int>> (vertex, vector <int> ()));

    for (int i = 0; i < vertex; i++) {
        dist_table[i][i] = 0;
        for (int j = 0; j < vertex; j++) {
            if (i == j) continue;
            path[i][j].emplace_back(i + 1);
            path[i][j].emplace_back(j + 1);
        }
    }

    for (int i = 0; i < edge; i++) {
        cin >> start >> end >> dist;
        start--; end--;
        if (dist_table[start][end] > dist) {
            dist_table[start][end] = dist;
        }
    }

    for (int mid = 0; mid < vertex; mid++) {
        for (int start = 0; start < vertex; start++) {
            for (int end = 0; end < vertex; end++) {
                if (start == end) continue;
                if (dist_table[start][end] > dist_table[start][mid] + dist_table[mid][end]) {
                    dist_table[start][end] = dist_table[start][mid] + dist_table[mid][end];
                    path[start][end] = path[start][mid];
                    len = path[mid][end].size();
                    for (int i = 1; i < len; i++) {
                        path[start][end].emplace_back(path[mid][end][i]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            if (dist_table[i][j] == INF) {
                cout << 0 << ' ';
            }
            else cout << dist_table[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            if (dist_table[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }
            cout << path[i][j].size() << ' ';
            for (auto i : path[i][j]) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
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