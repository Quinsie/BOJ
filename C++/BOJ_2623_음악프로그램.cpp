#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vector <int>> vvi;

void bfs(vvi& table, vi& pointed, vi& ans, int singer)
{
    int pos, npos;
    queue <int> que;

    for (int i = 0; i < singer; i++) {
        if (!pointed[i]) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        pos = que.front();
        que.pop();

        ans.emplace_back(pos + 1);
        for (int i = 0; i < table[pos].size(); i++) {
            npos = table[pos][i];
            pointed[npos]--;
            if (!pointed[npos]) {
                que.push(npos);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int singer, order, length, num, prev_num;
    bool flag;
    vi pointed, ans;
    vvi table;

    cin >> singer >> order;
    table.assign(singer, vi());
    pointed.assign(singer, 0);

    for (int i = 0; i < order; i++) {
        cin >> length >> prev_num;
        for (int j = 1; j < length; j++) {
            cin >> num;
            pointed[num - 1]++;
            table[prev_num - 1].emplace_back(num - 1);
            prev_num = num;
        }
    }

    bfs(table, pointed, ans, singer);

    if (ans.size() != singer) {
        cout << 0 << "\n";
        return 0;
    } else {
        for (auto i : ans) {
            cout << i << "\n";
        }
    }

    return 0;
}