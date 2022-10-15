#include <iostream>
#define eratos_max 7368788

using namespace std;

int eratos(int num)
{
    int count = 0, target = 0;
    bool* check;
    check = new bool[eratos_max]{ false, };

    check[0] = true; check[1] = true;
    for (int i = 2; i * i < eratos_max; i++) {
        if (check[i] == false) {
            for (int j = i + i; j < eratos_max; j += i) {
                check[j] = true;
            }
        }
    }

    for (int i = 0; i < eratos_max; i++) {
        if (check[i] == false) count++;
        if (count == num) {
            target = i;
            break;
        }
    }
    delete[] check;
    return target;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    cout << eratos(num);

    return 0;
}