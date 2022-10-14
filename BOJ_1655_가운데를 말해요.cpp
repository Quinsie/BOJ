#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp, temp2, max_size, min_size;
    priority_queue <int> max_que;
    priority_queue <int, vector <int>, greater <int>> min_que;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        max_size = max_que.size(); min_size = min_que.size();
        if (max_size == min_size) { max_que.push(temp); max_size++; }
        else { min_que.push(temp); min_size++; }

        if (max_size && min_size) {
            if (min_que.top() < max_que.top()) {
                temp = max_que.top();
                max_que.pop();
                max_que.push(min_que.top());
                min_que.pop();
                min_que.push(temp);
            }
        }
        
        cout << max_que.top() << '\n';
    }
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