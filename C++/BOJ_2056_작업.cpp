#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

int bfs(vvi table, vi pointed, vi work_time, int work)
{
    int pos, ans = 0;
    queue <int> que;
    vi time(work, 0);

    for (int i = 0; i < work; i++) {
        if (!pointed[i]) {
            que.push(i);
            time[i] = work_time[i];
        }
    }

    while (!que.empty()) {
        pos = que.front();
        que.pop();

        for (int i = 0; i < table[pos].size(); i++) {
            time[table[pos][i]] = max(time[table[pos][i]], work_time[table[pos][i]] + time[pos]);
            pointed[table[pos][i]]--;
            if (!pointed[table[pos][i]]) {
                que.push(table[pos][i]);
            }
        }
    }

    for (auto i : time) {
        if (i > ans) ans = i;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int work, from_num, from;
    vvi table;
    vi pointed, work_time;

    cin >> work;
    table.assign(work, vi());
    pointed.assign(work, 0);
    work_time.assign(work, 0);

    for (int i = 0; i < work; i++) {
        cin >> work_time[i] >> from_num;
        for (int j = 0; j < from_num; j++) {
            cin >> from;
            from--; // to avoid index miss
            pointed[i]++;
            table[from].emplace_back(i);
        }
    }

    cout << bfs(table, pointed, work_time, work) << "\n";
    
    return 0;
}