#include <bits/stdc++.h>

using namespace std;

bool find(const int& n, const vector <int>& arr)
{
    for (auto i : arr) if (i == n) return true;
    return false;
}

int bfs(int target)
{
    int pos, npos, time, clip;
    queue <tuple <int, int, int>> que;
    vector <vector <int>> check;

    check.assign(2001, vector <int> ());
    que.push(make_tuple( 1, 0, 0 ));
    check[1].emplace_back(0);

    while (!que.empty()) {
        pos = get<0>(que.front());
        time = get<1>(que.front());
        clip = get<2>(que.front());
        que.pop();

        if (pos == target) return time;

        for (int i = 0; i < 2; i++) {
            if (i == 0) npos = pos - 1;
            else npos = pos + clip;

            if (npos > 0 && npos < 2000 && !find(clip, check[npos])) {
                check[npos].emplace_back(clip);
                que.push(make_tuple( npos, time + 1, clip ));
            }
        }

        if (!find(pos, check[pos])) {
            check[pos].emplace_back(pos);
            que.push(make_tuple( pos, time + 1, pos ));
        }
    }
}

void solve()
{
    int target;

    cin >> target;
    cout << bfs(target) << '\n';
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