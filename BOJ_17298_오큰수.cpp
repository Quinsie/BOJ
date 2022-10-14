#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, num;
    vector <int> arr, ans;
    stack <int> s;

    cin >> n;
    arr.assign(n, 0);
    
    for (int i = 0; i < n; i++) cin >> arr[i];

    ans.push_back(-1);
    s.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        num = s.top(); s.pop();

        while (true) {
            if (num > arr[i]) {
                ans.push_back(num);
                s.push(num);
                break;
            } else {
                if (s.empty()) {
                    ans.push_back(-1);
                    break;
                } else {
                    num = s.top(); s.pop();
                }
            }
        }

        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    
    for (auto i : ans) cout << i << ' ';
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