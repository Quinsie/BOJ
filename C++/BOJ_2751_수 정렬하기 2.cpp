#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int* arr;
    cin >> num;
    arr = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + num);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << "\n";
    }
    delete[] arr;
    return 0;
}