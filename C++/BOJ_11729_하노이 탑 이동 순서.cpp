#include <iostream>

using namespace std;

void recursive(int block, int start, int end, int mid)
{
    if (block == 1) {
        cout << start << ' ' << end << "\n";
        return;
    }
    recursive(block - 1, start, mid, end);
    cout << start << ' ' << end << "\n";
    recursive(block - 1, mid, end, start);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int block;
    cin >> block;
    cout << (1 << block) - 1 << "\n";
    recursive(block, 1, 3, 2);
    
    return 0;
}
