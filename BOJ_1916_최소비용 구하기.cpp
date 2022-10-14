#include <iostream>
#include <vector>

using namespace std;

const int INF = 10e8;

void solve()
{
    int n, m, s, e, d;
    int start, end, min_idx, min_dist;
    bool flag;
    vector <bool> check;
    vector <vector <int>> dist;

    cin >> n >> m;
    check.assign(n, false);
    dist.assign(n, vector <int> (n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> d;
        s--; e--;
        if (dist[s][e] > d) {
            dist[s][e] = d;
        }
    }

    cin >> start >> end;
    start--; end--;
    check[start] = true;

    while (true) {
        flag = false;
        min_dist = INF;
        for (int i = 0; i < n; i++) {
            if (!flag && !check[i]) {
                min_idx = i;
                min_dist = dist[start][i];
                flag = true;
                continue;
            }

            if (!check[i] && dist[start][i] < min_dist) {
                min_idx = i;
                min_dist = dist[start][i];
            }
        }
        if (!flag) break;
        check[min_idx] = true;

        for (int i = 0; i < n; i++) {
            if (i == start) continue;
            dist[start][i] = min(dist[start][i], dist[start][min_idx] + dist[min_idx][i]);
        }
    }

    cout << dist[start][end] << '\n';
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