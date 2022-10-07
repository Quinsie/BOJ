// BOJ_10816 : 숫자 카드 2
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int card, temp, output;
    unordered_map <int, int> table;

    cin >> card;
    for (int i = 0; i < card; i++) {
        cin >> temp;
        table[temp]++;
    }
    cin >> output;
    for (int i = 0; i < output; i++) {
        cin >> temp;
        if (table[temp]) cout << table[temp] << ' ';
        else cout << 0 << ' ';
    }
    
    return 0;
}
