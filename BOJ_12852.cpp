#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pos;
    int* count;
    int* route;

    cin >> n;
    count = new int[n + 1];
    route = new int[n + 1];

    count[0] = 0; count[1] = 0;
    route[0] = 0; route[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        count[i] = count[i - 1] + 1;
        route[i] = i - 1;

        if (i % 2 == 0 && count[i / 2] + 1 < count[i]) {
            count[i] = count[i / 2] + 1;
            route[i] = (int)(i / 2);
        }
        if (i % 3 == 0 && count[i / 3] + 1 < count[i]) {
            count[i] = count[i / 3] + 1;
            route[i] = (int)(i / 3);
        }
    }

    cout << count[n] << "\n";
    while(n != 1) {
        cout << n << " ";
        n = route[n];
    }
    cout << 1 << "\n";

    delete[] count;
    delete[] route;

    return 0;
}
