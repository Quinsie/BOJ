#include <bits/stdc++.h>

using namespace std;

class person {
public:
    int number, score_a, score_b;
    person() {
        number = 0;
        score_a = 0;
        score_b = 0;
    }
    ~person() {}
};

bool compare(person a, person b)
{
    if (a.score_a == b.score_a && a.score_b == b.score_b) return a.number < b.number;
    else if (a.score_a == b.score_a) return a.score_b < b.score_b;
    else return a.score_a < b.score_a;
}

void solve()
{
    int n, num, a, b, c, score_a, score_b;
    vector <person> arr;

    cin >> n;
    arr.assign(n, person());
    
    for (int i = 0; i < n; i++) {
        cin >> num >> a >> b >> c;
        score_a = a * b * c;
        score_b = a + b + c;
        arr[i].number = num;
        arr[i].score_a = score_a;
        arr[i].score_b = score_b;
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < 3; i++) cout << arr[i].number << ' ';
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}