#include <iostream>
#include <vector>

using namespace std;

void pre_order_traversal(const vector <pair <int, int>>& tree, int node) // 전위 순회
{
    if (node != -1) {
        cout << (char)(node + 65);
        pre_order_traversal(tree, tree[node].first);
        pre_order_traversal(tree, tree[node].second);
    }
}

void in_order_traversal(const vector <pair <int, int>>& tree, int node) // 중위 순회
{
    if (node != -1) {
        in_order_traversal(tree, tree[node].first);
        cout << (char)(node + 65);
        in_order_traversal(tree, tree[node].second);
    }
}

void post_order_traversal(const vector <pair <int, int>>& tree, int node) // 후위 순회
{
    if (node != -1) {
        post_order_traversal(tree, tree[node].first);
        post_order_traversal(tree, tree[node].second);
        cout << (char)(node + 65);
    }
}

void solve()
{
    int n, tempint, idx;
    char temp;
    vector <pair <int, int>> tree;

    cin >> n;
    tree.assign(n, pair <int, int> ());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            cin.ignore();
            
            if (j == 0) {
                idx = (int)temp - 65;
                continue;
            }
            if (temp == 46) tempint = -1;
            else tempint = (int)temp - 65;

            if (j == 1) tree[idx].first = tempint;
            else tree[idx].second = tempint;
        }
    }

    pre_order_traversal(tree, 0); cout << '\n';
    in_order_traversal(tree, 0); cout << '\n';
    post_order_traversal(tree, 0); cout << '\n';
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
