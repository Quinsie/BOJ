#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector<int>> vvi;

int bfs(vvi table, vi build, vi& pointed, int point, int target)
{
    int pos;
    queue <int> que;
    vi time(point, 0);
    
    for (int i = 0; i < point; i++) {
        if (!pointed[i]) { // if not pointed
            que.push(i);
            time[i] = build[i];
        }
    }
    
    while (!que.empty()) {
        pos = que.front();
        que.pop();
        
        if (pos == target) { // if answer
            return time[pos];
        }
        
        for (int i = 0; i < table[pos].size(); i++) {
            time[table[pos][i]] = max(time[table[pos][i]], build[table[pos][i]] + time[pos]);
            pointed[table[pos][i]]--;
            if (!pointed[table[pos][i]]) {
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
    
    int testcase, point, line, target, from, to;
    vi build, pointed;
    vvi table;
    
    cin >> testcase;
    while (testcase--) {
        cin >> point >> line; // point = building, line = order
        build.assign(point, 0);
        pointed.assign(point, 0);
        table.assign(point, vi());
        
        for (int i = 0; i < point; i++) {
            cin >> build[i]; // input build time
        }
        
        for (int i = 0; i < line; i++) {
            cin >> from >> to;
            from--; to--; // minus due to index
            table[from].emplace_back(to);
            pointed[to]++;
        }
        
        cin >> target; // target num
        target--;
        
        cout << bfs(table, build, pointed, point, target) << "\n";
        
        build.clear();
        pointed.clear();
        table.clear();
    }
    
    return 0;
}