#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int repeat, num, count;
    string name, type;
    unordered_map <string, int> table;

    cin >> repeat;
    while(repeat--) {
        table.clear();

        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> name >> type;
            table[type]++;
        }

        count = 1;
        for (pair <string, int> elem : table) {
            count *= elem.second + 1;
        }
        count--;

        cout << count << '\n';
    }

    return 0;
}