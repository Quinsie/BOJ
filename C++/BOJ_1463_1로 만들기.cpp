#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector <int> arr;
    
    cin >> n;
    arr.assign(n + 1, 0);
    
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }
    
    cout << arr[n] << '\n';

    return 0;
}
