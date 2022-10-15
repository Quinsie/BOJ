#include <iostream>
#include <vector>

using namespace std;

typedef vector <bool> vb;
typedef vector <pair <int, int>> vpii;
typedef vector <vector <pair <int, int>>> vvpii;

void dfs(const vvpii& tree, vb& check, int now, int now_len, int& len, int& point)
{
    int search;
    bool leaf;

    check[now] = true;
    leaf = true;
    search = tree[now].size();
    
    for (int i = 0; i < search; i++) {
        if (!check[tree[now][i].first]) {
            leaf = false;
            check[tree[now][i].first];
            now_len += tree[now][i].second;
            dfs(tree, check, tree[now][i].first, now_len, len, point);
            now_len -= tree[now][i].second;
        }
    }

    if (leaf) {
        if (now_len > len) {
            len = now_len;
            point = now;
        }
    }
}

void solve()
{
    int n, from, to, length, l, point;
    vb check;
    vvpii tree;

    cin >> n;
    if (n == 1) {cout << 0; return;}
    tree.assign(n, vpii());

    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> length;
        from--; to--;
        tree[from].emplace_back(to, length);
        tree[to].emplace_back(from, length);
    }

    check.assign(n, false);
    l = 0; point = -1;
    dfs(tree, check, 0, 0, l, point);
    check.clear();
    check.assign(n, false);
    l = 0;
    dfs(tree, check, point, 0, l, point);

    cout << l << '\n';
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
