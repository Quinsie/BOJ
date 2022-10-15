#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int repeat, num, temp_i;
    char temp_c;
    multiset<int> que;
    multiset<int>::iterator iter;

    cin >> repeat;
    while (repeat--) {
        que.clear();
        cin >> num;
        while (num--) {
            cin >> temp_c >> temp_i;
            if (temp_c == 'I') que.emplace(temp_i);
            else {
                if (que.empty()) continue;
                if (temp_i == -1) {
                    iter = que.begin();
                    que.erase(iter);
                }
                else {
                    iter = que.end();
                    iter--;
                    que.erase(iter);
                }
            }
        }

        if (que.empty()) cout << "EMPTY" << "\n";
        else {
            iter = que.end();
            iter--;
            cout << *iter << " ";
            iter = que.begin();
            cout << *iter << "\n";
        }
    }

    return 0;
}