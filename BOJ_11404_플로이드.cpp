#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, from, to, dis;
    vector <vector <int>> dist;

    cin >> n >> m;
    dist.assign(n, vector <int> (n, 10e8));

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dis;
        from--; to--;
        dist[from][to] = min(dist[from][to], dis);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 10e8) {
                cout << 0 << ' ';
                continue;
            }
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
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