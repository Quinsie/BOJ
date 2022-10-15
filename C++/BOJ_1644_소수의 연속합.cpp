#include <iostream>
#include <vector>

using namespace std;

void make_eratos(vector <int> &eratos, int num)
{
    vector <bool> check(num + 1, false);
    check[0] = true; check[1] = true;

    for (int i = 2; i * i <= num; i++) {
        if (!check[i]) {
            for (int j = i + i; j <= num; j += i) {
                check[j] = true;
            }
        }
    }

    for (int i = 2; i <= num; i++) {
        if (!check[i]) eratos.emplace_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, result(0), sum(0), lo(0), hi(0);
    vector <int> eratos;

    cin >> num;
    make_eratos(eratos, num);
    
    while (true) {
        if (sum >= num) {
            sum -= eratos[lo++];
        } else if (hi == eratos.size()) {
            break;
        } else {
            sum += eratos[hi++];
        }
        if (sum == num) result++;
    }

    cout << result << "\n";
    
    return 0;
}