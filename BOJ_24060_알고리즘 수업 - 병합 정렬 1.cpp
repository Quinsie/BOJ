#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int>& arr, const int& left, const int& mid, const int& right, const int& target, int& ans, int& ans_num)
{
    int i, j, t;
    vector <int> temp;

    i = left; j = mid + 1; t = 0;
    temp.assign(right - left + 1, 0);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[t++] = arr[i++];
        else temp[t++] = arr[j++];
    }
    while (i <= mid) temp[t++] = arr[i++];
    while (j <= right) temp[t++] = arr[j++];

    i = left; t = 0;
    while (i <= right) {
        arr[i] = temp[t];
        ans++;
        if (ans == target) ans_num = arr[i];
        i++; t++;
    }
}

void merge_sort(vector <int>& arr, const int& left, const int& right, const int& target, int& ans, int& ans_num)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid, target, ans, ans_num);
        merge_sort(arr, mid + 1, right, target, ans, ans_num);
        merge(arr, left, mid, right, target, ans, ans_num);
    }
}
void solve()
{
    int n, k, ans, ans_num;
    vector <int> arr;

    cin >> n >> k;
    ans_num = -1;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1, k, ans, ans_num);

    cout << ans_num << '\n';
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