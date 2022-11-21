#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;

int binary_search(const vector <int>& arr, const int& val)
{
    int size, left, right, mid;

    size = arr.size();
    left = 0; right = size - 1;

    if (arr[right] <= val) return 0;

    while (left < right) {
        mid = (left + right) / 2;

        if (arr[mid] > val) right = mid;
        else left = mid + 1;
    }

    if (arr[right] == val) return size - right - 1;
    else return size - right;
}

void seg_assign(vector <vector <int>>& seg_arr, const int& n)
{
    int height, tree_size;

    for (int i = 0; i < 18; i++) {
        if (pow(2, i) == n) {
            seg_arr.assign(n * 2, vector <int> ());
            return;
        } else if (pow(2, i) > n) break;
    }

    height = (int)ceil(log2(n));
    tree_size = pow(2, height + 1);
    seg_arr.assign(tree_size, vector <int> ());
}

vector <int> seg_init(const vector <int>& arr, vector <vector <int>>& seg_arr,
                      const int& pos, const int& left, const int& right)
{
    int mid;
    vector <int> add_1, add_2;

    if (left == right) {
        seg_arr[pos].emplace_back(arr[left]);
        return seg_arr[pos];
    }

    mid = (left + right) / 2;
    add_1 = seg_init(arr, seg_arr, pos * 2, left, mid);
    add_2 = seg_init(arr, seg_arr, pos * 2 + 1, mid + 1, right);

    add_1.insert(add_1.end(), add_2.begin(), add_2.end());
    sort(add_1.begin(), add_1.end());

    seg_arr[pos] = add_1;
    return add_1;
}

int seg_query(const vector <vector <int>>& seg_arr, const int& from, const int& to,
              const int& pos, const int& left, const int& right, const int& val)
{
    int mid;

    if (right < from || left > to) return 0;
    if (right <= to && left >= from) return binary_search(seg_arr[pos], val);

    mid = (left + right) / 2;
    return seg_query(seg_arr, from, to, pos * 2, left, mid, val) +
           seg_query(seg_arr, from, to, pos * 2 + 1, mid + 1, right, val);
}

void solve()
{
    int n, m, from, to, val, last_ans, ans;
    vector <int> arr;
    vector <vector <int>> seg_arr;

    cin >> n;
    arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    seg_assign(seg_arr, n);
    seg_init(arr, seg_arr, 1, 1, n);

    last_ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> val;
        from = from ^ last_ans; to = to ^ last_ans; val = val ^ last_ans;
        
        ans = seg_query(seg_arr, from, to, 1, 1, n, val);
        cout << ans << '\n';
        last_ans = ans;
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