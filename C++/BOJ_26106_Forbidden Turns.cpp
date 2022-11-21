#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, n, k, start, end, a, b, w;
    int cur_dist, cur_node, bef_node, next_node, weight;
    pair <int, int> pr;
    array <int, 3> temp;
    set <array <int, 3>> s;
    set <pair <int, int>> check;
    priority_queue <array <int, 3>> pq;
    vector <vector <pair <int, int>>> adj;

    cin >> m >> n >> k >> start >> end;

    adj.assign(n, vector <pair <int, int>> ());

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
    }

    for (int i = 0; i < k; i++) {
        cin >> temp[0] >> temp[1] >> temp[2];
        s.insert(temp);
    }

    pq.push({ -0, start, -1 });
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        cur_dist = -x[0]; cur_node = x[1]; bef_node = x[2];

        if (cur_node == end) {
            cout << cur_dist << '\n';
            return;
        }

        for (auto& u : adj[cur_node]) {
            next_node = u.first;
            weight = u.second;

            if (s.count({ bef_node, cur_node, next_node }) == 1) continue;
            pr.first = cur_node; pr.second = next_node;
            if (check.count(pr) == 1) continue;
            check.insert(pr);
            pq.push({ -cur_dist - weight, next_node, cur_node });
        }
    }

    cout << -1 << '\n';
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