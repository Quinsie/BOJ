#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2147483647;
const int MIN = -2147483647;

void recursive(int pos, int target, vector <int>& num_list, vector <int>& op, vector <int>& ans)
{
    static int max = MIN;
    static int min = MAX;
    int now = 0;
    
    if (pos == target) { // base case
        now = num_list[0];
        for (int i = 0; i < target; i++) {
            if (ans[i] == 0) {
                now += num_list[i + 1];
            } else if (ans[i] == 1) {
                now -= num_list[i + 1];
            } else if (ans[i] == 2) {
                now *= num_list[i + 1];
            } else {
                now /= num_list[i + 1];
            }
        }
        
        if (now > max) max = now;
        if (now < min) min = now;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!ans[pos] && op[i]) { // if op[i] exists and ans[pos] do not exsists
            op[i]--;
            ans[pos] = i;
            recursive(pos + 1, target, num_list, op, ans);
            ans[pos] = 0;
            op[i]++;
        }
    }
    
    if (pos == 0) {
        cout << max << "\n" << min << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    vector <int> num_list; // number list
    vector <int> op(4, 0); // operator
    vector <int> ans;
    
    cin >> num;
    num_list.assign(num, 0);
    ans.assign(num - 1, 0);
    for (int i = 0; i < num; i++) {
        cin >> num_list[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    
    recursive(0, num - 1, num_list, op, ans);
    
    return 0;
}