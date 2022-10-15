#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class bulb {
    public:
        int left, right, name;
};

bool compare(bulb a, bulb b)
{
    return a.right < b.right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, left, right, mid, now;
    int* LIS_len;
    bulb* bulb_arr;
    unordered_map <int, int> arr1, arr2;
    vector <int> memo, ans;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        arr1.insert({temp, i + 1});
    }
    for (int i = 0; i < num; i++) {
        cin >> temp;
        arr2.insert({temp, i + 1});
    }

    bulb_arr = new bulb[num];
    for (int i = 0; i < num; i++) {
        bulb_arr[i].name = i + 1;
        bulb_arr[i].left = arr1[i + 1];
        bulb_arr[i].right = arr2[i + 1];
    }

    sort(bulb_arr, bulb_arr + num, compare);
    
    LIS_len = new int[num]{ 1, };
    memo.emplace_back(-1);

    for (int i = 0; i < num; i++) {
        if (bulb_arr[i].left > memo.back()) {
            memo.emplace_back(bulb_arr[i].left);
            LIS_len[i] = memo.size() - 1;
        }
        else {
            left = 0;
            right = memo.size();

            while (left < right) {
                mid = (left + right) / 2;
                if (memo[mid] < bulb_arr[i].left) left = mid + 1;
                else right = mid;
            }

            memo[right] = bulb_arr[i].left;
            LIS_len[i] = right;
        }
    }

    now = memo.size() - 1;
    for (int i = num - 1; i >= 0; i--) {
        if (LIS_len[i] == now) {
            ans.emplace_back(bulb_arr[i].name);
            now--;
            if (now == 0) break;
        }
    }
    
    sort(ans.begin(), ans.end());

    cout << memo.size() - 1 << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

    delete[] bulb_arr;
    delete[] LIS_len;

    return 0;
}