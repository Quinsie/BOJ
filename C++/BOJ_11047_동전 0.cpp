#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int coin, money, need(0);
    int* coin_arr;

    cin >> coin >> money;
    coin_arr = new int[coin];
    for (int i = 0; i < coin; i++) {
        cin >> coin_arr[i];
    }

    for (int i = coin - 1; i >= 0; i--) {
        while (money >= coin_arr[i]) {
            money -= coin_arr[i];
            need++;
        }
    }

    cout << need << "\n";
    delete[] coin_arr;

    return 0;
}