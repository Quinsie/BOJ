#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int* arr;

    cin >> num;
    arr = new int[num + 1]{ 0, };
    for (int i = 1; i <= num; i++) {
        arr[i] = i;
        for (int j = 1; j * j <= i; j++) {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }
    cout << arr[num];
    delete[] arr;
    
    return 0;
}