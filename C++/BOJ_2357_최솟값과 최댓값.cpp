#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;

const int MAX = 2147483647;
const int MIN = -2147483647;

void seg_assign(vector <pair <int, int>>& seg_arr, const int& n)
{
    int height, tree_size;

    for (int i = 0; i < 32; i++) {
        if (n == pow(2, i)) {
            seg_arr.assign(n * 2, pair <int, int> ());
            return;
        }
    }

    height = (int)ceil(log2(n));
    tree_size = pow(2, height + 1);
    seg_arr.assign(tree_size, pair <int, int> ());
}

pair <int, int> seg_init(const vector <int>& arr, vector <pair <int, int>>& seg_arr,
                         const int& pos, const int& left, const int& right)
{
    int mid;
    pair <int, int> temp1, temp2;

    if (left == right) {
        seg_arr[pos].first = arr[left];
        seg_arr[pos].second = arr[left];
        return seg_arr[pos];
    }

    mid = (left + right) / 2;
    temp1 = seg_init(arr, seg_arr, pos * 2, left, mid);
    temp2 = seg_init(arr, seg_arr, pos * 2 + 1, mid + 1, right);

    seg_arr[pos].first = min(temp1.first, temp2.first);
    seg_arr[pos].second = max(temp1.second, temp2.second);
    return seg_arr[pos];
}

void min_seg_query(const vector <pair <int, int>>& seg_arr, const int& from, const int& to,
                  const int& pos, const int& left, const int& right, int& number)
{
    int mid;

    if (right < from || left > to) return;
    if (right <= to && left >= from) {
        number = min(number, seg_arr[pos].first);
        return;
    }

    mid = (left + right) / 2;
    min_seg_query(seg_arr, from, to, pos * 2, left, mid, number);
    min_seg_query(seg_arr, from, to, pos * 2 + 1, mid + 1, right, number);
}

void max_seg_query(const vector <pair <int, int>>& seg_arr, const int& from, const int& to,
                  const int& pos, const int& left, const int& right, int& number)
{
    int mid;

    if (right < from || left > to) return;
    if (right <= to && left >= from) {
        number = max(number, seg_arr[pos].second);
        return;
    }

    mid = (left + right) / 2;
    max_seg_query(seg_arr, from, to, pos * 2, left, mid, number);
    max_seg_query(seg_arr, from, to, pos * 2 + 1, mid + 1, right, number);
}

void solve()
{
    int n, m, minimum, maximum, from, to;
    vector <int> arr;
    vector <pair <int, int>> seg_arr;

    cin >> n >> m;
    arr.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) cin >> arr[i];

    seg_assign(seg_arr, n);
    seg_init(arr, seg_arr, 1, 1, n);

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        minimum = MAX; maximum = MIN;
        min_seg_query(seg_arr, from, to, 1, 1, n, minimum);
        max_seg_query(seg_arr, from, to, 1, 1, n, maximum);
        cout << minimum << ' ' << maximum << '\n';
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