#include <iostream>
#include <vector>
#include <cmath>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;

void seg_assign(vector <long long>& seg_arr, const int& n)
{
    int height, tree_size;

    for (int i = 0; i < 64; i++) {
        if (pow(2, i) == n) {
            seg_arr.assign(n * 2, 0);
            return;
        }
    }

    height = (int)ceil(log2(n));
    tree_size = pow(2, height + 1);
    seg_arr.assign(tree_size, 0);
}

long long seg_init(const vector <long long>& arr, vector <long long>& seg_arr,
                   const int& pos, const int& left, const int& right)
{
    int mid;

    if (left == right) return seg_arr[pos] = arr[left];

    mid = (left + right) / 2;
    return seg_arr[pos] = seg_init(arr, seg_arr, pos * 2, left, mid) +
                          seg_init(arr, seg_arr, pos * 2 + 1, mid + 1, right);
}

long long seg_query(const vector <long long>& seg_arr, const int& from, const int& to,
                    const int& pos, const int& left, const int& right)
{
    int mid;

    if (right < from || left > to) return 0;
    if (right <= to && left >= from) return seg_arr[pos];

    mid = (left + right) / 2;
    return seg_query(seg_arr, from, to, pos * 2, left, mid) +
           seg_query(seg_arr, from, to, pos * 2 + 1, mid + 1, right);
}

void seg_update(vector <long long>& seg_arr, const int& index, const long long& value,
                     const int& pos, const int& left, const int& right)
{
    int mid;

    if (index < left || index > right) return;

    seg_arr[pos] += value;
    if (index == left && index == right) return;

    mid = (left + right) / 2;
    seg_update(seg_arr, index, value, pos * 2, left, mid);
    seg_update(seg_arr, index, value, pos * 2 + 1, mid + 1, right);
}

void solve()
{
    int n, m, k, a, b; 
    long long c, gap;
    vector <long long> arr, seg_arr;

    cin >> n >> m >> k;

    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    seg_assign(seg_arr, n);
    seg_init(arr, seg_arr, 1, 1, n);
    
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            gap = c - arr[b];
            arr[b] = c;
            seg_update(seg_arr, b, gap, 1, 1, n);
        } else {
            cout << seg_query(seg_arr, b, c, 1, 1, n) << '\n';
        }
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
