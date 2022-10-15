#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAX = 10e14;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    long long left_save, start_save, right_save, left, start, right, now, temp;
    vector <long long> solution;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        solution.emplace_back(temp);
    }

    sort(solution.begin(), solution.end());

    now = MAX;
    for (int i = 0; i < num - 2; i++) {
        start = solution[i];
        left = i + 1; right = num - 1;
        while (left < right) {
            temp = start + solution[left] + solution[right];
            if (now > abs(temp)) {
                now = abs(temp);
                left_save = solution[left];
                right_save = solution[right];
                start_save = start;
            }
            if (temp < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << start_save << ' ' << left_save << ' ' << right_save << '\n';

    return 0;
}