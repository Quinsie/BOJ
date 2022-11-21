#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, saved_end, info_num, start, end, now;
    int left, right, order;
    long long ans, temp;
    vector <int> gap;
    vector <long long> gap_sum;
    unordered_map <int, int> info;

    cin >> n >> k;

    info_num = 1;
    cin >> start >> end;
    saved_end = end;
    info[1] = info_num;

    for (int i = 2; i <= n; i++) {
        cin >> start >> end;
        if (start > saved_end) {
            gap.push_back(start - saved_end);
            saved_end = end;
            info_num++;
        } else {
            saved_end = max(saved_end, end);
        }
        info[i] = info_num;
    }

    temp = 0;
    for (auto i : gap) {
        temp += i;
        gap_sum.push_back(temp);
    }

    now = 1; ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> order;
        
        left = min(info[now], info[order]);
        right = max(info[now], info[order]);

        now = order;

        if (left == right) {
            continue;
        } else {
            if (left == 1) ans += gap_sum[right - 2];
            else ans += gap_sum[right - 2] - gap_sum[left - 2];
        }
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