#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector <vector <int>> vvi;

void dfs(int now, vvi table, vector <bool> &check)
{
    cout << now + 1 << " ";

    check[now] = true;
    for (int i = 0; i < table[now].size(); i++) {
        if (!check[table[now][i]]) {
            dfs(table[now][i], table, check);
        }
    }
}

void bfs(int start, vvi table, vector <bool> &check)
{
    int now;
    queue <int> que;

    que.push(start);
    check[start] = true;

    while (!que.empty()) {
        now = que.front();
        que.pop();
        cout << now + 1 << " ";

        for (int i = 0; i < table[now].size(); i++) {
            if (!check[table[now][i]]) {
                check[table[now][i]] = true;
                que.push(table[now][i]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int point, line, start;
    int from, to;
    vector <vector <int>> table;
    vector <bool> check;

    cin >> point >> line >> start;
    start--;
    table.assign(point, vector<int>());
    check.assign(point, false);
    
    for (int i = 0; i < line; i++) {
        cin >> from >> to;
        from--; to--;
        table[from].emplace_back(to);
        table[to].emplace_back(from);
    }

    for (int i = 0; i < point; i++) {
        sort(table[i].begin(), table[i].end());
    }

    dfs(start, table, check);
    cout << "\n";

    check.assign(point, false);
    bfs(start, table, check);
    cout << "\n";
    
    return 0;
}