#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector <int>& table, int n, int k)
{
    int pos, npos;
    queue <int> que;
    que.push(n);

    while (!que.empty()) {
        pos = que.front();
        que.pop();

        if (pos == k) {
            cout << table[pos] - 1 << "\n";
            return;
        }

        npos = pos - 1;
        if (npos >= 0 && npos <= 100000 && !table[npos]) {
            table[npos] = table[pos] + 1;
            que.push(npos);
        }
        npos = pos + 1;
        if (npos >= 0 && npos <= 100000 && !table[npos]) {
            table[npos] = table[pos] + 1;
            que.push(npos);
        }
        npos = pos * 2;
        if (npos >= 0 && npos <= 100000 && !table[npos]) {
            table[npos] = table[pos] + 1;
            que.push(npos);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;
    vector <int> table(100001);
    table[n] = 1;

    bfs(table, n, k);

    return 0;
}