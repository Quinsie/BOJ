#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, count;
    int* arr;

    cin >> num;
    arr = new int[num + 1]{ 0, };

    arr[1] = 1;
    for (int i = 2; i < num + 1; i++) {
        arr[i] = arr[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            arr[i] = min(arr[i], arr[i - (j * j)] + 1);
        }
    }

    cout << arr[num] << "\n";

    delete[] arr;

    return 0;
}