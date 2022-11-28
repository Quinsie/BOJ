#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int iMAX = 2147483647;
const int iMIN = -2147483648;
const long long llMAX = 9223372036854775807;
const long long llMIN = -9223372036854775807;
const int imINF = -1000000000;

class node {
public:
    int asum, lsum, rsum, msum;
    node() { asum = 0; lsum = imINF; rsum = imINF; msum = imINF; }
    node(int a, int b, int c, int d) {
        asum = a; lsum = b; rsum = c; msum = d;
    }
};

int max_int3(const int& a, const int& b, const int& c) { return max(max(a, b), c); }

void seg_assign(vector <node>& seg_arr, const int& n)
{
    int height;

    for (int i = 1; i < 64; i++) {
        if (pow(2, i) == n) {
            seg_arr.assign(n * 2, node());
            return;
        }
    }

    height = ceil(log2(n));
    seg_arr.assign(pow(2, height + 1), node());
    return;
}

node seg_init(const vector <int>& arr, vector <node>& seg_arr, const int& pos,
              const int& left, const int& right)
{
    int mid, asum, lsum, rsum, msum;
    node ln, rn;

    if (left == right) {
        return seg_arr[pos] = node(arr[left], arr[left], arr[left], arr[left]);
    }

    mid = (left + right) / 2;

    ln = seg_init(arr, seg_arr, pos * 2, left, mid);
    rn = seg_init(arr, seg_arr, pos * 2 + 1, mid + 1, right);

    asum = ln.asum + rn.asum;
    lsum = max(ln.lsum, ln.asum + rn.lsum);
    rsum = max(rn.rsum, rn.asum + ln.rsum);
    msum = max(max(ln.msum, rn.msum), ln.rsum + rn.lsum);
    
    return seg_arr[pos] = node(asum, lsum, rsum, msum);
}

node seg_query(const vector <node>& seg_arr, const int& from, const int& to,
               const int& pos, const int& left, const int& right)
{
    int mid, asum, lsum, rsum, msum;
    node ln, rn;

    if (right < from || left > to) return node(0, imINF, imINF, imINF);
    if (left >= from && right <= to) return seg_arr[pos];

    mid = (left + right) / 2;
    ln = seg_query(seg_arr, from, to, pos * 2, left, mid);
    rn = seg_query(seg_arr, from, to, pos * 2 + 1, mid + 1, right);

    asum = ln.asum + rn.asum;
    lsum = max(ln.lsum, ln.asum + rn.lsum);
    rsum = max(rn.rsum, rn.asum + ln.rsum);
    msum = max(max(ln.msum, rn.msum), ln.rsum + rn.lsum);

    return node(asum, lsum, rsum, msum);
}

void solve()
{
    int n, m, from, to;
    node ans;
    vector <int> arr;
    vector <node> seg_arr;

    cin >> n;
    arr.assign(n + 1, 0);
    seg_assign(seg_arr, n);
    
    for (int i = 1; i <= n; i++) cin >> arr[i];
    seg_init(arr, seg_arr, 1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        ans = seg_query(seg_arr, from, to, 1, 1, n);
        cout << max_int3(ans.lsum, ans.rsum, ans.msum) << '\n';
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