#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector <vector <int>>& tree, vector <bool>& check, int now)
{
    int len;

    check[now] = true;
    len = tree[now].size();

    for (int i = 0; i < len; i++) {
        if (!check[tree[now][i]]) {
            dfs(tree, check, tree[now][i]);
        }
    }
}

void solve()
{
    int n, del, temp, count;
    vector <bool> check;
    vector <int> reverse;
    vector <vector <int>> tree;

    cin >> n;
    tree.assign(n, vector <int> ());
    reverse.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        reverse[i] = temp;
        if (temp == -1) continue;
        else tree[temp].emplace_back(i);
    }
    cin >> del;
    if (n == 1) {cout << 0; return;}

    check.assign(n, false);
    dfs(tree, check, del);
    
    count = 0;
    for (int i = 0; i < n; i++) {
        if (i == reverse[del]) {
            if (!(tree[i].size() - 1) && !check[i]) {
                count++;
                continue;
            }
        }
        if (!tree[i].size() && !check[i]) {
            count++;
        }
    }

    cout << count << '\n';
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