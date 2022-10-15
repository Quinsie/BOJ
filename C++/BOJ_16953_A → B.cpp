#include <iostream>
#include <utility>
#include <queue>

using namespace std;

long long bfs(int start, int end)
{
    long long now, count;
    queue <pair <int, int>> que;
    que.push({start, 1});

    while (!que.empty()) {
        now = que.front().first;
        count = que.front().second;
        que.pop();

        if (now == end) return count;       
        if (now * 2 <= end) que.push({now * 2, count + 1});
        if (now * 10 + 1 <= end) que.push({now * 10 + 1, count + 1});
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, end;

    cin >> start >> end;
    cout << bfs(start, end) << "\n";
    
    return 0;
}
