#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, now, idx, len, ans;
    vector <int> arr, erase;
    
    cin >> n >> m;
    erase.assign(n, 0);
    for (int i = 0; i < n; i++) {
        arr.emplace_back(i + 1);
    }
    for (int i = 0; i < m; i++) {
        cin >> erase[i];
    }
    
    now = 0;
    ans = 0;
    for (int i = 0; i < m; i++) {
        len = arr.size();
        for (int j = 0; j < len; j++) {
            if (erase[i] == arr[j]) {
                idx = j;
                break;
            }
        }
        
        ans += min(abs(now - idx), len - abs(now - idx));
        now = idx;
        arr.erase(arr.begin() + idx);
    }
    
    cout << ans << '\n';
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