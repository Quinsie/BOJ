#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test, num;
    long long* arr;

    arr = new long long[MAX]{ 0, };
    arr[1] = 1;
    for (int i = 2; i < MAX; i++) {
        for (int j = i + i; j < MAX; j += i) {
            arr[j] += (long long)i;
        }
        arr[i] += (long long)(i + 1);
        arr[i] += arr[i - 1];
    }

    cin >> test;
    while (test--) {
        cin >> num;
        cout << arr[num] << '\n';
    }

    delete[] arr;

    return 0;
}