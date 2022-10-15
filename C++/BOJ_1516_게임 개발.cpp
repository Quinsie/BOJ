#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

void bfs(vvi table, vi pointed, vi build_time, int building)
{
    int pos;
    queue <int> que;
    vi time(building, 0);

    for (int i = 0; i < building; i++) {
        time[i] = build_time[i];
        if (!pointed[i]) {
            que.push(i);
        }
    }

    int count = 0;
    while (!que.empty()) {
        pos = que.front();
        que.pop();

        for (int i = 0; i < table[pos].size(); i++) {
            pointed[table[pos][i]]--;
            // not time[table[pos][i]], build_time[table[pos][i]] is correct.
            time[table[pos][i]] = max(time[table[pos][i]], build_time[table[pos][i]] + time[pos]);
            if (!pointed[table[pos][i]]) {
                que.push(table[pos][i]);
            }
        }
    }

    for (auto i : time) {
        cout << i << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int building, from;
    vvi table;
    vi pointed, build_time;

    cin >> building;
    table.assign(building, vi());
    pointed.assign(building, 0);
    build_time.assign(building, 0);

    for (int i = 0; i < building; i++) {
        cin >> build_time[i];
        while (true) {
            cin >> from;
            if (from == -1) break;
            from--;
            pointed[i]++;
            table[from].emplace_back(i);
        }
    }

    bfs(table, pointed, build_time, building);

    return 0;
}