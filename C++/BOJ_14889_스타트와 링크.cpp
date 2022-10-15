#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
int num[21][21];
int m = 10000;
bool check[21];

vector<int> target;

void func(int cnt)
{
    if (cnt == N / 2) {
        vector<int> leftteam;
        for (int i = 1; i <= N; i++) {
            if (check[i] == false) {
                leftteam.push_back(i);
            }
        }
        int tgscore = 0;
        for (int a : target) {
            for (int b : target) {
                tgscore += num[a][b];
            }
        }
        int lfscore = 0;
        for (int a : leftteam) {
            for (int b : leftteam) {
                lfscore += num[a][b];
            }
        }
        int diff = abs(lfscore - tgscore);
        if (m >= diff) {
            m = diff;
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (check[i])continue;
        if (!target.empty()&&target.back() > i) continue;
        target.push_back(i);
        check[i] = true;
        func(cnt + 1);
        target.pop_back();
        check[i] = false;

    }
}

int main()
{

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> num[i][j];
        }
    }
    func(0);
    cout << m;
}