#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, cnt;
    vector <int> num_list, sorted_num_list;
    unordered_map <int, int> compress;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        num_list.emplace_back(temp);
        sorted_num_list.emplace_back(temp);
    }
    sort(sorted_num_list.begin(), sorted_num_list.end());

    cnt = 1;
    for (auto i : sorted_num_list) {
        if (!compress[i]) {
            compress[i] = cnt;
            cnt++;
        }
    }
    for (auto i : num_list) {
        cout << compress[i] - 1 << " ";
    }

    return 0;
}