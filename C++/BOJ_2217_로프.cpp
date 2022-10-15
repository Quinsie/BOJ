#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, weight = 0;
    int* arr;

    cin >> num;
    arr = new int[num];
    for (int i = 0; i < num; i++) cin >> arr[i];
    sort(arr, arr + num, greater<int>());
    
    for (int i = 0; i < num; i++) {
        weight = max(weight, arr[i] * (i + 1));
    }

    cout << weight;
    delete[] arr;
    
    return 0;
}