#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2147483647;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int length, target, temp;
    int left, right, saved_len, now_sum;
    vector <int> arr;

    cin >> length >> target;
    for (int i = 0; i < length; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }

    left = 0; right = 0;
    saved_len = MAX; now_sum = arr[0];
    while (left <= right && right < length) {
        if (now_sum >= target) {
            if (right - left + 1 < saved_len) {
                saved_len = right - left + 1;
            }
            now_sum -= arr[left++];
        } else {
            now_sum += arr[++right];
        }
    }

    if (saved_len == MAX) cout << 0 << '\n';
    else cout << saved_len << "\n";

    return 0;
}