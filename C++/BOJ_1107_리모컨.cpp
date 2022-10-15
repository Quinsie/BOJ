#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 2147483647;

void recursive(int pos, vector <int> broken, string now, int target)
{
    int temp;
    static int ans = MAX, debug = 0;
    bool flag;

    temp = abs(stoi(now) - target);
    if (temp + pos < ans) {
        ans = temp + pos;
    }
    if (pos == 6) return;
    if (pos == 1 && now == "0") return; // cannot type numbers like this -> (01230)
    if (pos == 0) now = ""; // now initialize (first input is 100)
    for (int i = 0; i < 10; i++) {
        flag = false;
        for (int j = 0; j < broken.size(); j++) {
            if (i == broken[j]) {
                flag = true;
                break;
            }
        }
        if (flag) continue; // if num in broke vector
        now += to_string(i);
        recursive(pos + 1, broken, now, target);
        now.pop_back();
    }

    if (pos == 0) cout << ans << "\n"; // print answer
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, ans, channel;
    vector <int> broken;

    cin >> channel;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        broken.emplace_back(temp);
    }

    recursive(0, broken, "100", channel);

    return 0;
}