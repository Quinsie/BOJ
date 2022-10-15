#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, count, target;
    int* arr;

    cin >> num;
    arr = new int[num]{ 0, };
    for (int i = 0; i < num; i++) {
        cin >> temp;
        count = 0;
        for (int j = 0; j < num; j++) {
            if (count == temp) {
                if (!arr[j]) {
                    target = j;
                    break;
                }
            }
            if (!arr[j]) count++;
        }
        arr[target] = i + 1;
    }

    for (int i = 0; i < num; i++) {
        cout << arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}