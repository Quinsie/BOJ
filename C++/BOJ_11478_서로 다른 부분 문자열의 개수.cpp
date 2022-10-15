#include <iostream>
#include <unordered_set>

using namespace std;

void solve()
{
    int length;
    string str, temp;
    unordered_set <string> table;

    cin >> str;
    length = str.size();
    for (int i = 1; i <= length; i++) {
        for (int j = 0; j <= length - i; j++) {
            temp = "";
            for (int k = j; k < j + i; k++) {
                temp += str[k];
            }
            table.insert(temp);
        }
    }

    cout << table.size() << '\n';
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}