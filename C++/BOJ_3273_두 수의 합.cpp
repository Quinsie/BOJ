#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, target, count, temp, left, right, sum;
    vector <int> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }
    cin >> target;
    sort(arr.begin(), arr.end());

    count = 0;
    left = 0; right = n - 1;
    while (left < right) {
        sum = arr[left] + arr[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else { // sum == target
            count++;
            left++;
        }
    }
    cout << count << '\n';
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