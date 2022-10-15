#include <iostream>

using namespace std;

const unsigned int mod = 1000000009;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int repeat, num;
    unsigned int* arr;

    arr = new unsigned int[1000001];
    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        arr[i] = ((arr[i - 1] % mod) + (arr[i - 2] % mod) + (arr[i - 3] % mod)) % mod;
    }
    
    cin >> repeat;
    while (repeat--) {
        cin >> num;
        cout << arr[num] << '\n';
    }

    delete[] arr;

    return 0;
}