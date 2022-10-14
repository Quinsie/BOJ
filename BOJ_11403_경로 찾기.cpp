#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp;
    vector <vector <bool>> graph;

    cin >> n;
    graph.assign(n, vector <bool> (n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp) graph[i][j] = true;
        }
    }

    for (int mid = 0; mid < n; mid++) {
        for (int start = 0; start < n; start++) {
            for (int end = 0; end < n; end++) {
                if (graph[start][mid] && graph[mid][end]) graph[start][end] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << ' ';
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