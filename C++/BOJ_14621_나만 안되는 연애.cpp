#include <bits/stdc++.h>

using namespace std;

class edge {
public:
    int from, to, length;

    edge() {
        from = 0;
        to = 0;
        length = 0;
    }
    edge(int a, int b, int c) {
        from = a;
        to = b;
        length = c;
    }
    ~edge() {}

    bool operator< (const edge& other) {
        if (this->length < other.length) return true;
        else return false;
    }
};

int find(vector <int>& parent, int n)
{
    if (parent[n] == n) return n;
    return parent[n] = find(parent, parent[n]);
}

void union_p(vector <int>& parent, int a, int b)
{
    a = find(parent, a); b = find(parent, b);

    if (a < b) parent[a] = b;
    else parent[b] = a;
}

bool compare(edge a, edge b) { return a < b; }

void solve()
{
    int n, m, u, v, d, ans, count, len;
    vector <int> parent;
    vector <char> school;
    vector <edge> edges;

    cin >> n >> m;
    parent.assign(n, 0);
    school.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> school[i];
        cin.ignore();
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        u--; v--;
        if (school[u] == school[v]) continue;
        edges.emplace_back(edge(u, v, d));
    }

    sort(edges.begin(), edges.end(), compare);
    ans = 0; count = 1;
    len = edges.size();

    for (int i = 0; i < len; i++) {
        u = edges[i].from; v = edges[i].to; d = edges[i].length;
        if (find(parent, u) != find(parent, v)) {
            union_p(parent, u, v);
            ans += d;
            if (count++ == n - 1) {
                cout << ans << '\n';
                return;
            }
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