#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int document, target, count, testcase;
    deque <pair<int, int>> que;

    cin >> testcase;
    while (testcase--) {
        document = 0;
        target = 0;
        count = 1;
        cin >> document >> target;

        for (int i = 0; i < document; i++) {
            int priority;
            cin >> priority;
            que.push_back({i, priority});
        }

        while (!que.empty()) {
            auto now = que.front();
            int prior = now.second;

            for (auto doc : que) {
                if (prior < doc.second) {
                    que.push_back(now);
                    que.erase(que.begin());
                    prior = 0;
                    break;
                }
            }
            if (prior != 0) {
                if (now.first == target) {
                    cout << count << "\n";
                    break;
                }
                que.erase(que.begin());
                count++;
            }
        }
        que.clear();
    }
}