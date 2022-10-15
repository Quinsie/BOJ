#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector <vector <int>>& table, vector <bool>& check,
         int now)
{
    int length;
    
    check[now] = true;
    cout << now << ' ';
    
    length = table[now].size();
    for (int i = 0; i < length; i++) {
        if (!check[table[now][i]]) {
            dfs(table, check, table[now][i]);
        }
    }
}

void bfs(vector <vector <int>>& table, int start, int point)
{
    int now, length; // 현재 검사중인 점
    queue <int> que; // 큐
    vector <bool> check(point + 1, false);
    
    que.push(start);
    check[start] = true;
    
    while (!que.empty()) { // 큐에 어떤 요소가 하나라도 있는 동안
        now = que.front();
        que.pop();
        
        cout << now << ' ';
        length = table[now].size();
        for (int i = 0; i < length; i++) {
            if (!check[table[now][i]]) {
                que.push(table[now][i]);
                check[table[now][i]] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int point, line, start, from, to;
    vector <vector <int>> table;
    vector <bool> check;
    
    cin >> point >> line >> start;
    table.assign(point + 1, vector <int> ());
    check.assign(point + 1, false);
    
    for (int i = 0; i < line; i++) {
        cin >> from >> to;
        table[from].emplace_back(to);
        table[to].emplace_back(from);
    }
    
    for (int i = 1; i <= point; i++) {
        sort(table[i].begin(), table[i].end());
    }
    
    dfs(table, check, start);
    cout << '\n';
    bfs(table, start, point);
    cout << '\n';
    
    return 0;
}
