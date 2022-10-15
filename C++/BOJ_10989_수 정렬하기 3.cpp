#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num_arr[10001] = { 0, }, num, temp;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        num_arr[temp]++;
    }
    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < num_arr[i]; j++) {
            cout << i << "\n";
        }
    }
    return 0;
}