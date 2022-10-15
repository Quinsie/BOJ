#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

void bfs(vvi table, vi pointed, int point)
{
    int pos, npos;
    vi check(point, 0);
    queue <int> que;
    
    for (int i = 0; i < point; i++) {
        if (!pointed[i]) {
            que.push(i);
            check[i] = 1;
        }
    }

    while (!que.empty()) {
        pos = que.front();
        que.pop();
        cout << pos + 1 << " ";

        for (int i = 0; i < table[pos].size(); i++) {
            pointed[table[pos][i]]--;
            if (!pointed[table[pos][i]] && !check[table[pos][i]]) {
                check[table[pos][i]] = 1;
                que.push(table[pos][i]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int point, line, from, to;
    vvi table;
    vi pointed;

    cin >> point >> line;
    table.assign(point, vi ());
    pointed.assign(point, 0);

    for (int i = 0; i < line; i++) {
        cin >> from >> to;
        from--; to--;
        table[from].emplace_back(to);
        pointed[to]++;
    }

    bfs(table, pointed, point);

    return 0;
}