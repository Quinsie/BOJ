#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp;
    priority_queue <int, vector<int>, greater<int>> que;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        if (temp != 0) {
            que.push(temp);
        }
        else {
            if (que.empty()) {
                cout << 0 << "\n";
                continue;
            }
            else {
                cout << que.top() << "\n";
                que.pop();
            }
        }
    }

    return 0;
}