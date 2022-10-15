#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2147483647;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, down_save, up_save;
    int left, right, now, temp;
    vector <int> solution;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        solution.emplace_back(temp);
    }

    left = 0; right = num - 1;
    now = MAX;
    while (left < right) {
        temp = solution[left] + solution[right];
        if (abs(temp) < abs(now)) {
            now = abs(temp);
            down_save = left;
            up_save = right;
        }
        if (temp < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << solution[down_save] << " " << solution[up_save] << "\n";

    return 0;
}